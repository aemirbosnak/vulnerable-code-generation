//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char content[MAX_FILE_SIZE];
} file_t;

file_t files[MAX_FILES];
int num_files;

void create_file(char* name, int size, char* content) {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    strcpy(files[num_files].content, content);
    num_files++;
}

void read_file(char* name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File content: %s\n", files[i].content);
            return;
        }
    }

    printf("Error: File not found.\n");
}

void delete_file(char* name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(files[i].name, "");
            files[i].size = 0;
            strcpy(files[i].content, "");
            num_files--;
            return;
        }
    }

    printf("Error: File not found.\n");
}

int main() {
    int choice;
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char content[MAX_FILE_SIZE];

    num_files = 0;

    do {
        printf("\nFile System Simulation\n");
        printf("1. Create file\n");
        printf("2. Read file\n");
        printf("3. Delete file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter file size: ");
            scanf("%d", &size);
            printf("Enter file content: ");
            scanf("%s", content);
            create_file(name, size, content);
            break;

        case 2:
            printf("Enter file name: ");
            scanf("%s", name);
            read_file(name);
            break;

        case 3:
            printf("Enter file name: ");
            scanf("%s", name);
            delete_file(name);
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