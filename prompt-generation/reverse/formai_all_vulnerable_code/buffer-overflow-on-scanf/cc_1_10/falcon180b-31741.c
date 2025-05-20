//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct process {
    char name[20];
    int pid;
    int ram_usage;
} Process;

int main() {
    int num_processes = 0;
    Process processes[MAX_PROCESSES];
    char input[50];
    bool quit = false;

    printf("Welcome to the Cheerful RAM Usage Monitor!\n");
    printf("Please enter the number of processes you want to monitor (up to %d):\n", MAX_PROCESSES - 1);
    scanf("%d", &num_processes);

    printf("Please enter the name and PID of each process:\n");

    for (int i = 0; i < num_processes; i++) {
        printf("Process %d:\n", i + 1);
        scanf("%s %d", processes[i].name, &processes[i].pid);
        processes[i].ram_usage = 0;
    }

    while (!quit) {
        printf("\n");
        printf("Current RAM usage by process:\n");
        for (int i = 0; i < num_processes; i++) {
            sprintf(input, "ps -p %d -o %%mem=", processes[i].pid);
            FILE *fp = popen(input, "r");
            fscanf(fp, "%d", &processes[i].ram_usage);
            pclose(fp);

            printf("%s: %d%%\n", processes[i].name, processes[i].ram_usage);
        }

        printf("\nPress 'q' to quit or any other key to refresh.\n");
        scanf(" %c", &input[0]);

        if (input[0] == 'q') {
            quit = true;
        }
    }

    return 0;
}