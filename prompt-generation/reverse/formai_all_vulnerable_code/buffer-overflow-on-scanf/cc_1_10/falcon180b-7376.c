//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LEN 50
#define MAX_FILE_DATA_LEN 500

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    char data[MAX_FILE_DATA_LEN];
    int size;
} file_t;

file_t file_system[MAX_FILES];
int num_files = 0;

void create_file(char* name, char* data, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: File system is full.\n");
        return;
    }

    strcpy(file_system[num_files].name, name);
    strcpy(file_system[num_files].data, data);
    file_system[num_files].size = size;

    num_files++;
}

void delete_file(char* name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].name, name) == 0) {
            memset(file_system[i].name, 0, MAX_FILE_NAME_LEN);
            memset(file_system[i].data, 0, MAX_FILE_DATA_LEN);
            num_files--;
            return;
        }
    }

    printf("Error: File not found.\n");
}

void list_files() {
    int i;

    for (i = 0; i < num_files; i++) {
        printf("%s\t%d bytes\n", file_system[i].name, file_system[i].size);
    }
}

int main() {
    char command[100];
    char name[MAX_FILE_NAME_LEN];
    char data[MAX_FILE_DATA_LEN];
    int size;

    while (true) {
        printf("Enter command (create, delete, list, exit): ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter file data: ");
            scanf("%s", data);
            size = strlen(data);
            create_file(name, data, size);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            delete_file(name);
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}