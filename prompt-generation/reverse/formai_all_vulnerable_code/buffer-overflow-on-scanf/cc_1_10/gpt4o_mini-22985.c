//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_PATH_LENGTH 256

void print_menu();
void backup_file(const char *source, const char *destination);
void display_files(const char *directory);
int confirm_backup();

int main() {
    char source_file[MAX_PATH_LENGTH];
    char destination_file[MAX_PATH_LENGTH];
    int choice;

    while (1) {
        print_menu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the source file path: ");
                scanf("%s", source_file);
                
                printf("Enter the destination file path: ");
                scanf("%s", destination_file);
                
                if (confirm_backup()) {
                    backup_file(source_file, destination_file);
                } else {
                    printf("Backup cancelled.\n");
                }
                break;

            case 2:
                printf("Enter directory to display files from: ");
                char directory[MAX_PATH_LENGTH];
                scanf("%s", directory);
                display_files(directory);
                break;

            case 3:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("\n--- File Backup System ---\n");
    printf("1. Backup a file\n");
    printf("2. Display files in a directory\n");
    printf("3. Exit\n");
}

void backup_file(const char *source, const char *destination) {
    FILE *source_file = fopen(source, "rb");
    if (source_file == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *dest_file = fopen(destination, "wb");
    if (dest_file == NULL) {
        perror("Error opening destination file");
        fclose(source_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, source_file)) > 0) {
        fwrite(buffer, sizeof(char), bytes, dest_file);
    }

    printf("Backup completed successfully from %s to %s\n", source, destination);

    fclose(source_file);
    fclose(dest_file);
}

void display_files(const char *directory) {
    struct stat st;

    if (stat(directory, &st) != 0) {
        perror("Failed to get directory status");
        return;
    }

    if (!S_ISDIR(st.st_mode)) {
        printf("%s is not a directory\n", directory);
        return;
    }

    printf("\nFiles in directory %s:\n", directory);
    char command[MAX_PATH_LENGTH + 10];
    
    snprintf(command, sizeof(command), "ls -l %s", directory);
    system(command);
}

int confirm_backup() {
    char confirmation;
    printf("Are you sure you want to proceed with the backup? (y/n): ");
    scanf(" %c", &confirmation);
    return (confirmation == 'y' || confirmation == 'Y');
}