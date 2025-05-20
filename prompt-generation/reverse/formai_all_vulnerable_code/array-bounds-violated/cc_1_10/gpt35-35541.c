//FormAI DATASET v1.0 Category: File Backup System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_SIZE 1000000 // 1MB

typedef struct File {
    char name[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
} File;

void saveFile(File file, char *directory) {
    char path[MAX_FILENAME_LENGTH + 10];
    strcpy(path, directory);
    strcat(path, file.name);

    FILE *fp = fopen(path, "wb");
    fwrite(file.data, sizeof(char), file.size, fp);
    fclose(fp);
}

void backupFile(char *filename, char *directory) {
    char path[MAX_FILENAME_LENGTH + 10];
    strcpy(path, directory);
    strcat(path, filename);

    FILE *fp = fopen(path, "rb");
    if (fp == NULL) {
        printf("%s does not exist or could not be opened.\n", filename);
        return;
    }

    File file;
    strncpy(file.name, filename, MAX_FILENAME_LENGTH);
    fseek(fp, 0, SEEK_END);
    file.size = ftell(fp);
    rewind(fp);
    fread(file.data, sizeof(char), file.size, fp);
    fclose(fp);

    saveFile(file, directory);

    printf("Backup of %s saved successfully!\n", filename);
}

void menu() {
    printf("C File Backup System\n");
    printf("--------------------\n");
    printf("1. Backup file\n");
    printf("2. Exit\n");
    printf("Enter choice: ");
}

int main() {
    char directory[MAX_FILENAME_LENGTH];
    printf("Enter backup directory: ");
    scanf("%s", directory);

    if (directory[strlen(directory) - 1] != '/') {
        strcat(directory, "/");
    }

    int choice = 0;
    while (choice != 2) {
        menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                {
                    char filename[MAX_FILENAME_LENGTH];
                    printf("Enter filename: ");
                    scanf("%s", filename);
                    backupFile(filename, directory);
                    break;
                }
            case 2:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}