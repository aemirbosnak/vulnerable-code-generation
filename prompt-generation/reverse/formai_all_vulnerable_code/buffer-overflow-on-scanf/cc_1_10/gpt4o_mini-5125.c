//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to list files in a directory
void list_files(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }
    
    printf("Listing files in directory: %s\n", directory);
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] != '.') { // Skip hidden files
            printf(" - %s\n", entry->d_name);
        }
    }
    closedir(dp);
}

// Function to check disk usage
void check_disk_usage() {
    printf("\nDisk usage:\n");
    // Execute df command
    system("df -h");
}

// Function to display system information
void display_system_info() {
    printf("\nSystem Information:\n");
    // Execute uname command
    system("uname -a");
}

// Main function to utilize the defined functionalities
int main() {
    char directory[256];
    int choice;

    printf("Welcome to the System Administration Program!\n");
    printf("Please enter a directory to list files: ");
    scanf("%s", directory);

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. List files in the directory\n");
        printf("2. Check disk usage\n");
        printf("3. Display system information\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_files(directory);
                break;
            case 2:
                check_disk_usage();
                break;
            case 3:
                display_system_info();
                break;
            case 4:
                printf("Exiting the program. Farewell!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}