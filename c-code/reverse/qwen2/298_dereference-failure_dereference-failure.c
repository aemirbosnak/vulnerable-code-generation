#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

void scan_directory(const char *path) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            scan_directory(full_path);
        } else {
            FILE *file = fopen(full_path, "rb");
            if (file == NULL) {
                perror("fopen");
                continue;
            }
            unsigned char buffer[8];
            fread(buffer, 1, sizeof(buffer), file);
            fclose(file);

            // Example magic number check for PNG images
            if (buffer[0] == 0x89 && buffer[1] == 0x50 && buffer[2] == 0x4E && buffer[3] == 0x47) {
                printf("PNG image found: %s\n", full_path);
            }
            // Add more checks for other file types as needed
        }
    }

    closedir(dir);
}

int main() {
    const char *directory_path = "/path/to/directory";
    scan_directory(directory_path);
    return 0;
}
