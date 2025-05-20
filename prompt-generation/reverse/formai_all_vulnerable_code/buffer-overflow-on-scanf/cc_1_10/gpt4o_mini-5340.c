//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILES 10

typedef struct {
    char name[50];
    FILE *fp;
} FileEntry;

void create_file(const char *filename);
void read_file(const char *filename);
void update_file(const char *filename);
void delete_file(const char *filename);
void list_files(FileEntry files[], int count);
void clear_file(FileEntry files[], int *count);

int main() {
    FileEntry files[MAX_FILES];
    int file_count = 0;
    int option;
    char filename[50];

    while (1) {
        printf("\n--- File Management System ---\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Update File\n");
        printf("4. Delete File\n");
        printf("5. List Files\n");
        printf("6. Clear All Files\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        getchar(); // Consume newline

        switch (option) {
            case 1:
                printf("Enter filename to create: ");
                fgets(filename, sizeof(filename), stdin);
                strtok(filename, "\n"); // Remove newline character
                create_file(filename);
                snprintf(files[file_count++].name, sizeof(files[file_count].name), "%s", filename);
                files[file_count - 1].fp = fopen(filename, "a");
                if (files[file_count - 1].fp == NULL) {
                    perror("Failed to open file");
                    return 1;
                }
                break;

            case 2:
                printf("Enter filename to read: ");
                fgets(filename, sizeof(filename), stdin);
                strtok(filename, "\n"); // Remove newline character
                read_file(filename);
                break;

            case 3:
                printf("Enter filename to update: ");
                fgets(filename, sizeof(filename), stdin);
                strtok(filename, "\n"); // Remove newline character
                update_file(filename);
                break;

            case 4:
                printf("Enter filename to delete: ");
                fgets(filename, sizeof(filename), stdin);
                strtok(filename, "\n"); // Remove newline character
                delete_file(filename);
                break;

            case 5:
                list_files(files, file_count);
                break;

            case 6:
                clear_file(files, &file_count);
                break;

            case 7:
                printf("Exiting the program.\n");
                for (int i = 0; i < file_count; i++) {
                    fclose(files[i].fp);
                }
                exit(0);

            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

void create_file(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Failed to create file");
        return;
    }
    fprintf(fp, "This file was created successfully!\n");
    fclose(fp);
    printf("File '%s' created successfully.\n", filename);
}

void read_file(const char *filename) {
    char buffer[MAX_LINE_LENGTH];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Failed to open file for reading");
        return;
    }
    printf("\nContents of '%s':\n", filename);
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);
}

void update_file(const char *filename) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Failed to open file for updating");
        return;
    }
    char input[MAX_LINE_LENGTH];
    printf("Enter text to append to the file (End with Ctrl+D):\n");
    while (fgets(input, sizeof(input), stdin) != NULL) {
        fputs(input, fp);
    }
    fclose(fp);
    printf("File '%s' updated successfully.\n", filename);
}

void delete_file(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("Failed to delete file");
    }
}

void list_files(FileEntry files[], int count) {
    if (count == 0) {
        printf("No files currently managed.\n");
    } else {
        printf("\nList of managed files:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s\n", i + 1, files[i].name);
        }
    }
}

void clear_file(FileEntry files[], int *count) {
    for (int i = 0; i < *count; i++) {
        fclose(files[i].fp);
        remove(files[i].name);
    }
    *count = 0;
    printf("All managed files have been cleared.\n");
}