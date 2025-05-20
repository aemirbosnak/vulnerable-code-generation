//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

struct process {
    char name[20];
    int pid;
    int memory;
};

int main() {
    int i, j, n;
    char input[50];

    struct process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter the name of process %d: ", i+1);
        scanf("%s", processes[i].name);
        processes[i].pid = i+1;
        processes[i].memory = 0;
    }

    while(1) {
        system("clear");
        printf("\nRAM USAGE MONITOR\n");

        for(i = 0; i < n; i++) {
            printf("\nProcess %d: %s\n", processes[i].pid, processes[i].name);
            printf("Memory Usage: %d KB\n\n", processes[i].memory);
        }

        printf("\nEnter the PID of the process to check memory usage: ");
        scanf("%d", &j);

        for(i = 0; i < n; i++) {
            if(processes[i].pid == j) {
                printf("\nMemory Usage of Process %d: %d KB\n", j, processes[i].memory);
                break;
            }
        }

        printf("\nEnter 'q' to quit: ");
        scanf("%s", input);

        if(strcmp(input, "q") == 0)
            break;
    }

    return 0;
}