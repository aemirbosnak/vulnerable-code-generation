//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>
#include <time.h>

#define MAX_CMDS 10
#define CMD_LENGTH 256
#define LOG_FILE "sys_admin_log.txt"

void log_action(const char *action) {
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        perror("Failed to log action");
        return;
    }
    
    time_t now = time(NULL);
    fprintf(fp, "[%s] %s\n", ctime(&now), action);
    fclose(fp);
}

void display_system_info() {
    printf("\n=== System Information ===\n");
    printf("Hostname: ");
    system("hostname");
    
    printf("Uptime: ");
    system("uptime");

    printf("Users Logged In: ");
    system("who");

    log_action("Displayed system information.");
}

void list_processes() {
    printf("\n=== List of Processes ===\n");
    system("ps -aux");
    log_action("Listed all processes.");
}

void check_disk_usage() {
    printf("\n=== Disk Usage Statistics ===\n");
    system("df -h");
    log_action("Checked disk usage.");
}

void check_memory_usage() {
    printf("\n=== Memory Usage Statistics ===\n");
    system("free -h");
    log_action("Checked memory usage.");
}

void execute_command(char *cmd) {
    int status;
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        execlp(cmd, cmd, NULL);
        perror("Command execution failed");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Fork failed");
    } else {
        // Parent process
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Command executed with exit status: %d\n", WEXITSTATUS(status));
            char log_entry[CMD_LENGTH + 30];
            snprintf(log_entry, sizeof(log_entry), "Executed command: %s", cmd);
            log_action(log_entry);
        }
    }
}

void interactive_shell() {
    char command[CMD_LENGTH];

    printf("\n=== Interactive Shell ===\n");
    while (1) {
        printf("admin@sys:~$ ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "exit") == 0) {
            log_action("Exited interactive shell.");
            break;
        }
        execute_command(command);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n=== System Administration Menu ===\n");
        printf("1. Display System Info\n");
        printf("2. List Processes\n");
        printf("3. Check Disk Usage\n");
        printf("4. Check Memory Usage\n");
        printf("5. Interactive Shell\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                display_system_info();
                break;
            case 2:
                list_processes();
                break;
            case 3:
                check_disk_usage();
                break;
            case 4:
                check_memory_usage();
                break;
            case 5:
                interactive_shell();
                break;
            case 0:
                log_action("Exited program.");
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}