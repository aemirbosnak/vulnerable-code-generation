//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_FILE_NAME_LENGTH 1024

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    off_t size;
} File;

void print_files(File* files, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s - %lld bytes\n", files[i].name, files[i].size);
    }
}

int main() {
    char path[MAX_FILE_NAME_LENGTH];
    printf("Enter directory path: ");
    scanf("%s", path);

    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error: %s is not a directory\n", path);
        return 1;
    }

    File* files = NULL;
    int count = 0;

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) { // Regular file
            char file_path[MAX_FILE_NAME_LENGTH];
            sprintf(file_path, "%s/%s", path, ent->d_name);

            struct statvfs fs;
            statvfs(file_path, &fs);

            File file = {
               .name = ent->d_name,
               .size = fs.f_blocks * fs.f_frsize
            };

            files = realloc(files, sizeof(File) * ++count);
            files[count - 1] = file;
        }
    }

    closedir(dir);

    print_files(files, count);

    free(files);

    return 0;
}