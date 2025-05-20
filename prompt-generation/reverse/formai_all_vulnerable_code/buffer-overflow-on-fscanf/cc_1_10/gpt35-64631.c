//FormAI DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_COUNT 20

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int size;
} file_t;

file_t files[MAX_FILE_COUNT];

void backup_files() {
    FILE* backup_file;
    backup_file = fopen("backup.txt", "w");
    if (backup_file == NULL) {
        printf("Error opening backup file");
        return;
    }
    for (int i = 0; i < MAX_FILE_COUNT; i++) {
        if (files[i].size > 0) {
            fprintf(backup_file, "%s %d\n", files[i].filename, files[i].size);
        }
    }
    fclose(backup_file);
}

void load_backup() {
    FILE* backup_file;
    backup_file = fopen("backup.txt", "r");
    if (backup_file == NULL) {
        printf("No backup found.");
        return;
    }
    char filename[MAX_FILENAME_LENGTH];
    int size;
    while (fscanf(backup_file, "%s %d", filename, &size) != EOF) {
        int index = -1;
        for (int i = 0; i < MAX_FILE_COUNT; i++) {
            if (strcmp(files[i].filename, filename) == 0) {
                index = i;
                break;
            }
            else if (index == -1 && files[i].size == 0) {
                index = i;
            }
        }
        if (index != -1) {
            strcpy(files[index].filename, filename);
            files[index].size = size;
        }
    }
    fclose(backup_file);
}

void print_files() {
    printf("List of current files:\n");
    for (int i = 0; i < MAX_FILE_COUNT; i++) {
        if (files[i].size > 0) {
            printf("%s - size: %d bytes\n", files[i].filename, files[i].size);
        }
    }
}

int main() {
    int input;
    load_backup();
    do {
        printf("Choose an option:\n1. Add file\n2. Remove file\n3. Backup files\n4. Print files\n5. Exit\n");
        scanf("%d", &input);
        if (input == 1) {
            char filename[MAX_FILENAME_LENGTH];
            int size;
            printf("Enter filename: ");
            scanf("%s", filename);
            printf("Enter file size: ");
            scanf("%d", &size);
            int index = -1;
            for (int i = 0; i < MAX_FILE_COUNT; i++) {
                if (strcmp(files[i].filename, filename) == 0) {
                    index = i;
                    break;
                }
                else if (index == -1 && files[i].size == 0) {
                    index = i;
                }
            }
            if (index != -1) {
                strcpy(files[index].filename, filename);
                files[index].size = size;
                printf("File added.\n");
            }
            else {
                printf("Unable to add file. Maximum number of files reached.\n");
            }
        }
        else if (input == 2) {
            char filename[MAX_FILENAME_LENGTH];
            printf("Enter filename: ");
            scanf("%s", filename);
            int index = -1;
            for (int i = 0; i < MAX_FILE_COUNT; i++) {
                if (strcmp(files[i].filename, filename) == 0) {
                    index = i;
                    break;
                }
            }
            if (index != -1) {
                strcpy(files[index].filename, "");
                files[index].size = 0;
                printf("File removed.\n");
            }
            else {
                printf("File not found.\n");
            }
        }
        else if (input == 3) {
            backup_files();
            printf("Files backed up.\n");
        }
        else if (input == 4) {
            print_files();
        }
    } while (input != 5);
    return 0;
}