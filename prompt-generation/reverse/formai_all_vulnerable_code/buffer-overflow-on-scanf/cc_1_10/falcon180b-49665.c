//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_SIZE];
    int size;
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(char* name, char* content) {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    strcpy(files[num_files].name, name);
    strcpy(files[num_files].content, content);
    files[num_files].size = strlen(content);

    num_files++;
}

void read_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("%s\n", files[i].content);
            return;
        }
    }

    printf("File not found.\n");
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].content, 0, sizeof(files[i].content));
            files[i].size = 0;

            printf("File deleted.\n");
            return;
        }
    }

    printf("File not found.\n");
}

void main() {
    int choice, i;

    while (1) {
        printf("\n\n");
        printf("1. Create file\n");
        printf("2. Read file\n");
        printf("3. Delete file\n");
        printf("4. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter file name: ");
            scanf("%s", files[num_files].name);

            printf("Enter file content: ");
            scanf("%s", files[num_files].content);

            break;
        case 2:
            printf("Enter file name: ");
            scanf("%s", files[num_files].name);

            read_file(files[num_files].name);
            break;
        case 3:
            printf("Enter file name: ");
            scanf("%s", files[num_files].name);

            delete_file(files[num_files].name);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
}