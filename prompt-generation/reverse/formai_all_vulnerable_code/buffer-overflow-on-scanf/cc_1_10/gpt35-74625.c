//FormAI DATASET v1.0 Category: File Backup System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_CONTENT_LENGTH 200
#define MAX_NUM_FILES 100

// Structure to hold file information
struct File {
    char name[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
};

// Global array of files
struct File files[MAX_NUM_FILES];
int next_free_index = 0;

// Function to add a file to the backup system
void add_file(char* name, char* content) {
    if (next_free_index == MAX_NUM_FILES) {
        printf("Maximum number of files exceeded. Cannot add new file.\n");
        return;
    }

    // Copy file name and content to next free index in global array
    strcpy(files[next_free_index].name, name);
    strcpy(files[next_free_index].content, content);

    printf("File %s added to backup system.\n", name);

    next_free_index++;
}

// Function to list all files in the backup system
void list_files() {
    if (next_free_index == 0) {
        printf("No files in backup system.\n");
        return;
    }

    printf("Files in backup system:\n");

    for (int i = 0; i < next_free_index; i++) {
        printf("%s\n", files[i].name);
    }
}

// Function to retrieve a file from the backup system
void retrieve_file(char* name) {
    int found = 0;

    for (int i = 0; i < next_free_index; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File %s found in backup system:\n", name);
            printf("%s\n", files[i].content);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("File %s not found in backup system.\n", name);
    }
}

int main() {
    char input[MAX_FILE_CONTENT_LENGTH];
    char name[MAX_FILENAME_LENGTH];

    while (1) {
        // Get user input
        printf("Enter command (add, list, or retrieve): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);

            printf("Enter file content: ");
            scanf("%s", input);

            add_file(name, input);
        } else if (strcmp(input, "list") == 0) {
            list_files();
        } else if (strcmp(input, "retrieve") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);

            retrieve_file(name);
        } else {
            printf("Invalid command. Please enter add, list, or retrieve.\n");
        }
    }

    return 0;
}