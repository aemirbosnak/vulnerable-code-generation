//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int ram_usage;
} Process;

int main() {
    int num_processes = 0;
    Process *processes = (Process *)malloc(MAX_PROCESSES * sizeof(Process));

    while (1) {
        int i;
        for (i = 0; i < num_processes; i++) {
            printf("%s (PID %d) is using %d bytes of RAM.\n", processes[i].name, processes[i].pid, processes[i].ram_usage);
        }

        printf("\nPress 'a' to add a process, 'd' to delete a process, or 'q' to quit.\n");
        char command;
        scanf("%c", &command);

        switch (command) {
        case 'a':
            printf("Enter process name: ");
            scanf("%s", processes[num_processes].name);
            printf("Enter PID: ");
            scanf("%d", &processes[num_processes].pid);
            processes[num_processes].ram_usage = 0;
            num_processes++;
            break;
        case 'd':
            printf("Enter PID of process to delete: ");
            int pid_to_delete;
            scanf("%d", &pid_to_delete);
            int found = 0;
            for (i = 0; i < num_processes; i++) {
                if (processes[i].pid == pid_to_delete) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                num_processes--;
                for (i = 0; i < num_processes; i++) {
                    if (i > (num_processes - 1)) {
                        processes[i].pid = processes[i - 1].pid;
                        strcpy(processes[i].name, processes[i - 1].name);
                        processes[i].ram_usage = processes[i - 1].ram_usage;
                    } else {
                        processes[i].pid = processes[i + 1].pid;
                        strcpy(processes[i].name, processes[i + 1].name);
                        processes[i].ram_usage = processes[i + 1].ram_usage;
                    }
                }
            } else {
                printf("PID not found.\n");
            }
            break;
        case 'q':
            free(processes);
            exit(0);
        default:
            printf("Invalid command.\n");
        }
    }

    return 0;
}