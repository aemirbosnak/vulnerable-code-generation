//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define THRESHOLD 20 // Disk space threshold in percentage
#define TEMP_DIR "/tmp/" // Temporary directory to clean

void check_disk_usage();
void clean_temp_files();
void display_disk_info();

int main() {
    int choice;

    while (1) {
        printf("\nDisk Space Management System\n");
        printf("1. Check Disk Usage\n");
        printf("2. Clean Temporary Files\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_disk_usage();
                break;
            case 2:
                clean_temp_files();
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void check_disk_usage() {
    FILE *fp;
    char buffer[256];

    // Execute the df command to get disk usage
    fp = popen("df -h", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    printf("\nDisk Usage Information:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Check if the output corresponds to our interest
        if (strstr(buffer, "/") != NULL) {
            printf("%s", buffer);
        }
    }

    // Close the file pointer
    pclose(fp);
    
    // Check available space percentage
    fp = popen("df | grep '/$' | awk '{print $5}' | sed 's/%//'", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    int used_space;
    fscanf(fp, "%d", &used_space);
    pclose(fp);

    if (used_space > (100 - THRESHOLD)) {
        printf("Warning: Available disk space is below %d%%.\n", THRESHOLD);
    } else {
        printf("Disk usage is within acceptable limits.\n");
    }
}

void clean_temp_files() {
    char confirm;
    printf("This action will delete all files in %s. Are you sure? (y/n): ", TEMP_DIR);
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        printf("Cleaning up temporary files...\n");
        // Execute the rm command to remove temporary files
        int ret = system("rm -rf " TEMP_DIR "*");
        if (ret == 0) {
            printf("Temporary files cleaned up successfully.\n");
        } else {
            printf("Error occurred while cleaning temporary files.\n");
        }
    } else {
        printf("No files were deleted.\n");
    }
}

void display_disk_info() {
    // Placeholder function for optional future enhancements
    printf("Displaying more detailed disk information can be implemented here.\n");
}