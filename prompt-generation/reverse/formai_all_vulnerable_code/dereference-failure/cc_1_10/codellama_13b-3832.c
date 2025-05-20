//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *name;
    char *path;
    char *extension;
    struct stat sb;
} file_info;

void print_file_info(file_info *file) {
    printf("Name: %s\n", file->name);
    printf("Path: %s\n", file->path);
    printf("Extension: %s\n", file->extension);
    printf("Size: %ld bytes\n", file->sb.st_size);
    printf("Created: %s", ctime(&file->sb.st_ctime));
    printf("Modified: %s", ctime(&file->sb.st_mtime));
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    file_info file;
    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) {
            file.name = ent->d_name;
            file.path = argv[1];
            file.extension = strrchr(file.name, '.');
            if (file.extension) {
                *file.extension = '\0';
                file.extension++;
            }
            stat(file.path, &file.sb);
            print_file_info(&file);
        }
    }

    closedir(dir);
    return 0;
}