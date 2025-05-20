//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 10

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_content[MAX_FILE_SIZE];
} file_t;

file_t file_backup[100];
int file_count = 0;

void backup_file(char *file_name, char *file_content) {
    if (file_count >= 100) {
        printf("Error: Backup limit reached.\n");
        return;
    }

    strcpy(file_backup[file_count].file_name, file_name);
    strcpy(file_backup[file_count].file_content, file_content);

    file_count++;
}

void restore_file(char *file_name) {
    int i;

    for (i = 0; i < file_count; i++) {
        if (strcmp(file_backup[i].file_name, file_name) == 0) {
            printf("File restored: %s\n", file_backup[i].file_content);
            return;
        }
    }

    printf("Error: File not found.\n");
}

void main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_content[MAX_FILE_SIZE];
    char choice;

    do {
        printf("File Backup System\n");
        printf("===================\n");
        printf("1. Backup File\n");
        printf("2. Restore File\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter file name: ");
                scanf("%s", file_name);
                printf("Enter file content: ");
                scanf("%s", file_content);
                backup_file(file_name, file_content);
                break;
            case '2':
                printf("Enter file name to restore: ");
                scanf("%s", file_name);
                restore_file(file_name);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= '3');
}