#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void classify_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
    fclose(file);

    if (bytes_read == 0) {
        printf("%s: Empty file\n", filename);
        return;
    }

    // Example magic numbers for demonstration purposes
    if (buffer[0] == 'P' && buffer[1] == 'N' && buffer[2] == 'G') {
        printf("%s: PNG image\n", filename);
    } else if (buffer[0] == '\xFF' && buffer[1] == '\xD8' && buffer[2] == '\xFF') {
        printf("%s: JPEG image\n", filename);
    } else if (buffer[0] == 'M' && buffer[1] == 'Z') {
        printf("%s: Windows executable\n", filename);
    } else {
        printf("%s: Unknown type\n", filename);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    DIR *dir;
    struct dirent *entry;

    dir = opendir(argv[1]);
    if (!dir) {
        perror("Error opening directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char path[BUFFER_SIZE];
            snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);
            classify_file(path);
        }
    }

    closedir(dir);
    return 0;
}
