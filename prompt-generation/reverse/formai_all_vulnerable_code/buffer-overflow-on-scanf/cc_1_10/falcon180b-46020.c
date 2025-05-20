//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1000
#define MAX_FILES 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_SIZE];
    int size;
} file_t;

file_t files[MAX_FILES];
int file_count = 0;

void create_file(char* name) {
    int i;
    for (i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File already exists.\n");
            return;
        }
    }
    strcpy(files[file_count].name, name);
    files[file_count].size = 0;
    file_count++;
}

void write_file(char* name, char* content) {
    int i;
    for (i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcat(files[i].content, content);
            files[i].size += strlen(content);
            printf("File written successfully.\n");
            return;
        }
    }
    printf("File not found.\n");
}

void read_file(char* name) {
    int i;
    for (i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File content: %s\n", files[i].content);
            return;
        }
    }
    printf("File not found.\n");
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].name, 0, MAX_FILE_NAME_LENGTH);
            memset(files[i].content, 0, MAX_FILE_SIZE);
            files[i].size = 0;
            printf("File deleted successfully.\n");
            return;
        }
    }
    printf("File not found.\n");
}

int main() {
    char command[100];
    while(1) {
        printf("Enter command: ");
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", name);
            create_file(name);
        } else if (strcmp(command, "write") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            char content[MAX_FILE_SIZE];
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter file content: ");
            scanf("%s", content);
            write_file(name, content);
        } else if (strcmp(command, "read") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", name);
            read_file(name);
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", name);
            delete_file(name);
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}