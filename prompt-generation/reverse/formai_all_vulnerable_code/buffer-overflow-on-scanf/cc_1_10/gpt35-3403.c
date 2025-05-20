//FormAI DATASET v1.0 Category: File system simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_CONTENT_LENGTH 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    int size;
} file;

file files[100];
int num_files = 0;

void create_file() {
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            printf("File already exists\n");
            return;
        }
    }

    printf("Enter content: ");
    scanf("%s", content);

    files[num_files].size = strlen(content);
    strcpy(files[num_files].filename, filename);
    strcpy(files[num_files].content, content);
    num_files++;
}

void delete_file() {
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            for (int j = i; j < num_files - 1; j++) {
                strcpy(files[j].filename, files[j+1].filename);
                strcpy(files[j].content, files[j+1].content);
                files[j].size = files[j+1].size;
            }
            num_files--;
            printf("File deleted\n");
            return;
        }
    }
    printf("File not found\n");
}

void display_file() {
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            printf("File contents:\n%s\n", files[i].content);
            return;
        }
    }
    printf("File not found\n");
}

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. Display file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_file();
                break;
            case 2:
                delete_file();
                break;
            case 3:
                display_file();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}