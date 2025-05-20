//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    pid_t pid;
    int status;
    char command[MAX_COMMAND_LENGTH];
} process_t;

int main(int argc, char *argv[]) {
    int num_processes = 0;
    process_t processes[MAX_PROCESSES];

    printf("System Process Viewer\n");

    while (1) {
        printf("\nEnter 'l' to list processes or 'q' to quit: ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'l' || choice == 'L') {
            system("clear");
            printf("\nPID\tStatus\tCommand\n");

            for (int i = 0; i < num_processes; i++) {
                printf("%d\t", processes[i].pid);

                if (WIFEXITED(processes[i].status)) {
                    printf("Exited with status %d\n", WEXITSTATUS(processes[i].status));
                } else if (WIFSIGNALED(processes[i].status)) {
                    printf("Killed by signal %d\n", WTERMSIG(processes[i].status));
                } else if (WIFSTOPPED(processes[i].status)) {
                    printf("Stopped by signal %d\n", WSTOPSIG(processes[i].status));
                } else {
                    printf("Unknown status\n");
                }
            }
        } else if (choice == 'q' || choice == 'Q') {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}