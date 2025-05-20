//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILES 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int is_file;
} File;

File directory[MAX_FILES];
int num_files = 0;

void create_file(char *name) {
    if (num_files >= MAX_FILES) {
        printf("Error: Directory is full.\n");
        return;
    }

    strcpy(directory[num_files].name, name);
    directory[num_files].is_file = 1;
    num_files++;
}

void delete_file(char *name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(directory[i].name, name) == 0) {
            if (!directory[i].is_file) {
                printf("Error: %s is not a file.\n", name);
                return;
            }

            for (int j = i; j < num_files - 1; j++) {
                strcpy(directory[j].name, directory[j + 1].name);
            }

            num_files--;
            printf("%s deleted.\n", name);
            return;
        }
    }

    printf("Error: %s not found.\n", name);
}

void list_files() {
    int i;

    printf("Files in directory:\n");
    for (i = 0; i < num_files; i++) {
        if (directory[i].is_file) {
            printf("- %s\n", directory[i].name);
        }
    }
}

int main() {
    char command[30], name[MAX_NAME_LENGTH];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "create") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            create_file(name);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            delete_file(name);
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}