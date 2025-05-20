//FormAI DATASET v1.0 Category: File system simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LEN 100

typedef struct {
    char name[MAX_FILENAME_LEN];
    int size;
} file_t;

typedef struct {
    file_t files[MAX_FILES];
    int num_files;
    int total_size;
} directory_t;

int create_file(directory_t *dir, char *filename, int size) {
    if (dir->num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return 0;
    }

    if (dir->total_size + size > 10000) {
        printf("Error: Insufficient disk space.\n");
        return 0;
    }

    strcpy(dir->files[dir->num_files].name, filename);
    dir->files[dir->num_files].size = size;
    dir->num_files++;
    dir->total_size += size;

    printf("File '%s' created.\n", filename);

    return 1;
}

int delete_file(directory_t *dir, char *filename) {
    int i;

    for (i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, filename) == 0) {
            dir->total_size -= dir->files[i].size;

            for (; i < dir->num_files - 1; i++) {
                dir->files[i] = dir->files[i + 1];
            }

            dir->num_files--;

            printf("File '%s' deleted.\n", filename);

            return 1;
        }
    }

    printf("Error: File '%s' not found.\n", filename);

    return 0;
}

void print_directory(directory_t *dir) {
    int i;

    printf("\nDirectory contents:\n");

    for (i = 0; i < dir->num_files; i++) {
        printf(" - %s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }

    printf("\nTotal directory size: %d bytes.\n", dir->total_size);
}

int main() {
    directory_t dir;
    dir.num_files = 0;
    dir.total_size = 0;

    printf("Welcome to the file system simulator!\n\n");

    while (1) {
        char command[MAX_FILENAME_LEN];
        char filename[MAX_FILENAME_LEN];
        int size;

        printf("Enter a command (create, delete, print, exit): ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            printf("Enter filename: ");
            scanf("%s", filename);

            printf("Enter file size in bytes: ");
            scanf("%d", &size);

            create_file(&dir, filename, size);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter filename: ");
            scanf("%s", filename);

            delete_file(&dir, filename);
        } else if (strcmp(command, "print") == 0) {
            print_directory(&dir);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Error: Invalid command '%s'.\n", command);
        }

        printf("\n");
    }

    return 0;
}