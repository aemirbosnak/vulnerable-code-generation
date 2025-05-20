//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILE_LEN 1024
#define MAX_DIR_LEN 1024
#define BUF_SIZE 1024

typedef struct {
    char filename[MAX_FILE_LEN];
    off_t size;
} file_t;

typedef struct {
    char dirname[MAX_DIR_LEN];
    off_t total_size;
    int num_files;
    file_t *files;
} dir_t;

void read_dir(const char *dir_path, dir_t *dir) {
    DIR *d;
    struct dirent *ent;
    d = opendir(dir_path);

    if (d!= NULL) {
        while ((ent = readdir(d))!= NULL) {
            if (ent->d_type == DT_REG || ent->d_type == DT_LNK) {
                strncpy(dir->files[dir->num_files].filename, ent->d_name, MAX_FILE_LEN - 1);
                dir->files[dir->num_files].size = ent->d_off;
                dir->num_files++;
            }
        }
        closedir(d);
    }
}

void print_dir(const char *dir_path, const dir_t *dir) {
    int i;
    printf("Directory: %s\n", dir_path);
    printf("Total size: %lld bytes\n", dir->total_size);
    printf("Number of files: %d\n", dir->num_files);
    printf("Files:\n");

    for (i = 0; i < dir->num_files; i++) {
        printf("%s (%lld bytes)\n", dir->files[i].filename, dir->files[i].size);
    }
}

int main(int argc, char *argv[]) {
    dir_t dir;
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    strncpy(dir.dirname, argv[1], MAX_DIR_LEN - 1);
    dir.total_size = 0;
    dir.num_files = 0;
    dir.files = malloc(sizeof(file_t) * MAX_FILE_LEN);

    read_dir(argv[1], &dir);
    print_dir(argv[1], &dir);

    free(dir.files);
    return 0;
}