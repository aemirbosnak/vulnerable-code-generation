//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_NUM_COMMANDS 10

void execute_command(char *command) {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        char *argv[] = {"/bin/sh", "-c", command, NULL};
        if (execvp(argv[0], argv) == -1) {
            perror("Execution failed");
            exit(1);
        }
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Command '%s' executed with exit status %d\n", command, WEXITSTATUS(status));
        }
    }
}

void get_system_info() {
    printf("\n--- System Information ---\n");
    execute_command("uname -a");
    execute_command("uptime");
    execute_command("free -h");
    execute_command("df -h");
}

void log_command(char *command) {
    FILE *log_file = fopen("system_commands.log", "a");
    if (log_file != NULL) {
        time_t now;
        time(&now);
        fprintf(log_file, "[%s] Executed: '%s'\n", ctime(&now), command);
        fclose(log_file);
    } else {
        perror("Unable to open log file");
    }
}

void print_menu() {
    printf("\n--- System Administration Menu ---\n");
    printf("1. Get system information\n");
    printf("2. List files in current directory\n");
    printf("3. Display current working directory\n");
    printf("4. Create a directory\n");
    printf("5. Remove a directory\n");
    printf("6. Exit\n");
}

void list_files() {
    execute_command("ls -alh");
}

void current_working_directory() {
    execute_command("pwd");
}

void create_directory(char *dir_name) {
    char command[MAX_COMMAND_LENGTH];
    snprintf(command, sizeof(command), "mkdir %s", dir_name);
    execute_command(command);
}

void remove_directory(char *dir_name) {
    char command[MAX_COMMAND_LENGTH];
    snprintf(command, sizeof(command), "rmdir %s", dir_name);
    execute_command(command);
}

int main() {
    int choice;
    char command[MAX_COMMAND_LENGTH];
    char dir_name[MAX_COMMAND_LENGTH];

    while (1) {
        print_menu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                get_system_info();
                break;
            case 2:
                list_files();
                log_command("List files in current directory");
                break;
            case 3:
                current_working_directory();
                log_command("Display current working directory");
                break;
            case 4:
                printf("Enter directory name to create: ");
                fgets(dir_name, sizeof(dir_name), stdin);
                dir_name[strcspn(dir_name, "\n")] = 0; // Remove newline
                create_directory(dir_name);
                log_command(dir_name);
                break;
            case 5:
                printf("Enter directory name to remove: ");
                fgets(dir_name, sizeof(dir_name), stdin);
                dir_name[strcspn(dir_name, "\n")] = 0; // Remove newline
                remove_directory(dir_name);
                log_command(dir_name);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}