#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 1024

void classify_file(const char *path) {
    FILE *file = fopen(path, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
    fclose(file);

    if (bytes_read <= 0) {
        fprintf(stderr, "Error reading file: %s\n", path);
        return;
    }

    // Placeholder for actual magic number comparison logic
    if (buffer[0] == 'P' && buffer[1] == 'N' && buffer[2] == 'G') {
        printf("%s is a PNG image.\n", path);
    } else if (buffer[0] == '\xFF' && buffer[1] == '\xD8' && buffer[2] == '\xFF') {
        printf("%s is a JPEG image.\n", path);
    } else {
        printf("%s has an unknown file type.\n", path);
    }
}

void traverse_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[BUFFER_SIZE];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            traverse_directory(full_path);
        } else if (entry->d_type == DT_REG) {
            classify_file(full_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    traverse_directory(argv[1]);

    return EXIT_SUCCESS;
}
