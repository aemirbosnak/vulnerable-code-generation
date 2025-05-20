//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_SIZE 50
#define MAX_FILE_CONTENT_SIZE 500

typedef struct {
    char name[MAX_FILE_NAME_SIZE];
    char content[MAX_FILE_CONTENT_SIZE];
} File;

int num_files = 0;
File files[MAX_FILES];

void create_file(char* name, char* content) {
    if (num_files >= MAX_FILES) {
        printf("Error: Too many files.\n");
        return;
    }

    strcpy(files[num_files].name, name);
    strcpy(files[num_files].content, content);

    num_files++;
}

void delete_file(char* name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].name, 0, MAX_FILE_NAME_SIZE);
            memset(files[i].content, 0, MAX_FILE_CONTENT_SIZE);

            num_files--;

            printf("File '%s' deleted.\n", name);

            return;
        }
    }

    printf("File not found.\n");
}

void read_file(char* name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File '%s':\n%s", name, files[i].content);

            return;
        }
    }

    printf("File not found.\n");
}

int main() {
    int choice;

    do {
        printf("1. Create file\n2. Delete file\n3. Read file\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter file name: ");
            scanf("%s", files[num_files].name);

            printf("Enter file content: ");
            scanf("%s", files[num_files].content);

            break;

        case 2:
            printf("Enter file name to delete: ");
            scanf("%s", files[num_files].name);

            delete_file(files[num_files].name);

            break;

        case 3:
            printf("Enter file name to read: ");
            scanf("%s", files[num_files].name);

            read_file(files[num_files].name);

            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice!= 4);

    return 0;
}