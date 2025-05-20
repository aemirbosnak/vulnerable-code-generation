//FormAI DATASET v1.0 Category: File system simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_CONTENT_LENGTH 1000
#define MAX_FILES 100

/* Struct to represent a file */
typedef struct {
    char name[MAX_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} File;

/* Array to hold all files */
File file_system[MAX_FILES];

/* Counter to keep track of number of files */
int file_count = 0;

/* Function to create a new file */
void create_file(char* name, char* content) {
    /* Check if maximum number of files has been reached */
    if (file_count >= MAX_FILES) {
        printf("File system is full. Cannot create new file.\n");
        return;
    }

    /* Check if file with same name already exists */
    for (int i = 0; i < file_count; i++) {
        if (strcmp(name, file_system[i].name) == 0) {
            printf("File with same name already exists. Cannot create new file.\n");
            return;
        }
    }

    /* Create new file */
    File new_file;
    strcpy(new_file.name, name);
    strcpy(new_file.content, content);
    file_system[file_count++] = new_file;

    printf("File created successfully.\n");
}

/* Function to delete a file */
void delete_file(char* name) {
    /* Search for file with given name */
    int index = -1;
    for (int i = 0; i < file_count; i++) {
        if (strcmp(name, file_system[i].name) == 0) {
            index = i;
            break;
        }
    }

    /* File not found */
    if (index == -1) {
        printf("File not found. Cannot delete file.\n");
        return;
    }

    /* Delete file */
    for (int i = index; i < file_count - 1; i++) {
        file_system[i] = file_system[i + 1];
    }
    file_count--;

    printf("File deleted successfully.\n");
}

/* Function to read the content of a file */
void read_file(char* name) {
    /* Search for file with given name */
    int index = -1;
    for (int i = 0; i < file_count; i++) {
        if (strcmp(name, file_system[i].name) == 0) {
            index = i;
            break;
        }
    }

    /* File not found */
    if (index == -1) {
        printf("File not found. Cannot read file.\n");
        return;
    }

    /* Print file content */
    printf("Content of '%s' file:\n", name);
    printf("%s\n", file_system[index].content);
}

/* Main function */
int main() {
    char command[10];
    char name[MAX_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];

    while (1) {
        printf("Enter command (create, delete, read, exit): ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            getchar();  // Consume newline character
            printf("Enter file content: ");
            fgets(content, MAX_CONTENT_LENGTH, stdin);
            create_file(name, content);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            delete_file(name);
        } else if (strcmp(command, "read") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            read_file(name);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command. Please enter a valid command.\n");
        }
    }

    return 0;
}