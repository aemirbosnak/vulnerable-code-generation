#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 1024

void classify_files(const char *dir_path) {
    DIR *dir;
    struct dirent *entry;
    char path[BUFFER_SIZE];

    if ((dir = opendir(dir_path)) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            classify_files(path);
        } else {
            FILE *file = fopen(path, "rb");
            if (file == NULL) {
                perror("fopen");
                continue;
            }

            unsigned char buffer[8];
            size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
            fclose(file);

            if (bytes_read > 0) {
                printf("File: %s\n", path);
                // Add your magic number classification logic here
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    classify_files(argv[1]);

    return EXIT_SUCCESS;
}
