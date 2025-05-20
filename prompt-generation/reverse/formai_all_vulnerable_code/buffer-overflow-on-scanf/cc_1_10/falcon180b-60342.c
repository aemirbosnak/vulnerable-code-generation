//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: relaxed
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

File files[MAX_FILES];
int num_files = 0;

void create_file(char* name, char* content) {
    if (num_files >= MAX_FILES) {
        printf("Error: Too many files.\n");
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
            memset(files[i].content, 0, MAX_FILE_CONTENT_LENGTH);
            strcpy(files[i].name, "");
            files[i].size = 0;

            printf("File %s deleted.\n", name);

            return;
        }
    }

    printf("File not found.\n");
}

void view_file(char* name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File content:\n%s\n", files[i].content);

            return;
        }
    }

    printf("File not found.\n");
}

int main() {
    int choice, i;

    while (1) {
        printf("\nFile System Simulation\n");
        printf("1. Create file\n2. Delete file\n3. View file\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter file name: ");
            scanf("%s", files[num_files].name);

            printf("Enter file content: ");
            scanf("%[^\n]", files[num_files].content);

            printf("File %s created.\n", files[num_files].name);
            break;

        case 2:
            printf("Enter file name: ");
            scanf("%s", files[num_files].name);

            delete_file(files[num_files].name);
            break;

        case 3:
            printf("Enter file name: ");
            scanf("%s", files[num_files].name);

            view_file(files[num_files].name);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}