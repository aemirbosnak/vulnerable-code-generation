//FormAI DATASET v1.0 Category: System administration ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// define module for managing system processes
void manage_processes() {
    printf("System process management module\n");

    // retrieve the user's choice
    int choice;
    printf("Enter 1 to list all running processes\n");
    printf("Enter 2 to start a new process\n");
    printf("Enter 3 to stop a running process\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Listing all running processes:\n");
            system("ps aux"); // command to list processes
            break;
        case 2: {
            char command[50];
            printf("Enter the command to start a new process: ");
            scanf("%s", command);
            system(command); // command to start a new process
            break;
        }
        case 3: {
            int process_id;
            printf("Enter the process ID to stop: ");
            scanf("%d", &process_id);
            char kill_command[50];
            sprintf(kill_command, "kill %d", process_id);
            system(kill_command); // command to stop a process by its ID
            break;
        }
        default:
            printf("Invalid choice, please try again.\n");
    }
}

// define module for managing disk usage
void manage_disk() {
    printf("Disk usage management module\n");

    // retrieve the user's choice
    int choice;
    printf("Enter 1 to check current disk usage\n");
    printf("Enter 2 to free up disk space\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Checking current disk usage:\n");
            system("df -h"); // command to check disk usage
            break;
        case 2: {
            char directory[50];
            printf("Enter the directory to clean: ");
            scanf("%s", directory);
            char clean_command[50];
            sprintf(clean_command, "sudo rm -rf %s/*", directory);
            system(clean_command); // command to clean a directory (using sudo for permissions)
            break;
        }
        default:
            printf("Invalid choice, please try again.\n");
    }
}

int main() {
    // retrieve the user's choice of module to use
    int choice;
    printf("Enter 1 to manage system processes\n");
    printf("Enter 2 to manage disk usage\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            manage_processes();
            break;
        case 2:
            manage_disk();
            break;
        default:
            printf("Invalid choice, please try again.\n");
    }

    return 0;
}