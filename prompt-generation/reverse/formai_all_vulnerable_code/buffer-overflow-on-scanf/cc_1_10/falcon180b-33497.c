//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 1000
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
} file_t;

file_t files[MAX_FILES];
int num_files = 0;

void create_file(char* name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: Too many files!\n");
        return;
    }

    strncpy(files[num_files].name, name, MAX_FILE_NAME_LENGTH);
    files[num_files].size = size;
    num_files++;

    printf("File '%s' created with size %d bytes.\n", name, size);
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File '%s' deleted.\n", name);
            num_files--;
            return;
        }
    }

    printf("Error: File not found!\n");
}

void list_files() {
    int i;
    printf("Files:\n");
    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    char command[100];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            int size;

            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter file size (bytes): ");
            scanf("%d", &size);

            create_file(name, size);
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_FILE_NAME_LENGTH];

            printf("Enter file name: ");
            scanf("%s", name);

            delete_file(name);
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}