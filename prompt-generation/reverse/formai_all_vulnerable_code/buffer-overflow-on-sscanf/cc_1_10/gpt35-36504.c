//FormAI DATASET v1.0 Category: File system simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

struct File {
    char name[50];
    int size;
};

struct Directory {
    char name[50];
    int file_count;
    struct File files[MAX_FILES];
};

struct FileSystem {
    struct Directory root;
    int dir_count;
    struct Directory *dirs[MAX_FILES];
};

void print_help() {
    printf("Usage: \n");
    printf("1. mkdir [dir] : Create a new directory\n");
    printf("2. ls : Show all files and directories in current directory\n");
    printf("3. touch [file] [size] : Create a new file with the specified size\n");
    printf("4. cd [dir] : Change to the specified directory\n");
    printf("5. rm [file] : Remove the specified file\n");
    printf("6. rmdir [dir] : Remove the specified directory and all its contents\n");
    printf("7. exit : Exit the program\n");
}

void add_directory(struct FileSystem *fs, struct Directory *dir) {
    if (fs->dir_count < MAX_FILES) {
        fs->dirs[fs->dir_count] = dir;
        fs->dir_count++;
    }
}

void remove_directory(struct FileSystem *fs, struct Directory *dir) {
    int i;
    for (i = 0; i < fs->dir_count; i++) {
        if (fs->dirs[i] == dir) {
            memmove(fs->dirs + i, fs->dirs + i + 1, (fs->dir_count - i - 1) * sizeof(fs->dirs[i]));
            fs->dir_count--;
            break;
        }
    }
}

struct Directory *find_directory(struct FileSystem *fs, char *name) {
    int i;
    for (i = 0; i < fs->dir_count; i++) {
        if (strcmp(fs->dirs[i]->name, name) == 0) {
            return fs->dirs[i];
        }
    }
    return NULL;
}

void add_file(struct Directory *dir, char *name, int size) {
    if (dir->file_count < MAX_FILES) {
        struct File file = { .size = size };
        strcpy(file.name, name);
        dir->files[dir->file_count] = file;
        dir->file_count++;
    }
}

void remove_file(struct Directory *dir, char *name) {
    int i;
    for (i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            memmove(dir->files + i, dir->files + i + 1, (dir->file_count - i - 1) * sizeof(dir->files[i]));
            dir->file_count--;
            break;
        }
    }
}

void print_directory(struct Directory *dir) {
    printf("Directory: %s\n", dir->name);
    int i;
    for (i = 0; i < dir->file_count; i++) {
        printf("  %s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }
}

int main() {
    struct FileSystem fs = { .root = { .name = "/", .file_count = 0 }, .dir_count = 0 };
    add_directory(&fs, &fs.root);

    char cmd[100];
    char arg1[50];
    char arg2[50];

    struct Directory *current_dir = &fs.root;

    while (1) {
        printf("%s> ", current_dir->name);
        fgets(cmd, 100, stdin);
        cmd[strlen(cmd) - 1] = '\0';

        if (strcmp(cmd, "exit") == 0) {
            break;
        } else if (strcmp(cmd, "ls") == 0) {
            print_directory(current_dir);
        } else if (sscanf(cmd, "mkdir %s", arg1) == 1) {
            struct Directory *dir = malloc(sizeof(struct Directory));
            strcpy(dir->name, arg1);
            dir->file_count = 0;
            add_directory(&fs, dir);
            printf("Directory created: %s\n", arg1);
        } else if (sscanf(cmd, "touch %s %s", arg1, arg2) == 2) {
            int size = atoi(arg2);
            if (size < 0) {
                printf("Invalid size\n");
            } else {
                add_file(current_dir, arg1, size);
                printf("File created: %s\n", arg1);
            }
        } else if (sscanf(cmd, "cd %s", arg1) == 1) {
            struct Directory *dir = find_directory(&fs, arg1);
            if (dir == NULL) {
                printf("Directory not found: %s\n", arg1);
            } else {
                current_dir = dir;
            }
        } else if (sscanf(cmd, "rm %s", arg1) == 1) {
            remove_file(current_dir, arg1);
            printf("File deleted: %s\n", arg1);
        } else if (sscanf(cmd, "rmdir %s", arg1) == 1) {
            struct Directory *dir = find_directory(&fs, arg1);
            if (dir == NULL) {
                printf("Directory not found: %s\n", arg1);
            } else {
                remove_directory(&fs, dir);
            }
        } else {
            print_help();
        }
    }

    return 0;
}