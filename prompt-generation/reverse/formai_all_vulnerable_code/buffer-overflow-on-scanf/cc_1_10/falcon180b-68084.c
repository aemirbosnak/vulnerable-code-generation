//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESS_NUMBER 100
#define MAX_PROCESS_NAME_LENGTH 20

typedef struct Process {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int memoryUsage;
} Process;

int getProcessMemoryUsage(int pid) {
    FILE *file;
    char filename[20];
    int memoryUsage = 0;

    sprintf(filename, "/proc/%d/statm", pid);
    file = fopen(filename, "r");

    if (file!= NULL) {
        int pages = 0;
        fscanf(file, "%d", &pages);
        memoryUsage = pages * 4096; // 4KB per page
        fclose(file);
    }

    return memoryUsage;
}

int main() {
    int processNumber = 0;
    Process processes[MAX_PROCESS_NUMBER];
    char userInput[50];

    while (1) {
        printf("Enter a process name (or type 'list' to see current processes): ");
        scanf("%s", userInput);

        if (strcmp(userInput, "list") == 0) {
            printf("Current processes:\n");
            for (int i = 0; i < processNumber; i++) {
                printf("%s (PID: %d, Memory Usage: %d KB)\n", processes[i].name, processes[i].pid, processes[i].memoryUsage / 1024);
            }
        } else {
            int pid = fork();

            if (pid == 0) {
                execlp(userInput, userInput, NULL);
                exit(1);
            } else {
                wait(NULL);
            }

            int memoryUsage = getProcessMemoryUsage(pid);

            for (int i = 0; i < processNumber; i++) {
                if (processes[i].pid == pid) {
                    processes[i].memoryUsage = memoryUsage;
                    break;
                }
            }

            if (processNumber < MAX_PROCESS_NUMBER - 1) {
                strcpy(processes[processNumber].name, userInput);
                processes[processNumber].pid = pid;
                processes[processNumber].memoryUsage = memoryUsage;
                processNumber++;
            }
        }
    }

    return 0;
}