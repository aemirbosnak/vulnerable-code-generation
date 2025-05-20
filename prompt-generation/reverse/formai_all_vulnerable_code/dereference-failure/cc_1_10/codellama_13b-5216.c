//Code Llama-13B DATASET v1.0 Category: File Synchronizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#define BUFFER_SIZE 4096

typedef struct FileInfo {
    char* name;
    char* path;
    struct stat st;
} FileInfo;

void getFileInfo(FileInfo* file) {
    file->name = basename(file->path);
    stat(file->path, &file->st);
}

void listDirectory(char* directory) {
    DIR* dir = opendir(directory);
    struct dirent* entry;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char* path = malloc(strlen(directory) + strlen(entry->d_name) + 2);
            sprintf(path, "%s/%s", directory, entry->d_name);
            listDirectory(path);
            free(path);
        } else {
            FileInfo file;
            file.path = malloc(strlen(directory) + strlen(entry->d_name) + 1);
            sprintf(file.path, "%s/%s", directory, entry->d_name);
            getFileInfo(&file);
            printf("%s: %ld bytes\n", file.name, file.st.st_size);
            free(file.path);
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    listDirectory(argv[1]);

    return 0;
}