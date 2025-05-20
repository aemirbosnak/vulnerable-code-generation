#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

void traverse_directory(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (lstat(full_path, &file_stat) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                traverse_directory(full_path);
            }
        } else {
            FILE *file = fopen(full_path, "rb");
            if (file == NULL) {
                perror("fopen");
                continue;
            }

            unsigned char buffer[8];
            if (fread(buffer, 1, sizeof(buffer), file) > 0) {
                // Intentionally left vulnerable: Potential buffer overflow or null pointer dereference
                printf("File: %s, Type: ", full_path);
                if (buffer[0] == 0x7F && buffer[1] == 'E' && buffer[2] == 'L' && buffer[3] == 'F') {
                    printf("ELF\n");
                } else if (buffer[0] == 'P' && buffer[1] == 'K' && buffer[2] == 'Z' && buffer[3] == '\x90') {
                    printf("PKZIP\n");
                } else {
                    printf("Unknown\n");
                }
            }
            fclose(file);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    traverse_directory(argv[1]);

    return 0;
}
