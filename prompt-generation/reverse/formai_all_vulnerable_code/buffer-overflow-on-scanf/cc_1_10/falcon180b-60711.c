//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 30
#define MAX_FILE_CONTENT_LENGTH 200

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    int size;
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(char *name, char *content) {
    if (num_files >= MAX_FILES) {
        printf("Error: Too many files\n");
        return;
    }

    strcpy(files[num_files].name, name);
    strcpy(files[num_files].content, content);
    files[num_files].size = strlen(content);

    num_files++;
}

void delete_file(char *name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].name, 0, MAX_FILE_NAME_LENGTH);
            memset(files[i].content, 0, MAX_FILE_CONTENT_LENGTH);
            files[i].size = 0;

            num_files--;
            return;
        }
    }

    printf("Error: File not found\n");
}

void display_files() {
    int i;

    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Create file\n2. Delete file\n3. Display files\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter file name: ");
            char name[MAX_FILE_NAME_LENGTH];
            scanf("%s", name);

            printf("Enter file content: ");
            char content[MAX_FILE_CONTENT_LENGTH];
            scanf("%s", content);

            create_file(name, content);
            break;

        case 2:
            printf("Enter file name to delete: ");
            char del_name[MAX_FILE_NAME_LENGTH];
            scanf("%s", del_name);

            delete_file(del_name);
            break;

        case 3:
            display_files();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}