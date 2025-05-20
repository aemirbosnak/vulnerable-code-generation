//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

typedef struct {
    char name[MAX_PATH];
    int is_file;
} entry_t;

entry_t *entries = NULL;
int num_entries = 0;

void add_entry(const char *path, int is_file) {
    entry_t *new_entry = malloc(sizeof(entry_t));
    if (new_entry == NULL) {
        fprintf(stderr, "Error: out of memory\n");
        exit(1);
    }
    strcpy(new_entry->name, path);
    new_entry->is_file = is_file;
    entries = realloc(entries, sizeof(entry_t) * ++num_entries);
    entries[num_entries - 1] = *new_entry;
    free(new_entry);
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s%c", entries[i].name, i < num_entries - 1? ',' : '\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [path]\n", argv[0]);
        exit(1);
    }

    char path[MAX_PATH];
    strcpy(path, argv[1]);
    path[strlen(path) - 1] = '/';

    DIR *dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Error: could not open directory '%s'\n", path);
        exit(1);
    }

    struct dirent *dent;
    while ((dent = readdir(dir))!= NULL) {
        if (dent->d_type == DT_DIR) {
            char *subpath = malloc(strlen(path) + strlen(dent->d_name) + 2);
            if (subpath == NULL) {
                fprintf(stderr, "Error: out of memory\n");
                exit(1);
            }
            strcpy(subpath, path);
            strcat(subpath, dent->d_name);
            strcat(subpath, "/");
            add_entry(subpath, 0);
            free(subpath);
        } else if (dent->d_type == DT_REG) {
            add_entry(dent->d_name, 1);
        }
    }

    closedir(dir);

    print_entries();

    return 0;
}