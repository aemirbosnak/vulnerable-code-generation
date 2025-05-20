//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATH 1024

struct node {
    char name[MAX_PATH];
    struct node *next;
    long long size;
};

struct node *head = NULL;

void add_node(char *name, long long size) {
    struct node *new_node = malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    new_node->size = size;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list() {
    struct node *temp = head;
    printf("Directory Size Report\n\n");
    printf("Directory\t\tSize\n");
    while (temp!= NULL) {
        printf("%s\t\t%lld bytes\n", temp->name, temp->size);
        temp = temp->next;
    }
}

long long get_directory_size(char *dir_name) {
    DIR *dp;
    struct dirent *dir;
    long long size = 0;

    dp = opendir(dir_name);

    if (dp!= NULL) {
        while ((dir = readdir(dp))!= NULL) {
            if (strcmp(dir->d_name, ".")!= 0 && strcmp(dir->d_name, "..")!= 0) {
                char path[MAX_PATH];
                sprintf(path, "%s/%s", dir_name, dir->d_name);
                if (is_directory(path)) {
                    size += get_directory_size(path);
                } else {
                    struct stat st;
                    stat(path, &st);
                    size += st.st_size;
                }
            }
        }
        closedir(dp);
    }

    return size;
}

int is_directory(char *path) {
    struct stat st;
    stat(path, &st);
    return S_ISDIR(st.st_mode);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }

    char path[MAX_PATH];
    sprintf(path, "%s", argv[1]);

    long long size = get_directory_size(path);
    add_node(path, size);

    print_list();

    return 0;
}