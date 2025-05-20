//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_CONTENT_LENGTH 1000

typedef struct file_t {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    int size;
} file_t;

int num_files = 0;
file_t files[MAX_FILES];

void create_file(char* name, char* content) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(name, files[i].name) == 0) {
            printf("Error: File already exists.\n");
            return;
        }
    }
    strcpy(files[num_files].name, name);
    strcpy(files[num_files].content, content);
    files[num_files].size = strlen(content);
    num_files++;
}

void read_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(name, files[i].name) == 0) {
            printf("Content of file %s:\n%s\n", files[i].name, files[i].content);
            return;
        }
    }
    printf("Error: File not found.\n");
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(name, files[i].name) == 0) {
            memset(files[i].name, 0, MAX_FILE_NAME_LENGTH);
            memset(files[i].content, 0, MAX_FILE_CONTENT_LENGTH);
            num_files--;
            printf("File %s deleted.\n", name);
            return;
        }
    }
    printf("Error: File not found.\n");
}

void list_files() {
    int i;
    for (i = 0; i < num_files; i++) {
        printf("%s\n", files[i].name);
    }
}

int main() {
    char command[100];
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    while (1) {
        printf("Enter command (create/read/delete/list/exit): ");
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter file content: ");
            scanf("%s", content);
            create_file(name, content);
        } else if (strcmp(command, "read") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            read_file(name);
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