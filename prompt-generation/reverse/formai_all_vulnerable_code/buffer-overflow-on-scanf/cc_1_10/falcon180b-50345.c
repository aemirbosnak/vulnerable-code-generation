//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_CONTENT_LENGTH 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    int size;
} File;

int num_files = 0;
File files[MAX_FILES];

int main() {
    int choice;
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    int size;

    do {
        printf("1. Create File\n2. Display File\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter file name: ");
            scanf("%s", name);

            if (num_files >= MAX_FILES) {
                printf("Maximum number of files reached.\n");
            } else {
                printf("Enter file content: ");
                scanf("%s", content);

                size = strlen(content);
                if (size > MAX_FILE_CONTENT_LENGTH) {
                    printf("File content too long.\n");
                } else {
                    strcpy(files[num_files].name, name);
                    strcpy(files[num_files].content, content);
                    files[num_files].size = size;
                    num_files++;
                }
            }

            break;

        case 2:
            printf("Enter file name: ");
            scanf("%s", name);

            for (int i = 0; i < num_files; i++) {
                if (strcmp(name, files[i].name) == 0) {
                    printf("File name: %s\n", files[i].name);
                    printf("File content: %s\n", files[i].content);
                    printf("File size: %d\n", files[i].size);
                    break;
                }
            }

            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }

    } while (1);

    return 0;
}