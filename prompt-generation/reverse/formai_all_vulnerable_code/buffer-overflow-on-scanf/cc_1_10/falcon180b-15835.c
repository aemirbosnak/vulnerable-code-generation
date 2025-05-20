//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_FILE_SYSTEM_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME_SIZE];
    char content[MAX_FILE_SYSTEM_SIZE];
    int size;
} File;

int main() {
    int num_files = 0;
    File *files = malloc(MAX_FILE_SYSTEM_SIZE);

    // Create a file
    char filename[MAX_FILE_NAME_SIZE];
    printf("Enter filename: ");
    scanf("%s", filename);
    strcat(filename, ".txt");

    File *file = malloc(sizeof(File));
    strcpy(file->name, filename);

    // Add the file to the file system
    files[num_files] = *file;
    num_files++;

    // Read a file
    char read_filename[MAX_FILE_NAME_SIZE];
    printf("Enter filename to read: ");
    scanf("%s", read_filename);

    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, read_filename) == 0) {
            printf("File content: %s\n", files[i].content);
            break;
        }
    }

    // Delete a file
    char delete_filename[MAX_FILE_NAME_SIZE];
    printf("Enter filename to delete: ");
    scanf("%s", delete_filename);

    i = 0;
    while (i < num_files) {
        if (strcmp(files[i].name, delete_filename) == 0) {
            free(files[i].content);
            memmove(files + i, files + i + 1, (num_files - i - 1) * sizeof(File));
            num_files--;
            break;
        }
        i++;
    }

    // List all files
    printf("Files:\n");
    for (i = 0; i < num_files; i++) {
        printf("%s\n", files[i].name);
    }

    free(files);
    return 0;
}