//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *name;
    char *path;
    int size;
    int type;
} file_t;

file_t *files = NULL;
int num_files = 0;

void add_file(const char *name, const char *path, int size, int type) {
    file_t *file = malloc(sizeof(file_t));

    file->name = strdup(name);
    file->path = strdup(path);
    file->size = size;
    file->type = type;

    files = realloc(files, sizeof(file_t) * ++num_files);
    files[num_files - 1] = *file;
    free(file);
}

void print_files() {
    for (int i = 0; i < num_files; i++) {
        printf("%s\t%s\t%d\t%d\n", files[i].name, files[i].path, files[i].size, files[i].type);
    }
}

int main() {
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, stdin)!= NULL) {
        char *line = strtok(buffer, "\n");
        char *name = strtok(line, "\t");
        char *path = strtok(NULL, "\t");
        int size = atoi(strtok(NULL, "\t"));
        int type = atoi(strtok(NULL, "\t"));

        add_file(name, path, size, type);
    }

    print_files();

    return 0;
}