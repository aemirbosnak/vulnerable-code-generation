//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

void print_directory(const char *path, int depth) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(path)) == NULL) {
        printf("Error: Failed to open directory\n");
        return;
    }

    while ((entry = readdir(dir))!= NULL) {
        const char *name = entry->d_name;
        int size = 0;

        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) {
            continue;
        }

        size = get_file_size(path, name);

        if (depth > 0) {
            printf("\n");
        }
        printf("  %*s %d bytes\n", depth * 4, name, size);
    }

    closedir(dir);
}

int get_file_size(const char *path, const char *file) {
    FILE *file_ptr;
    char buffer[1024];
    int size = 0;

    if ((file_ptr = fopen(path, "r")) == NULL) {
        return -1;
    }

    while (fgets(buffer, sizeof(buffer), file_ptr)!= NULL) {
        size += strlen(buffer);
    }

    fclose(file_ptr);

    return size;
}

int main() {
    const char *path = "/path/to/directory";
    int depth = 0;

    if (depth == 0) {
        printf("Enter directory depth (1 for root, 2 for subdirectories, etc.): ");
        scanf("%d", &depth);
    }

    print_directory(path, depth);

    return 0;
}