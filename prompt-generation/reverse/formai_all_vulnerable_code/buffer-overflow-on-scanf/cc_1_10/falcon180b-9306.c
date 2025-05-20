//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: authentic
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

int current_file_index = 0;
File files[MAX_FILES];

void create_file(char* name, char* content) {
    if (current_file_index >= MAX_FILES) {
        printf("Error: Maximum number of files reached\n");
        return;
    }

    strcpy(files[current_file_index].name, name);
    strcpy(files[current_file_index].content, content);
    files[current_file_index].size = strlen(content);

    current_file_index++;
}

void read_file(char* name) {
    int i;

    for (i = 0; i < current_file_index; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File content: %s\n", files[i].content);
            break;
        }
    }
}

void delete_file(char* name) {
    int i;

    for (i = 0; i < current_file_index; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].content, 0, files[i].size);
            strcpy(files[i].name, "");
            files[i].size = 0;
            break;
        }
    }
}

int main() {
    char command[50];

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            char file_name[MAX_FILE_NAME_LENGTH];
            char file_content[MAX_FILE_CONTENT_LENGTH];

            printf("Enter file name: ");
            scanf("%s", file_name);

            printf("Enter file content: ");
            scanf("%s", file_content);

            create_file(file_name, file_content);
        }
        else if (strcmp(command, "read") == 0) {
            char file_name[MAX_FILE_NAME_LENGTH];

            printf("Enter file name: ");
            scanf("%s", file_name);

            read_file(file_name);
        }
        else if (strcmp(command, "delete") == 0) {
            char file_name[MAX_FILE_NAME_LENGTH];

            printf("Enter file name: ");
            scanf("%s", file_name);

            delete_file(file_name);
        }
        else if (strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Invalid command\n");
        }
    }

    return 0;
}