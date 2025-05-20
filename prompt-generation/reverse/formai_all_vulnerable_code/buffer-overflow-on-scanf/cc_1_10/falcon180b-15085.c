//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display the menu options
void display_menu() {
    printf("Data Recovery Tool\n");
    printf("1. Recover Deleted Files\n");
    printf("2. Recover Lost Partition\n");
    printf("3. Recover Corrupted Files\n");
    printf("4. Exit\n");
}

// Function to recover deleted files
void recover_deleted_files() {
    printf("Recovering deleted files...\n");
    // Code to recover deleted files
}

// Function to recover lost partition
void recover_lost_partition() {
    printf("Recovering lost partition...\n");
    // Code to recover lost partition
}

// Function to recover corrupted files
void recover_corrupted_files() {
    printf("Recovering corrupted files...\n");
    // Code to recover corrupted files
}

// Main function
int main() {
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                recover_deleted_files();
                break;
            case 2:
                recover_lost_partition();
                break;
            case 3:
                recover_corrupted_files();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice!= 4);
    return 0;
}