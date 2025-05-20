//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SYSTEM_SIZE 10000
#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    int size;
} File;

typedef struct {
    File **files;
    int num_files;
    int max_files;
} FileSystem;

void init_file_system(FileSystem *fs) {
    fs->files = (File **) malloc(MAX_FILE_SYSTEM_SIZE * sizeof(File *));
    fs->num_files = 0;
    fs->max_files = MAX_FILE_SYSTEM_SIZE;
}

int create_file(FileSystem *fs, char *name, char *content) {
    if (fs->num_files >= fs->max_files) {
        printf("Error: File system is full.\n");
        return -1;
    }

    File *f = (File *) malloc(sizeof(File));
    strcpy(f->name, name);
    strcpy(f->content, content);
    f->size = strlen(content);

    fs->files[fs->num_files] = f;
    fs->num_files++;

    printf("File '%s' created successfully.\n", name);
    return 0;
}

int read_file(FileSystem *fs, char *name) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            printf("File content: %s\n", fs->files[i]->content);
            return 0;
        }
    }

    printf("File not found.\n");
    return -1;
}

int delete_file(FileSystem *fs, char *name) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            free(fs->files[i]);
            fs->files[i] = NULL;
            fs->num_files--;

            printf("File '%s' deleted successfully.\n", name);
            return 0;
        }
    }

    printf("File not found.\n");
    return -1;
}

int main() {
    FileSystem fs;
    init_file_system(&fs);

    create_file(&fs, "test.txt", "Hello, world!");
    read_file(&fs, "test.txt");
    delete_file(&fs, "test.txt");

    return 0;
}