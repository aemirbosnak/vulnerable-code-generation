//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILE_NAME_MAX_LENGTH 50

typedef struct {
    char name[FILE_NAME_MAX_LENGTH];
    char content[100];
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
    num_files++;
}

void read_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("Content of file %s:\n%s\n", name, files[i].content);
            return;
        }
    }
    printf("File not found.\n");
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(&files[i], 0, sizeof(file_t));
            num_files--;
            printf("File %s deleted.\n", name);
            return;
        }
    }
    printf("File not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nFile System Simulation\n");
        printf("1. Create file\n2. Read file\n3. Delete file\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter file name: ");
            char name[FILE_NAME_MAX_LENGTH];
            scanf("%s", name);
            printf("Enter file content: ");
            char content[100];
            scanf("%s", content);
            create_file(name, content);
            break;

        case 2:
            printf("Enter file name: ");
            char name2[FILE_NAME_MAX_LENGTH];
            scanf("%s", name2);
            read_file(name2);
            break;

        case 3:
            printf("Enter file name: ");
            char name3[FILE_NAME_MAX_LENGTH];
            scanf("%s", name3);
            delete_file(name3);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}