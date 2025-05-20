//FormAI DATASET v1.0 Category: File system simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_FILENAME_LEN 256
#define MAX_DATA_LEN 1024

// Structures
typedef struct {
    char filename[MAX_FILENAME_LEN];
    char data[MAX_DATA_LEN];
    int size;
} file;

// Functions
void create_file(file**, int*, char[], char[]);
void delete_file(file**, int*, char[]);
void read_file(file**, int*, char[]);
void write_file(file**, int*, char[], char[]);
void list_files(file**, int*);

int main() {
    file* files = NULL;
    int num_files = 0;
    char command[10];
    char arg1[MAX_FILENAME_LEN];
    char arg2[MAX_DATA_LEN];

    while (1) {
        printf("Enter command (create, delete, read, write, list): ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            printf("Enter filename: ");
            scanf("%s", arg1);
            printf("Enter data: ");
            scanf("%s", arg2);
            create_file(&files, &num_files, arg1, arg2);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter filename: ");
            scanf("%s", arg1);
            delete_file(&files, &num_files, arg1);
        } else if (strcmp(command, "read") == 0) {
            printf("Enter filename: ");
            scanf("%s", arg1);
            read_file(&files, &num_files, arg1);
        } else if (strcmp(command, "write") == 0) {
            printf("Enter filename: ");
            scanf("%s", arg1);
            printf("Enter data: ");
            scanf("%s", arg2);
            write_file(&files, &num_files, arg1, arg2);
        } else if (strcmp(command, "list") == 0) {
            list_files(&files, &num_files);
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    free(files);
    return 0;
}

void create_file(file** files, int* num_files, char filename[], char data[]) {
    // Check if file already exists
    for (int i = 0; i < *num_files; i++) {
        if (strcmp((*files)[i].filename, filename) == 0) {
            printf("Error: File already exists.\n");
            return;
        }
    }

    // Create new file
    if (*num_files == 0) {
        *files = (file*) malloc(sizeof(file));
    } else {
        *files = (file*) realloc(*files, (*num_files + 1) * sizeof(file));
    }

    strcpy((*files)[*num_files].filename, filename);
    strcpy((*files)[*num_files].data, data);
    (*files)[*num_files].size = strlen(data);
    (*num_files)++;

    printf("File created successfully.\n");
}

void delete_file(file** files, int* num_files, char filename[]) {
    // Find file
    int index = -1;
    for (int i = 0; i < *num_files; i++) {
        if (strcmp((*files)[i].filename, filename) == 0) {
            index = i;
            break;
        }
    }

    // Delete file
    if (index == -1) {
        printf("Error: File not found.\n");
    } else {
        memmove((*files) + index, (*files) + index + 1, (*num_files - index - 1) * sizeof(file));
        (*num_files)--;
        *files = (file*) realloc(*files, (*num_files) * sizeof(file));
        printf("File deleted successfully.\n");
    }
}

void read_file(file** files, int* num_files, char filename[]) {
    // Find file
    int index = -1;
    for (int i = 0; i < *num_files; i++) {
        if (strcmp((*files)[i].filename, filename) == 0) {
            index = i;
            break;
        }
    }

    // Read file
    if (index == -1) {
        printf("Error: File not found.\n");
    } else {
        printf("Data for file '%s': \n%s\n", filename, (*files)[index].data);
    }
}

void write_file(file** files, int* num_files, char filename[], char data[]) {
    // Find file
    int index = -1;
    for (int i = 0; i < *num_files; i++) {
        if (strcmp((*files)[i].filename, filename) == 0) {
            index = i;
            break;
        }
    }

    // Write file
    if (index == -1) {
        printf("Error: File not found.\n");
    } else {
        strcpy((*files)[index].data, data);
        (*files)[index].size = strlen(data);
        printf("File updated successfully.\n");
    }
}

void list_files(file** files, int* num_files) {
    if (*num_files == 0) {
        printf("No files.\n");
        return;
    }

    printf("Files:\n");
    for (int i = 0; i < *num_files; i++) {
        printf("- %s\n", (*files)[i].filename);
    }
}