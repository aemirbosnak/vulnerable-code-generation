//FormAI DATASET v1.0 Category: File system simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

struct file {
    char name[20];
    int size;
};

int file_count = 0;
struct file files[MAX_FILES];

void create_file(char *name, int size) {
    if (file_count == MAX_FILES) {
        printf("Error: File system full!\n");
        return;
    }

    struct file new_file;
    strcpy(new_file.name, name);
    new_file.size = size;

    files[file_count] = new_file;
    file_count++;

    printf("File created: %s (%d bytes)\n", name, size);
}

void delete_file(char *name) {
    int index = -1;

    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: File not found!\n");
        return;
    }

    for (int i = index; i < file_count-1; i++) {
        files[i] = files[i+1];
    }

    file_count--;

    printf("File deleted: %s\n", name);
}

void print_files() {
    printf("\n");
    for (int i = 0; i < file_count; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
    printf("\n");
}

int main() {
    printf("Welcome to the Happy File System Simulator!\n");

    while (1) {
        printf("Enter a command (create, delete, print, exit): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            char name[20];
            printf("Enter file name (up to 20 characters): ");
            scanf("%s", name);

            int size;
            printf("Enter file size (in bytes): ");
            scanf("%d", &size);

            create_file(name, size);
        }

        else if (strcmp(command, "delete") == 0) {
            char name[20];
            printf("Enter file name to delete: ");
            scanf("%s", name);

            delete_file(name);
        }

        else if (strcmp(command, "print") == 0) {
            print_files();
        }

        else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}