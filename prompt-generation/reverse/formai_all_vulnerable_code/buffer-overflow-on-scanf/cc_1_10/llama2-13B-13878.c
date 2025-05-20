//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_PROCESS_COUNT 5

// Structure to hold the command and its arguments
typedef struct {
    char *cmd;
    char *args[20];
} cmd_t;

// Function to execute a command and display its output
void execute_command(cmd_t *cmd) {
    int status;
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execvp(cmd->cmd, cmd->args);
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else {
        wait(&status);
        printf("Command executed successfully with status %d\n", status);
    }
}

// Function to print a menu of commands and their descriptions
void print_menu() {
    printf("Welcome to the system administration console\n");
    printf("----------------------------------------------\n");
    printf("Commands:\n");
    printf(" 1. List all processes\n");
    printf(" 2. Kill all processes\n");
    printf(" 3. Create a new user\n");
    printf(" 4. Set the root password\n");
    printf(" 5. Quit\n");
    printf("Enter your choice (1-5): ");
}

// Function to list all processes
void list_processes() {
    char *command = "/bin/ps -ef";
    cmd_t cmd;
    cmd.cmd = command;
    execute_command(&cmd);
}

// Function to kill all processes
void kill_processes() {
    char *command = "/bin/kill -9";
    cmd_t cmd;
    cmd.cmd = command;
    execute_command(&cmd);
}

// Function to create a new user
void create_user() {
    char *command = "/bin/useradd -m -s /bin/bash";
    cmd_t cmd;
    cmd.cmd = command;
    execute_command(&cmd);
}

// Function to set the root password
void set_root_password() {
    char *command = "/bin/passwd";
    cmd_t cmd;
    cmd.cmd = command;
    execute_command(&cmd);
}

int main() {
    print_menu();

    while (1) {
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_processes();
                break;
            case 2:
                kill_processes();
                break;
            case 3:
                create_user();
                break;
            case 4:
                set_root_password();
                break;
            case 5:
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}