#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void scan_directory(const char *path) {
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

        if (stat(full_path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                scan_directory(full_path);
            }
        } else {
            // Vulnerability: Memory allocation failure is not checked
            unsigned char buffer[16];
            FILE *file = fopen(full_path, "rb");
            if (file) {
                fread(buffer, 1, sizeof(buffer), file);
                fclose(file);
                printf("File: %s\n", full_path);
            }
        }
    }

    closedir(dir);
}

int main() {
    scan_directory(".");
    return 0;
}
