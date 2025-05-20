//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LEN 50
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    int size;
} File;

File files[MAX_FILES];
int num_files;

void create_file(char *name) {
    if (num_files >= MAX_FILES) {
        printf("Error: too many files\n");
        return;
    }
    strcpy(files[num_files].name, name);
    files[num_files].size = 0;
    num_files++;
}

void delete_file(char *name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memmove(&files[i], &files[i+1], (num_files - i - 1) * sizeof(File));
            num_files--;
            return;
        }
    }
    printf("Error: file not found\n");
}

void write_file(char *name, char *data, int size) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            if (files[i].size + size > MAX_FILE_SIZE) {
                printf("Error: file too large\n");
                return;
            }
            memcpy(&files[i].name[strlen(files[i].name)], data, size);
            files[i].size += size;
            return;
        }
    }
    printf("Error: file not found\n");
}

void read_file(char *name, char *buffer, int size) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            if (files[i].size > MAX_FILE_SIZE) {
                printf("Error: file too large\n");
                return;
            }
            memcpy(buffer, files[i].name, files[i].size);
            return;
        }
    }
    printf("Error: file not found\n");
}

int main() {
    int i;
    char command[100];
    char name[MAX_FILE_NAME_LEN];
    char data[MAX_FILE_SIZE];
    char buffer[MAX_FILE_SIZE];

    printf("Welcome to the File System Simulator\n");
    printf("Commands: create, delete, write, read\n");

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            create_file(name);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            delete_file(name);
        } else if (strcmp(command, "write") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter data: ");
            scanf("%s", data);
            write_file(name, data, strlen(data));
        } else if (strcmp(command, "read") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            read_file(name, buffer, MAX_FILE_SIZE);
            printf("File contents:\n%s\n", buffer);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}