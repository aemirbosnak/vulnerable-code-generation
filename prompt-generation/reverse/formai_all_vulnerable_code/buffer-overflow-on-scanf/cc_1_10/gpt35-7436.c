//FormAI DATASET v1.0 Category: File system simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100           // Define maximum number of files in the system
#define MAX_FILENAME 25         // Define maximum number of characters in a filename

struct file {
    char name[MAX_FILENAME];    // Stores the name of the file
    int size;                   // Stores the size of the file in bytes
    char contents[100];         // Stores the contents of the file
};

struct file files[MAX_FILES];   // Create an array of files

int num_files = 0;              // Initialize the number of files in the system to 0

void create_file(char *name, int size, char *contents) {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files in system reached.\n");
        return;
    }
    if (strlen(name) > MAX_FILENAME) {
        printf("Error: Filename is too long.\n");
        return;
    }
    for (int i = 0; i < num_files; i++) {
        if (strcmp(name, files[i].name) == 0) {
            printf("Error: File with that name already exists.\n");
            return;
        }
    }
    struct file new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    strcpy(new_file.contents, contents);
    files[num_files] = new_file;
    num_files++;
    printf("File \"%s\" created.\n", name);
}

void delete_file(char *name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(name, files[i].name) == 0) {
            for (int j = i; j < num_files - 1; j++) {
                files[j] = files[j+1];
            }
            num_files--;
            printf("File \"%s\" deleted.\n", name);
            return;
        }
    }
    printf("Error: File with that name does not exist.\n");
}

void list_files() {
    if (num_files == 0) {
        printf("No files in system.\n");
        return;
    }
    printf("Files in system:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    char command[50];
    while (1) {
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            char name[MAX_FILENAME];
            int size;
            char contents[100];
            printf("Enter file name (up to %d characters): ", MAX_FILENAME);
            scanf("%s", name);
            printf("Enter file size (in bytes): ");
            scanf("%d", &size);
            printf("Enter file contents (up to 100 characters): ");
            scanf("%s", contents);
            create_file(name, size, contents);
        }
        else if (strcmp(command, "delete") == 0) {
            char name[MAX_FILENAME];
            printf("Enter file name to delete: ");
            scanf("%s", name);
            delete_file(name);
        }
        else if (strcmp(command, "list") == 0) {
            list_files();
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting file system simulation. Goodbye!\n");
            exit(0);
        }
        else {
            printf("Error: Invalid command.\n");
        }
    }
}