//Falcon-180B DATASET v1.0 Category: File handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char* filename;
    FILE* file;
} FileHandle;

FileHandle* file_open(char* filename, char* mode) {
    FileHandle* fh = (FileHandle*)malloc(sizeof(FileHandle));
    fh->filename = strdup(filename);
    fh->file = fopen(filename, mode);
    if (fh->file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    return fh;
}

void file_close(FileHandle* fh) {
    if (fclose(fh->file)!= 0) {
        printf("Error closing file %s\n", fh->filename);
        exit(1);
    }
    free(fh->filename);
    free(fh);
}

char* file_read(FileHandle* fh) {
    char* buffer = (char*)malloc(1024*sizeof(char));
    char* result = fgets(buffer, 1024, fh->file);
    if (result == NULL) {
        printf("Error reading from file %s\n", fh->filename);
        exit(1);
    }
    return result;
}

void file_write(FileHandle* fh, char* data) {
    if (fputs(data, fh->file)!= 0) {
        printf("Error writing to file %s\n", fh->filename);
        exit(1);
    }
}

int main() {
    char* filename = "example.txt";
    FileHandle* fh = file_open(filename, "w");
    file_write(fh, "Hello, world!\n");
    file_close(fh);

    fh = file_open(filename, "r");
    char* line = file_read(fh);
    while (line!= NULL) {
        printf("%s", line);
        line = file_read(fh);
    }
    file_close(fh);
    return 0;
}