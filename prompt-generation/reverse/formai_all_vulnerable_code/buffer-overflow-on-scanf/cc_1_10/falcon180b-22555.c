//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PROCESSES 100

typedef struct {
    char name[20];
    int pid;
    int memory_usage;
} Process;

int main() {
    int num_processes = 0;
    Process processes[MAX_PROCESSES];
    char input_buffer[100];
    int i, j, k;
    int total_memory_usage = 0;
    double avg_memory_usage = 0;

    printf("Welcome to the RAM usage monitor!\n");
    printf("Please enter the number of processes you want to monitor (up to %d):\n", MAX_PROCESSES);
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) {
        printf("Please enter the name and PID of process %d:\n", i+1);
        scanf("%s %d", processes[i].name, &processes[i].pid);
        processes[i].memory_usage = 0;
    }

    while (1) {
        printf("\n");
        for (i = 0; i < num_processes; i++) {
            sprintf(input_buffer, "ps -p %d -o %%mem= | awk '{printf \"%.2f\", $1}'", processes[i].pid);
            if (system(input_buffer) == 0) {
                processes[i].memory_usage = atof(input_buffer);
                total_memory_usage += processes[i].memory_usage;
            } else {
                processes[i].memory_usage = 0;
            }
        }

        avg_memory_usage = total_memory_usage / num_processes;

        printf("RAM usage:\n");
        for (i = 0; i < num_processes; i++) {
            printf("%s (PID %d): %.2f%%\n", processes[i].name, processes[i].pid, processes[i].memory_usage);
        }

        printf("Average RAM usage: %.2f%%\n", avg_memory_usage);

        sleep(5);
    }

    return 0;
}