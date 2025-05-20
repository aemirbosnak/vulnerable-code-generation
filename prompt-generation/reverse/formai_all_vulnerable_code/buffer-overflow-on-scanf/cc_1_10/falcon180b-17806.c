//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: ultraprecise
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
} file_t;

int num_files = 0;
file_t files[MAX_FILES];

void create_file(char* name, char* content) {
    if (num_files >= MAX_FILES) {
        printf("Error: too many files\n");
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
            memset(files[i].name, 0, sizeof(files[i].name));
            memset(files[i].content, 0, sizeof(files[i].content));

            num_files--;

            return;
        }
    }

    printf("Error: file not found\n");
}

void list_files() {
    int i;

    for (i = 0; i < num_files; i++) {
        printf("File name: %s\nFile content: %s\nFile size: %d\n\n", files[i].name, files[i].content, files[i].size);
    }
}

int main() {
    char command[100];

    while (1) {
        printf("Enter command (create/delete/list/exit): ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            char content[MAX_FILE_CONTENT_LENGTH];

            printf("Enter file name: ");
            scanf("%s", name);

            printf("Enter file content: ");
            scanf("%s", content);

            create_file(name, content);
        }
        else if (strcmp(command, "delete") == 0) {
            char name[MAX_FILE_NAME_LENGTH];

            printf("Enter file name: ");
            scanf("%s", name);

            delete_file(name);
        }
        else if (strcmp(command, "list") == 0) {
            list_files();
        }
        else if (strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Error: invalid command\n");
        }
    }

    return 0;
}