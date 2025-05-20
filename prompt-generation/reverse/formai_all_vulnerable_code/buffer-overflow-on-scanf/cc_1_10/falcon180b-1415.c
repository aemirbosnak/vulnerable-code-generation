//Falcon-180B DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_LINE_SIZE 1024
#define MAX_DIR_SIZE 4096

typedef struct {
    char *name;
    int size;
    struct dirent *next;
} dir_entry_t;

void print_dir_entries(dir_entry_t *entries) {
    while (entries!= NULL) {
        printf("%s (%d bytes)\n", entries->name, entries->size);
        entries = entries->next;
    }
}

void free_dir_entries(dir_entry_t *entries) {
    while (entries!= NULL) {
        free(entries->name);
        free(entries);
        entries = entries->next;
    }
}

void read_dir_recursive(const char *dir_name, dir_entry_t **entries) {
    DIR *dir;
    struct dirent *ent;
    dir_entry_t *new_entries = NULL;

    dir = opendir(dir_name);
    if (dir == NULL) {
        printf("Error reading directory: %s\n", dir_name);
        return;
    }

    while ((ent = readdir(dir))!= NULL) {
        char path[MAX_DIR_SIZE];
        sprintf(path, "%s/%s", dir_name, ent->d_name);

        if (ent->d_type == DT_DIR) {
            read_dir_recursive(path, &new_entries);
        } else {
            dir_entry_t *entry = malloc(sizeof(dir_entry_t));
            entry->name = strdup(ent->d_name);
            entry->size = ent->d_reclen;
            entry->next = new_entries;
            new_entries = entry;
        }
    }

    closedir(dir);

    *entries = new_entries;
}

int main() {
    char dir_name[MAX_LINE_SIZE];
    printf("Enter directory name: ");
    scanf("%s", dir_name);

    dir_entry_t *entries = NULL;
    read_dir_recursive(dir_name, &entries);
    print_dir_entries(entries);
    free_dir_entries(entries);

    return 0;
}