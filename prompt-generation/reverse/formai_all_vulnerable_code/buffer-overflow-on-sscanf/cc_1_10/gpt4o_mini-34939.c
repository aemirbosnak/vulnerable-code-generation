//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define PROC_DIRECTORY "/proc"

void trim_newline(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}

void view_processes() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(PROC_DIRECTORY);
    if (dir == NULL) {
        perror("Failed to open /proc");
        return;
    }

    printf("%-10s %-25s %-10s\n", "PID", "Command", "State");
    printf("----------------------------------------------\n");

    while ((entry = readdir(dir)) != NULL) {
        if (!isdigit(entry->d_name[0])) {
            continue; // Skip non-numeric entries
        }

        char path[MAX_LINE_LENGTH];
        snprintf(path, sizeof(path), "%s/%s/stat", PROC_DIRECTORY, entry->d_name);

        FILE *stat_file = fopen(path, "r");
        if (stat_file != NULL) {
            char line[MAX_LINE_LENGTH];
            if (fgets(line, sizeof(line), stat_file)) {
                int pid;
                char command[MAX_LINE_LENGTH];
                char state;
                sscanf(line, "%d %s %c", &pid, command, &state);

                // Remove parentheses from command if any
                char *open_paren = strchr(command, '(');
                char *close_paren = strchr(command, ')');
                if (open_paren && close_paren && close_paren > open_paren) {
                    size_t command_length = close_paren - open_paren - 1;
                    strncpy(command, open_paren + 1, command_length);
                    command[command_length] = '\0';
                }

                // Trim newline characters
                trim_newline(command);

                printf("%-10d %-25s %-10c\n", pid, command, state);
            }
            fclose(stat_file);
        }
    }
    closedir(dir);
}

int main() {
    printf("Process Viewer\n");
    printf("---------------\n");
    view_processes();
    return 0;
}