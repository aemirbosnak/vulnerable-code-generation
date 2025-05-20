//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 1024

void display_menu() {
    printf("\nFile Backup System\n");
    printf("1. Backup a file\n");
    printf("2. Exit\n");
    printf("Please enter your choice: ");
}

int backup_file(const char *source, const char *destination) {
    FILE *src_file = fopen(source, "rb");
    if (src_file == NULL) {
        perror("Error opening source file");
        return -1;
    }

    FILE *dest_file = fopen(destination, "wb");
    if (dest_file == NULL) {
        perror("Error opening destination file");
        fclose(src_file);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    return 0;
}

void get_file_path(char *path, const char *prompt) {
    printf("%s", prompt);
    fgets(path, MAX_FILENAME_LENGTH, stdin);
    path[strcspn(path, "\n")] = '\0';  // Remove newline character
}

int main() {
    int choice;
    char source[MAX_FILENAME_LENGTH];
    char destination[MAX_FILENAME_LENGTH];

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // clear newline character from input buffer

        switch (choice) {
            case 1:
                get_file_path(source, "Enter the path of the file to backup: ");
                
                // Construct destination path
                snprintf(destination, MAX_FILENAME_LENGTH, "%s.bak", source);

                if (backup_file(source, destination) == 0) {
                    printf("Backup successful! File saved as: %s\n", destination);
                } else {
                    printf("Backup failed.\n");
                }
                break;

            case 2:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}