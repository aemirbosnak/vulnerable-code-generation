//FormAI DATASET v1.0 Category: System process viewer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>

void printProcessInfo(int pid, char* state, char* name, char* command) {
    printf("%d  %s  %s\n", pid, state, name);
    printf("%s\n", command);
    printf("------------------------\n");
}

void viewProcesses() {
    DIR* proc = opendir("/proc");
    struct dirent* entry;
    int pid;
    char name[1024], state, command[1024], path[1024], ch;
    FILE* file;

    printf("\nProcess Viewer\n\n");
    printf("PID  STATE  NAME\n");
    printf("------------------------\n");

    while ((entry = readdir(proc)) != NULL) {
        if (isdigit(*entry->d_name)) {
            pid = atoi(entry->d_name);

            sprintf(path, "/proc/%d/stat", pid);
            file = fopen(path, "r");
            fscanf(file, "%d %s %c", &pid, name, &state);
            fclose(file);

            sprintf(path, "/proc/%d/cmdline", pid);
            file = fopen(path, "r");
            ch = getc(file);
            int i = 0;
            while (ch != EOF) {
                if (ch == '\0') {
                    command[i] = ' ';
                }
                else {
                    command[i] = ch;
                }
                ch = getc(file);
                i++;
            }
            command[i] = '\0';
            fclose(file);
            printProcessInfo(pid, &state, name, command);
        }
    }
    closedir(proc);
}

int main() {
    viewProcesses();
    return 0;
}