//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

#define MAX_DIR_SIZE 1024
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_DIR_SIZE];
    time_t mtime;
    size_t size;
    int is_file;
} dir_entry_t;

void print_entry(const dir_entry_t *entry) {
    printf("%-40s %10ld %10zu\n", entry->name, entry->mtime, entry->size);
}

void scan_dir(const char *path, int depth) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror(path);
        return;
    }

    struct dirent *ent;
    int count = 0;
    while ((ent = readdir(dir))!= NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_DIR_SIZE];
        snprintf(full_path, MAX_DIR_SIZE, "%s/%s", path, ent->d_name);

        struct stat st;
        if (stat(full_path, &st) == -1) {
            perror(full_path);
            continue;
        }

        dir_entry_t entry;
        strncpy(entry.name, ent->d_name, MAX_DIR_SIZE - 1);
        entry.name[MAX_DIR_SIZE - 1] = '\0';
        entry.mtime = st.st_mtime;
        entry.size = st.st_size;
        entry.is_file = S_ISREG(st.st_mode);

        print_entry(&entry);
        count++;
    }

    closedir(dir);

    if (depth > 0) {
        char **files = NULL;
        int num_files = scandir(path, &files, NULL, NULL);
        if (num_files >= 0) {
            for (int i = 0; i < num_files; i++) {
                scan_dir(files[i], depth - 1);
            }
            for (int i = 0; i < num_files; i++) {
                free(files[i]);
            }
            free(files);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [path]\n", argv[0]);
        return 1;
    }

    scan_dir(argv[1], -1);

    return 0;
}