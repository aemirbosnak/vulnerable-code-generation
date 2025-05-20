//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 10

int process_count = 0;
int process_table[MAX_PROCESSES];

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        for (int i = 0; i < process_count; i++) {
            if (process_table[i] == -1) {
                process_table[i] = 0;
                printf("Process %d terminated\n", i);
                break;
            }
        }
    }
}

void add_process(int pid) {
    for (int i = 0; i < process_count; i++) {
        if (process_table[i] == -1) {
            process_table[i] = pid;
            printf("Process %d added\n", i);
            break;
        }
    }
    process_count++;
}

void remove_process(int pid) {
    for (int i = 0; i < process_count; i++) {
        if (process_table[i] == pid) {
            process_table[i] = -1;
            printf("Process %d removed\n", i);
            break;
        }
    }
    process_count--;
}

void print_process_table() {
    printf("Process ID\tStatus\n");
    for (int i = 0; i < process_count; i++) {
        if (process_table[i] == -1) {
            printf("%d\tTerminated\n", i);
        } else {
            printf("%d\tRunning\n", i);
        }
    }
}

int main() {
    signal(SIGCHLD, sigchld_handler);

    while (1) {
        printf("Enter 1 to add a process, 2 to remove a process, or 3 to print the process table:\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the process ID to add:\n");
                int pid;
                scanf("%d", &pid);
                add_process(pid);
                break;
            case 2:
                printf("Enter the process ID to remove:\n");
                int remove_pid;
                scanf("%d", &remove_pid);
                remove_process(remove_pid);
                break;
            case 3:
                print_process_table();
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}