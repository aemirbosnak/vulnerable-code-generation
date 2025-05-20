//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PROCESSES 1024
#define MAX_NAME_LENGTH 256

typedef struct {
    pid_t pid;
    char name[MAX_NAME_LENGTH];
    char state;
    int ppid;
} ProcessInfo;

void getProcessInfo(ProcessInfo *processes, int *count) {
    DIR *procDir;
    struct dirent *entry;
    char path[MAX_NAME_LENGTH];
    FILE *fp;

    procDir = opendir("/proc");
    if (!procDir) {
        perror("Could not open /proc");
        exit(EXIT_FAILURE);
    }

    *count = 0;

    while ((entry = readdir(procDir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            processes[*count].pid = atoi(entry->d_name);

            // Read the process status from /proc/[pid]/status
            snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);
            fp = fopen(path, "r");
            if (fp) {
                fscanf(fp, "Name:\t%s\nState:\t%c\nPPid:\t%d\n", 
                       processes[*count].name, 
                       &processes[*count].state, 
                       &processes[*count].ppid);
                fclose(fp);
                (*count)++;
            }
        }
    }
        
    closedir(procDir);
}

void printProcessInfo(ProcessInfo *processes, int count) {
    printf("\033[1;34m");
    printf("┌─────────┬─────────────────────────────────────┬─────────┬────────┐\n");
    printf("│   PID   │                Name                 │   PPID  │ State  │\n");
    printf("├─────────┼─────────────────────────────────────┼─────────┼────────┤\n");
    printf("\033[0m");
    
    for (int i = 0; i < count; i++) {
        printf("\033[1;33m");
        printf("│%9d│", processes[i].pid);
        printf("\033[0m");
        printf(" %38s │", processes[i].name);
        printf("\033[1;33m");
        printf("%9d│", processes[i].ppid);
        printf("\033[0m");
        printf("  %c     │\n", processes[i].state);
    }

    printf("\033[1;34m");
    printf("└─────────┴─────────────────────────────────────┴─────────┴────────┘\n");
    printf("\033[0m");
}

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int processCount;

    while (1) {
        system("clear");
        getProcessInfo(processes, &processCount);
        printProcessInfo(processes, processCount);
        printf("Press Ctrl+C to exit...\n");
        sleep(2);
    }

    return 0;
}