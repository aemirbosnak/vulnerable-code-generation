//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *name;
    off_t size;
} File;

void read_directory(const char *path, void (*callback)(File *)) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", path);
        return;
    }

    char buffer[BUFFER_SIZE];
    while (readdir(dir)!= NULL) {
        struct dirent *entry = readdir(dir);
        if (entry == NULL) {
            break;
        }

        File file;
        file.name = strdup(entry->d_name);
        file.size = 0;

        char path_buffer[BUFFER_SIZE];
        sprintf(path_buffer, "%s/%s", path, entry->d_name);

        struct stat stat_buf;
        if (stat(path_buffer, &stat_buf) == 0) {
            file.size = stat_buf.st_size;
        }

        callback(&file);
    }

    closedir(dir);
}

void print_file(File *file) {
    printf("%s (%zu bytes)\n", file->name, file->size);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    read_directory(argv[1], print_file);

    return 0;
}