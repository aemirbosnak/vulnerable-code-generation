//Falcon-180B DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_PATH 1024

int create_file(const char* path) {
    FILE* file = fopen(path, "w");
    if (file == NULL) {
        int error_code = errno;
        fprintf(stderr, "Error creating file %s: %s\n", path, strerror(error_code));
        return -1;
    }
    fclose(file);
    return 0;
}

int read_file(const char* path) {
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        int error_code = errno;
        fprintf(stderr, "Error reading file %s: %s\n", path, strerror(error_code));
        return -1;
    }
    fclose(file);
    return 0;
}

int write_to_file(const char* path, const char* data) {
    FILE* file = fopen(path, "w");
    if (file == NULL) {
        int error_code = errno;
        fprintf(stderr, "Error writing to file %s: %s\n", path, strerror(error_code));
        return -1;
    }
    fprintf(file, "%s", data);
    fclose(file);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return -1;
    }

    const char* file_path = argv[1];
    char buffer[MAX_PATH];
    int file_exists = 0;

    if (create_file(file_path) == -1) {
        return -1;
    }

    if (read_file(file_path) == -1) {
        return -1;
    }

    strcpy(buffer, "Hello, world!");
    if (write_to_file(file_path, buffer) == -1) {
        return -1;
    }

    return 0;
}