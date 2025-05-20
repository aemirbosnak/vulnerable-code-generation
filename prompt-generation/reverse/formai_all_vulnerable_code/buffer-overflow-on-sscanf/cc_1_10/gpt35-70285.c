//FormAI DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

void displayProcesses() {
    DIR* proc = opendir("/proc");
    if (!proc) {
        fprintf(stderr, "Failed to open /proc directory\n");
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(proc)) != NULL) {
        if (!isdigit(entry->d_name[0])) {
            continue;
        }

        char path[256];
        sprintf(path, "/proc/%s/status", entry->d_name);

        FILE* status = fopen(path, "r");
        if (!status) {
            continue;
        }

        char line[512], name[128];
        int pid = -1;
        while (fgets(line, sizeof(line), status)) {
            if (sscanf(line, "Name:\t%s", name) == 1) {
                break;
            }
            if (sscanf(line, "Pid:\t%d", &pid) == 1) {
                break;
            }
        }
        fclose(status);

        if (pid != -1) {
            printf("Process %d: %s\n", pid, name);
        }
    }
    closedir(proc);
}

int main() {
    printf("Scanning for processes...\n");
    displayProcesses();
    printf("Process scan complete.\n");
    return 0;
}