//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LEN 50

struct file_t {
    char name[MAX_FILE_NAME_LEN];
    int size;
};

int num_files = 0;
struct file_t files[MAX_FILES];

void add_file(char* name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: too many files\n");
        return;
    }

    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    num_files++;
}

void list_files() {
    printf("Files:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

void remove_file(char* name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("Removed file: %s\n", name);
            num_files--;
            for (int j = i; j < num_files; j++) {
                strcpy(files[j].name, files[j+1].name);
                files[j].size = files[j+1].size;
            }
            return;
        }
    }

    printf("File not found: %s\n", name);
}

int main() {
    char command[100];
    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[MAX_FILE_NAME_LEN];
            printf("Enter file name: ");
            scanf("%s", name);

            int size;
            printf("Enter file size: ");
            scanf("%d", &size);

            add_file(name, size);
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else if (strcmp(command, "remove") == 0) {
            char name[MAX_FILE_NAME_LEN];
            printf("Enter file name: ");
            scanf("%s", name);

            remove_file(name);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}