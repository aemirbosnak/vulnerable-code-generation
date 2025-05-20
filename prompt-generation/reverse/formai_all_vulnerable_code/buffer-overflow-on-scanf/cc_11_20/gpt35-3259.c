//FormAI DATASET v1.0 Category: File Backup System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_SIZE 10000

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
} File;

int main() {
    File* backup = NULL;
    int num_files = 0;
    int max_files = 10;

    while (1) {
        // Display menu
        printf("File Backup System\n");
        printf("-------------------\n");
        printf("1. Add a file\n");
        printf("2. Remove a file\n");
        printf("3. List files\n");
        printf("4. Save backup\n");
        printf("5. Load backup\n");
        printf("6. Exit\n");

        // Accept user choice
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Add a file
            if (num_files == max_files) {
                printf("Maximum number of files reached.\n");
            } else {
                File file;
                printf("Enter filename: ");
                scanf("%s", file.filename);
                printf("Enter file data: ");
                scanf("%s", file.data);
                file.size = strlen(file.data);
                backup = realloc(backup, sizeof(File) * (num_files + 1));
                backup[num_files] = file;
                num_files++;
                printf("File added successfully.\n");
            }
        } else if (choice == 2) {
            // Remove a file
            if (num_files == 0) {
                printf("No files to remove.\n");
            } else {
                char filename[MAX_FILENAME_LENGTH];
                printf("Enter filename: ");
                scanf("%s", filename);
                int file_index = -1;
                for (int i = 0; i < num_files; i++) {
                    if (strcmp(filename, backup[i].filename) == 0) {
                        file_index = i;
                        break;
                    }
                }
                if (file_index == -1) {
                    printf("File not found.\n");
                } else {
                    for (int i = file_index; i < num_files - 1; i++) {
                        backup[i] = backup[i + 1];
                    }
                    num_files--;
                    printf("File removed successfully.\n");
                }
            }
        } else if (choice == 3) {
            // List files
            if (num_files == 0) {
                printf("No files to list.\n");
            } else {
                printf("Filename\tSize\n");
                for (int i = 0; i < num_files; i++) {
                    printf("%s\t\t%d\n", backup[i].filename, backup[i].size);
                }
            }
        } else if (choice == 4) {
            // Save backup
            if (num_files == 0) {
                printf("No files to save.\n");
            } else {
                char filename[MAX_FILENAME_LENGTH];
                printf("Enter filename: ");
                scanf("%s", filename);
                FILE* file_pointer = fopen(filename, "wb");
                fwrite(&num_files, sizeof(int), 1, file_pointer);
                for (int i = 0; i < num_files; i++) {
                    fwrite(&backup[i], sizeof(File), 1, file_pointer);
                }
                fclose(file_pointer);
                printf("Backup saved successfully.\n");
            }
        } else if (choice == 5) {
            // Load backup
            char filename[MAX_FILENAME_LENGTH];
            printf("Enter filename: ");
            scanf("%s", filename);
            FILE* file_pointer = fopen(filename, "rb");
            if (file_pointer == NULL) {
                printf("File not found.\n");
            } else {
                fread(&num_files, sizeof(int), 1, file_pointer);
                backup = realloc(backup, sizeof(File) * num_files);
                fread(backup, sizeof(File), num_files, file_pointer);
                fclose(file_pointer);
                printf("Backup loaded successfully.\n");
            }
        } else if (choice == 6) {
            // Exit
            printf("Goodbye!\n");
            break;
        } else {
            // Invalid choice
            printf("Invalid choice.\n");
        }
    }

    return 0;
}