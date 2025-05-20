//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int processes[10];
    int priorities[10];
    int process_count = 0;
    int i;

    for (i = 0; i < 10; i++) {
        printf("Enter the priority of process %d: ", i + 1);
        scanf("%d", &priorities[i]);
        processes[i] = (i + 1) * 10;
    }

    printf("Processes with their priorities:\n");
    for (i = 0; i < 10; i++) {
        printf("%d - %d\n", processes[i], priorities[i]);
    }

    int sorted_processes[10];
    int sorted_priorities[10];
    int temp;

    for (i = 0; i < 10; i++) {
        sorted_processes[i] = processes[i];
        sorted_priorities[i] = priorities[i];
    }

    for (i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (sorted_priorities[j] > sorted_priorities[j + 1]) {
                temp = sorted_priorities[j];
                sorted_priorities[j] = sorted_priorities[j + 1];
                sorted_priorities[j + 1] = temp;

                temp = sorted_processes[j];
                sorted_processes[j] = sorted_processes[j + 1];
                sorted_processes[j + 1] = temp;
            }
        }
    }

    printf("\nProcesses with their priorities after sorting:\n");
    for (i = 0; i < 10; i++) {
        printf("%d - %d\n", sorted_processes[i], sorted_priorities[i]);
    }

    return 0;
}