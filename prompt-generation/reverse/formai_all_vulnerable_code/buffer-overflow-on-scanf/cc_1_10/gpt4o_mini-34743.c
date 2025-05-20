//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to check if a file exists
int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1; // file exists
    }
    return 0; // file does not exist
}

// Function to back up a file
void backup_file(const char *filename) {
    char backup_filename[256];
    snprintf(backup_filename, sizeof(backup_filename), "%s.bak", filename);
    
    if (file_exists(filename)) {
        FILE *original = fopen(filename, "r");
        FILE *backup = fopen(backup_filename, "w");
        
        if (!backup) {
            printf("Oh no! Could not create backup! Is your hard drive feeling okay?\n");
            return;
        }
        
        char ch;
        printf("Backing up: %s\n", filename);
        while ((ch = fgetc(original)) != EOF) {
            fputc(ch, backup);
        }
        
        fclose(original);
        fclose(backup);
        printf("Success! Your file is now safe and sound as %s\n", backup_filename);
    } else {
        printf("Oops! The file %s does not exist. Have you checked under the bed?\n", filename);
    }
}

// Function to display the menu
void display_menu() {
    printf("\n=============================\n");
    printf("     C File Backup System    \n");
    printf("        v1.0 - Almost Stable\n");
    printf("=============================\n");
    printf("1. Back up a file\n");
    printf("2. Exit with grace and dignity\n");
    printf("=============================\n");
    printf("Please choose an option: ");
}

// Main function
int main() {
    int choice;
    char filename[256];

    do {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the filename to back up (with extension, please!): ");
                scanf("%s", filename);
                backup_file(filename);
                break;
            case 2:
                printf("Exiting... Remember to always save your work and bring snacks!\n");
                break;
            default:
                printf("Hmm... That doesn't seem right. Perhaps your guru didn't teach you well?\n");
        }
    } while (choice != 2);

    printf("Have a great day, and may your files always remain tidy and backed up!\n");
    return 0;
}