//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_SIZE];
    int size;
} file;

file* root;

void create_file(char* name) {
    root = (file*)malloc(sizeof(file));
    strcpy(root->name, name);
    root->size = 0;
    root->content[0] = '\0';
}

void write_to_file(char* content) {
    if (root == NULL) {
        printf("No file found.\n");
        return;
    }

    int content_length = strlen(content);

    if (root->size + content_length > MAX_FILE_SIZE) {
        printf("File is full.\n");
        return;
    }

    strcat(root->content, content);
    root->size += content_length;
}

void read_from_file() {
    if (root == NULL) {
        printf("No file found.\n");
        return;
    }

    printf("File content:\n%s\n", root->content);
}

void delete_file() {
    if (root == NULL) {
        printf("No file found.\n");
        return;
    }

    free(root);
    root = NULL;
}

int main() {
    char command[100];

    root = NULL;

    while (1) {
        printf("Enter command (create/write/read/delete/exit): ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", name);
            create_file(name);
        } else if (strcmp(command, "write") == 0) {
            char content[MAX_FILE_SIZE];
            printf("Enter file content: ");
            scanf("%s", content);
            write_to_file(content);
        } else if (strcmp(command, "read") == 0) {
            read_from_file();
        } else if (strcmp(command, "delete") == 0) {
            delete_file();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}