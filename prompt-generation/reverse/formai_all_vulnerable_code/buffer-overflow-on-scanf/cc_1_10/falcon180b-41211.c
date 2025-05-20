//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 50
#define MAX_FILE_CONTENT 500

typedef struct {
    char name[MAX_FILE_NAME];
    char content[MAX_FILE_CONTENT];
    int size;
} file_t;

file_t files[MAX_FILES];
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

void delete_file(char* name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(&files[i], 0, sizeof(file_t));
            printf("File %s deleted.\n", name);
            return;
        }
    }

    printf("File not found.\n");
}

void display_files() {
    int i;

    for (i = 0; i < num_files; i++) {
        printf("File name: %s\nFile content: %s\nFile size: %d\n",
               files[i].name, files[i].content, files[i].size);
    }
}

int main() {
    int choice;
    char name[MAX_FILE_NAME];
    char content[MAX_FILE_CONTENT];

    do {
        printf("\nFile System Simulation\n");
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
            create_file(name, content);
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
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}