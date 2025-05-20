//FormAI DATASET v1.0 Category: File system simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Directory {
    char* name;
    struct Directory* parent;
    struct File* files;
    struct Directory* subdirs;
} Directory;

typedef struct File {
    char* name;
    char* content;
    struct Directory* parent;
    struct File* next;
} File;

File* create_file(char* name, char* content, Directory* parent) {
    File* file = (File*) malloc(sizeof(File));
    file->name = name;
    file->content = content;
    file->parent = parent;
    file->next = NULL;
    return file;
}

Directory* create_dir(char* name, Directory* parent) {
    Directory* dir = (Directory*) malloc(sizeof(Directory));
    dir->name = name;
    dir->parent = parent;
    dir->files = NULL;
    dir->subdirs = NULL;
    return dir;
}

File* find_file(char* name, Directory* dir) {
    if (dir == NULL) {
        return NULL;
    }
    File* file = dir->files;
    while (file != NULL) {
        if (strcmp(file->name, name) == 0) {
            return file;
        }
        file = file->next;
    }
    Directory* subdir = dir->subdirs;
    while (subdir != NULL) {
        file = find_file(name, subdir);
        if (file != NULL) {
            return file;
        }
        subdir = subdir->subdirs;
    }
    return NULL;
}

Directory* find_dir(char* path, Directory* curr_dir) {
    if (strcmp(path, "/") == 0) {
        return curr_dir;
    }
    char* token = strtok(path, "/");
    Directory* dir = curr_dir;
    while (token != NULL) {
        Directory* subdir = dir->subdirs;
        while (subdir != NULL) {
            if (strcmp(subdir->name, token) == 0) {
                dir = subdir;
                break;
            }
            subdir = subdir->subdirs;
        }
        token = strtok(NULL, "/");
    }
    return dir;
}

void mkdir(char* path, Directory* curr_dir) {
    char* name = strtok(path, "/");
    Directory* dir = curr_dir;
    while (name != NULL) {
        Directory* subdir = dir->subdirs;
        while (subdir != NULL) {
            if (strcmp(subdir->name, name) == 0) {
                dir = subdir;
                break;
            }
            subdir = subdir->subdirs;
        }
        if (subdir == NULL) {
            subdir = create_dir(name, dir);
            if (dir->subdirs == NULL) {
                dir->subdirs = subdir;
            } else {
                Directory* last_subdir = dir->subdirs;
                while (last_subdir->subdirs != NULL) {
                    last_subdir = last_subdir->subdirs;
                }
                last_subdir->subdirs = subdir;
            }
            // Print message
            printf("Created directory %s.\n", subdir->name);
        }
        name = strtok(NULL, "/");
    }
}

void touch(char* path, Directory* curr_dir) {
    char* file_name = strrchr(path, '/') + 1;
    char* dir_path = strdup(path);
    dir_path[strlen(dir_path) - strlen(file_name) - 1] = '\0';
    Directory* dir = find_dir(dir_path, curr_dir);
    if (dir == NULL) {
        printf("Error: Directory does not exist.\n");
        return;
    }
    File* file = find_file(file_name, dir);
    if (file == NULL) {
        file = create_file(file_name, "", dir);
        if (dir->files == NULL) {
            dir->files = file;
        } else {
            File* last_file = dir->files;
            while (last_file->next != NULL) {
                last_file = last_file->next;
            }
            last_file->next = file;
        }
        // Print message
        printf("Created file %s.\n", file->name);
    } else {
        printf("Error: File already exists.\n");
    }
}

void print_content(char* path, Directory* curr_dir) {
    char* file_name = strrchr(path, '/') + 1;
    char* dir_path = strdup(path);
    dir_path[strlen(dir_path) - strlen(file_name) - 1] = '\0';
    Directory* dir = find_dir(dir_path, curr_dir);
    if (dir == NULL) {
        printf("Error: Directory does not exist.\n");
        return;
    }
    File* file = find_file(file_name, dir);
    if (file == NULL) {
        printf("Error: File does not exist.\n");
    } else {
        printf("%s\n", file->content);
    }
}

void ls(Directory* curr_dir) {
    printf(".\n");
    printf("..\n");
    File* file = curr_dir->files;
    while (file != NULL) {
        printf("%s\n", file->name);
        file = file->next;
    }
    Directory* subdir = curr_dir->subdirs;
    while (subdir != NULL) {
        printf("%s/\n", subdir->name);
        subdir = subdir->subdirs;
    }
}

int main() {
    Directory* root_dir = create_dir("", NULL);
    char input[100];
    while (1) {
        printf("> ");
        fgets(input, 100, stdin);
        input[strlen(input) - 1] = '\0';
        char* token = strtok(input, " ");
        if (strcmp(token, "mkdir") == 0) {
            char* path = strtok(NULL, " ");
            mkdir(path, root_dir);
        } else if (strcmp(token, "touch") == 0) {
            char* path = strtok(NULL, " ");
            touch(path, root_dir);
        } else if (strcmp(token, "cat") == 0) {
            char* path = strtok(NULL, " ");
            print_content(path, root_dir);
        } else if (strcmp(token, "ls") == 0) {
            ls(root_dir);
        } else if (strcmp(token, "exit") == 0) {
            exit(0);
        } else {
            printf("Error: Command not recognized.\n");
        }
    }
    return 0;
}