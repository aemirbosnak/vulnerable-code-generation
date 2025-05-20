//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 50

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
} File;

int num_files = 0;
File files[MAX_FILES];

void create_file(char* name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: cannot create file, maximum number of files reached.\n");
        return;
    }

    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    num_files++;
}

void delete_file(char* name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (!strcmp(files[i].name, name)) {
            num_files--;
            break;
        }
    }
}

void list_files() {
    int i;

    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    char command[100];
    char name[MAX_FILE_NAME];
    int size;

    while (1) {
        printf("Enter command (create/delete/list/exit): ");
        scanf("%s", command);

        if (!strcmp(command, "create")) {
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter file size: ");
            scanf("%d", &size);
            create_file(name, size);
        } else if (!strcmp(command, "delete")) {
            printf("Enter file name: ");
            scanf("%s", name);
            delete_file(name);
        } else if (!strcmp(command, "list")) {
            list_files();
        } else if (!strcmp(command, "exit")) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}