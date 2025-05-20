//FormAI DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define PROC_DIR "/proc"

int main()
{
    DIR *dir;
    struct dirent *entry;
    char path[255];
    FILE *file;
    char line[255];

    dir = opendir(PROC_DIR);

    if (!dir) {
        perror("Unable to open " PROC_DIR);
        exit(1);
    }

    printf("%-10s %-10s %s\n", "PID", "PPID", "Command");

    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0
            && strcmp(entry->d_name, "..") != 0 && atoi(entry->d_name)) {

            sprintf(path, "%s/%s/status", PROC_DIR, entry->d_name);

            file = fopen(path, "r");

            if (!file) {
                perror("Unable to open file");
                continue;
            }

            char *pid = entry->d_name;
            char ppid[255], cmd[255];

            while (fgets(line, sizeof(line), file)) {
                if (strncmp(line, "PPid:", 5) == 0) {
                    strcpy(ppid, line + 6);
                    ppid[strlen(ppid) - 1] = '\0';
                } else if (strncmp(line, "Name:", 5) == 0) {
                    strcpy(cmd, line + 6);
                    cmd[strlen(cmd) - 1] = '\0';
                }
            }

            fclose(file);

            printf("%-10s %-10s %s\n", pid, ppid, cmd);
        }
    }

    closedir(dir);

    return 0;
}