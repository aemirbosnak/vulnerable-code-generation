//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_DIR_DEPTH 1000

typedef struct {
    char path[MAX_DIR_DEPTH];
    size_t size;
    struct dirent *d;
} DirEntry;

void print_dir_entries(DirEntry *entries, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s %zu bytes\n", entries[i].path, entries[i].size);
    }
}

void get_dir_entries(const char *path, DirEntry *entries, int depth) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    struct dirent *d;
    while ((d = readdir(dir))!= NULL) {
        if (d->d_type == DT_DIR) {
            if (depth < MAX_DIR_DEPTH) {
                strcat(entries[depth].path, "/");
                strcat(entries[depth].path, d->d_name);
                get_dir_entries(entries[depth].path, entries, depth + 1);
            }
        } else {
            struct stat st;
            stat(entries[depth].path, &st);
            entries[depth].size = st.st_size;
        }
        depth++;
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[MAX_DIR_DEPTH];
    strcpy(path, argv[1]);

    DirEntry entries[MAX_DIR_DEPTH];
    int count = 0;

    get_dir_entries(path, entries, 0);

    print_dir_entries(entries, count);

    return 0;
}