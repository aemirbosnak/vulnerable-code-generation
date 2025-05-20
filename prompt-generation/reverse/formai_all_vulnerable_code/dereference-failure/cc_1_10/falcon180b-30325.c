//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>

#define SIZE_UNIT 1024

typedef struct {
    char *path;
    size_t size;
    size_t files;
    size_t dirs;
} dir_t;

void add_dir(dir_t *dir, const char *path) {
    dir->size += SIZE_UNIT;
    dir->files++;
    dir->dirs++;
}

void print_dir(const dir_t *dir, int indent) {
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    printf("%s (%zu bytes)\n", dir->path, dir->size);
}

void analyze_dir(const char *path, dir_t *dir) {
    DIR *d = opendir(path);
    if (d == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent *ent;
    while ((ent = readdir(d))!= NULL) {
        char *full_path = malloc(strlen(path) + strlen(ent->d_name) + 2);
        if (full_path == NULL) {
            perror("malloc");
            exit(1);
        }
        sprintf(full_path, "%s/%s", path, ent->d_name);

        struct statvfs sv;
        if (statvfs(full_path, &sv)!= 0) {
            perror("statvfs");
            exit(1);
        }

        if (ent->d_type == DT_DIR) {
            add_dir(dir, full_path);
            analyze_dir(full_path, dir);
        } else {
            add_dir(dir, full_path);
        }

        free(full_path);
    }

    closedir(d);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    dir_t dir;
    dir.path = argv[1];
    dir.size = 0;
    dir.files = 0;
    dir.dirs = 0;

    analyze_dir(argv[1], &dir);

    print_dir(&dir, 0);

    return 0;
}