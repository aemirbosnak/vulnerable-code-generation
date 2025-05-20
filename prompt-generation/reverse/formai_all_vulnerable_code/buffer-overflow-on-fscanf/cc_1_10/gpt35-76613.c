//FormAI DATASET v1.0 Category: System process viewer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

/* A struct to hold process information */
typedef struct {
    int pid;
    char command[256];
} ProcessInfo;

/* A function to extract process information from /proc directory */
void getProcessInfo(ProcessInfo *info, const char *dir) {
    char path[256] = {'\0'}, buffer[256] = {'\0'};
    snprintf(path, sizeof(path), "%s/stat", dir); // stat contains process information
    FILE *file = fopen(path, "r"); 
    if (file) {
        fscanf(file, "%d", &info->pid); // Extract process ID
        fclose(file);
        snprintf(path, sizeof(path), "%s/cmdline", dir); // cmdline contains process command
        file = fopen(path, "r");
        if (file) {
            fgets(buffer, sizeof(buffer), file);
            strncpy(info->command, buffer, sizeof(info->command)); // Extract command
            fclose(file);
        }
    }
}

/* A function to print process information */
void printProcessInfo(ProcessInfo *info) {
    if (strlen(info->command) > 0) {
        printf("PID: %d, Command: %s\n", info->pid, info->command);
    }
}

/* A function to sort process information by command */
int cmpProcessInfo(const void *p1, const void *p2) {
    const ProcessInfo *info1 = (const ProcessInfo *) p1;
    const ProcessInfo *info2 = (const ProcessInfo *) p2;
    return strcoll(info1->command, info2->command);
}

/* Main function */
int main(int argc, char *argv[]) {
    DIR *dir = opendir("/proc");
    if (dir) {
        struct dirent *de;
        ProcessInfo *processes = malloc(256 * sizeof(ProcessInfo)); // Allocate space for process info
        int count = 0;
        while ((de = readdir(dir))) {
            if (isdigit(de->d_name[0])) { // Check if directory name is a process ID
                char path[256] = {'\0'};
                snprintf(path, sizeof(path), "/proc/%s", de->d_name);
                ProcessInfo info;
                getProcessInfo(&info, path);
                if (strlen(info.command) > 0) {
                    processes[count] = info; // Add to process list
                    count++;
                }
            }
        }
        closedir(dir);
        qsort(processes, count, sizeof(ProcessInfo), cmpProcessInfo); // Sort the process list
        for (int i = 0; i < count; i++) {
            printProcessInfo(&processes[i]); // Print the sorted process list
        }
        free(processes);
    }
    return 0;
}