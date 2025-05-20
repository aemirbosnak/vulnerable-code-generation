//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

// Function to execute a shell command and return the output
void execute_command(const char *command) {
    char buffer[128];
    FILE *pipe = popen(command, "r");
    if (pipe == NULL) {
        printf("Couldn't open pipe for command: %s\n", command);
        return;
    }
    
    // Output the result of the command
    printf("Executing command: %s\n", command);
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        printf("%s", buffer);
    }
    
    if (pclose(pipe) == -1) {
        perror("pclose failed");
    }
}

// Function to display the current system time
void display_current_time() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    
    char buffer[26];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Current system time: %s\n", buffer);
}

// Function to create a new user
void create_new_user(const char *username) {
    char command[256];
    snprintf(command, sizeof(command), "sudo adduser %s", username);
    execute_command(command);
}

// Function to delete a user
void delete_user(const char *username) {
    char command[256];
    snprintf(command, sizeof(command), "sudo deluser %s", username);
    execute_command(command);
}

// Function to list all users
void list_users() {
    execute_command("cat /etc/passwd | cut -d: -f1");
}

// Function to display system information
void display_system_info() {
    execute_command("uname -a");
}

// Function to display system memory usage
void display_memory_usage() {
    execute_command("free -h");
}

// Function to display disk usage
void display_disk_usage() {
    execute_command("df -h");
}

// Main program
int main() {
    int choice;
    char username[50];
    
    do {
        // Display a menu
        printf("\n*** Surprise System Admin Menu ***\n");
        printf("1. Display Current Time\n");
        printf("2. Create a New User\n");
        printf("3. Delete a User\n");
        printf("4. List All Users\n");
        printf("5. Display System Information\n");
        printf("6. Display Memory Usage\n");
        printf("7. Display Disk Usage\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_current_time();
                break;
            case 2:
                printf("Enter the username to create: ");
                scanf("%s", username);
                create_new_user(username);
                break;
            case 3:
                printf("Enter the username to delete: ");
                scanf("%s", username);
                delete_user(username);
                break;
            case 4:
                list_users();
                break;
            case 5:
                display_system_info();
                break;
            case 6:
                display_memory_usage();
                break;
            case 7:
                display_disk_usage();
                break;
            case 8:
                printf("Exiting... Have a surprising day!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}