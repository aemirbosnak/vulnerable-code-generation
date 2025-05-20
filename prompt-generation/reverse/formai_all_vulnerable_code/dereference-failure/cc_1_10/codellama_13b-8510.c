//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

struct dir_entry {
    char *name;
    int size;
    struct dir_entry *next;
};

struct dir_entry *dir_list;

void add_dir(char *name, int size) {
    struct dir_entry *new_entry = malloc(sizeof(struct dir_entry));
    new_entry->name = name;
    new_entry->size = size;
    new_entry->next = dir_list;
    dir_list = new_entry;
}

void print_dir_list() {
    struct dir_entry *current = dir_list;
    while (current != NULL) {
        printf("%s: %d bytes\n", current->name, current->size);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    struct dirent *entry;
    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char *name = entry->d_name;
            if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) {
                continue;
            }
            int size = 0;
            struct dirent *sub_entry;
            DIR *sub_dir = opendir(entry->d_name);
            if (sub_dir == NULL) {
                perror("opendir");
                continue;
            }
            while ((sub_entry = readdir(sub_dir)) != NULL) {
                size += sub_entry->d_reclen;
            }
            closedir(sub_dir);
            add_dir(name, size);
        }
    }
    closedir(dir);

    print_dir_list();

    return 0;
}