//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE 1024
#define MAX_NUM_FILES 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_SIZE];
    int size;
} File;

int num_files = 0;
File files[MAX_NUM_FILES];

void create_file(char *name, char *content, int size) {
    if (num_files >= MAX_NUM_FILES) {
        printf("Error: Too many files.\n");
        return;
    }

    strcpy(files[num_files].name, name);
    strcpy(files[num_files].content, content);
    files[num_files].size = size;

    num_files++;
}

void delete_file(char *name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            num_files--;

            if (i < num_files) {
                memmove(&files[i], &files[i+1], sizeof(File) * (num_files - i - 1));
            }

            break;
        }
    }
}

void display_files() {
    int i;

    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    int choice, size;
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_SIZE];

    while (1) {
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. Display files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter file content: ");
            scanf("%s", content);
            printf("Enter file size: ");
            scanf("%d", &size);

            create_file(name, content, size);
            break;

        case 2:
            printf("Enter file name to delete: ");
            scanf("%s", name);

            delete_file(name);
            break;

        case 3:
            display_files();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}