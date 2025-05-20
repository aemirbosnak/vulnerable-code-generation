#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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
        struct stat st;
        if (stat(full_path, &st) == -1) {
            perror("stat");
            continue;
        }
        if (S_ISDIR(st.st_mode)) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                scan_directory(full_path);
            }
        } else {
            int fd = open(full_path, O_RDONLY);
            if (fd == -1) {
                perror("open");
                continue;
            }
            unsigned char buffer[8];
            ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
            close(fd);
            if (bytes_read > 0) {
                // Intentional dereference failure vulnerability
                switch (buffer[0]) {
                    case 0x89:
                        printf("%s is a PNG file\n", full_path);
                        break;
                    case 0xFF:
                        printf("%s is a JPEG file\n", full_path);
                        break;
                    default:
                        printf("%s has an unknown file type\n", full_path);
                        break;
                }
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    scan_directory(argv[1]);
    return 0;
}
