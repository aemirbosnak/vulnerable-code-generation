//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    char name[50];
    int pid;
    int ram_usage;
} process;

void init() {
    setvbuf(stdout, NULL, _IONBF, 0);
}

int main() {
    init();
    int num_processes = 0;
    process *processes = malloc(MAX_PROCESSES * sizeof(process));
    char command[100];
    while (1) {
        printf("\nEnter a command (list, add, remove, exit): ");
        scanf("%s", command);
        if (strcmp(command, "list") == 0) {
            for (int i = 0; i < num_processes; i++) {
                printf("%s (%d) - %d bytes\n", processes[i].name, processes[i].pid, processes[i].ram_usage);
            }
        } else if (strcmp(command, "add") == 0) {
            printf("Enter process name: ");
            scanf("%s", processes[num_processes].name);
            printf("Enter PID: ");
            scanf("%d", &processes[num_processes].pid);
            processes[num_processes].ram_usage = 0;
            num_processes++;
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter PID: ");
            int pid;
            scanf("%d", &pid);
            for (int i = 0; i < num_processes; i++) {
                if (processes[i].pid == pid) {
                    num_processes--;
                    for (int j = i; j < num_processes; j++) {
                        processes[j] = processes[j+1];
                    }
                }
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    free(processes);
    return 0;
}