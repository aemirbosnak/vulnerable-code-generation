//Falcon-180B DATASET v1.0 Category: File handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_FILE_NAME_LENGTH 20

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    FILE *file;
} FILE_HANDLE;

FILE_HANDLE *open_file(char *filename) {
    FILE_HANDLE *handle = malloc(sizeof(FILE_HANDLE));
    if (handle == NULL) {
        printf("Error: could not allocate memory for file handle\n");
        exit(1);
    }
    strcpy(handle->name, filename);
    handle->file = fopen(filename, "r");
    if (handle->file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }
    return handle;
}

void close_file(FILE_HANDLE *handle) {
    fclose(handle->file);
    free(handle);
}

int read_line(FILE_HANDLE *handle, char *buffer) {
    char c;
    int i = 0;
    while ((c = fgetc(handle->file))!= EOF) {
        if (i >= MAX_LINE_LENGTH - 1) {
            printf("Error: line too long, truncated\n");
            break;
        }
        buffer[i++] = c;
        if (c == '\n') {
            buffer[i] = '\0';
            break;
        }
    }
    return i;
}

int main() {
    FILE_HANDLE *handle = open_file("example.txt");
    if (handle == NULL) {
        return 1;
    }
    char buffer[MAX_LINE_LENGTH];
    while (read_line(handle, buffer) > 0) {
        printf("%s", buffer);
    }
    close_file(handle);
    return 0;
}