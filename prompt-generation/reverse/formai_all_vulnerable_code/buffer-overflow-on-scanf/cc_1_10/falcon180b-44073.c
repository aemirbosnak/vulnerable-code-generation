//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_NAME_LEN 20
#define MAX_FILE_SYSTEM_SIZE 100

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    int size;
    char contents[MAX_FILE_SYSTEM_SIZE];
} File;

void create_file(File* file_system, char* name, int size) {
    strcpy(file_system->name, name);
    file_system->size = size;
    memset(file_system->contents, 0, MAX_FILE_SYSTEM_SIZE);
}

void delete_file(File* file_system) {
    memset(file_system, 0, sizeof(File));
}

void write_to_file(File* file_system, char* data, int len) {
    if (len > file_system->size) {
        printf("Error: File is full.\n");
        return;
    }
    strcat(file_system->contents, data);
}

void read_from_file(File* file_system, char* buffer, int len) {
    if (file_system->size == 0) {
        printf("Error: File is empty.\n");
        return;
    }
    strncpy(buffer, file_system->contents, len);
}

int main() {
    File file_system;
    char command[50];
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            char name[MAX_FILE_NAME_LEN];
            int size;
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter file size: ");
            scanf("%d", &size);
            create_file(&file_system, name, size);
        }
        else if (strcmp(command, "delete") == 0) {
            delete_file(&file_system);
        }
        else if (strcmp(command, "write") == 0) {
            char data[100];
            int len;
            printf("Enter data to write: ");
            scanf("%s", data);
            len = strlen(data);
            write_to_file(&file_system, data, len);
        }
        else if (strcmp(command, "read") == 0) {
            char buffer[100];
            int len;
            printf("Enter buffer length: ");
            scanf("%d", &len);
            read_from_file(&file_system, buffer, len);
            printf("File contents: %s\n", buffer);
        }
        else if (strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}