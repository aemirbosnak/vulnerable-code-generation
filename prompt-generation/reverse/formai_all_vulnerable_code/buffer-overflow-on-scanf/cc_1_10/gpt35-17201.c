//FormAI DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

void print_pid() {
    // Print the process ID and the parent process ID
    pid_t pid = getpid();
    pid_t ppid = getppid();
    printf("Process ID: %d | Parent Process ID: %d\n", pid, ppid);
}

void exit_handler(int signal) {
    printf("Signal %d received, terminating process\n", signal);
    exit(0);
}

void fork_child_process() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork() failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process created.\n");
        print_pid();
        exit(0);
    } else {
        // Parent process
        printf("Parent process created.\n");
        print_pid();
        printf("Waiting for child process to terminate...\n");
        wait(NULL);
        printf("Child process has terminated.\n");
    }
}

int main() {
    int choice;
    signal(SIGINT, exit_handler);

    do {
        printf("Enter your choice:\n");
        printf("1. Show Process ID and Parent Process ID\n");
        printf("2. Fork Child Process\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_pid();
                break;

            case 2:
                fork_child_process();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice, try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}