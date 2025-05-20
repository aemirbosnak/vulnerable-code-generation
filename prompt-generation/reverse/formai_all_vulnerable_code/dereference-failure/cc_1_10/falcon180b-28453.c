//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_LINE_LENGTH 80

typedef struct {
    char filename[MAX_LINE_LENGTH];
    int size;
} file_t;

file_t *files = NULL;
int num_files = 0;
int total_size = 0;

void add_file(char *filename, int size) {
    file_t *new_file = malloc(sizeof(file_t));
    if (new_file == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    strcpy(new_file->filename, filename);
    new_file->size = size;
    files = realloc(files, sizeof(file_t) * (num_files + 1));
    if (files == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    files[num_files] = *new_file;
    num_files++;
    total_size += size;
}

void print_files() {
    printf("Filename\tSize\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t%d\n", files[i].filename, files[i].size);
    }
    printf("\nTotal size: %d bytes\n", total_size);
}

int main() {
    char filename[MAX_LINE_LENGTH];
    int size;

    printf("Enter filenames and sizes (enter 'done' when finished):\n");
    while (fgets(filename, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (strcmp(filename, "done") == 0) {
            break;
        }
        if (sscanf(filename, "%s %d", filename, &size)!= 2) {
            printf("Error: Invalid input\n");
            exit(1);
        }
        add_file(filename, size);
    }

    print_files();

    return 0;
}