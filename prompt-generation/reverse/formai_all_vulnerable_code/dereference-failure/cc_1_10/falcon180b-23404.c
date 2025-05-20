//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILE_NAME_LENGTH 512
#define MAX_DIRECTORIES 1000

typedef struct directory {
    char name[MAX_FILE_NAME_LENGTH];
    int num_files;
    int num_directories;
    int total_size;
} Directory;

void initialize_directory(Directory* dir) {
    dir->num_files = 0;
    dir->num_directories = 0;
    dir->total_size = 0;
}

void add_file(Directory* dir, char* name, int size) {
    dir->num_files++;
    dir->total_size += size;
}

void add_directory(Directory* dir, char* name) {
    dir->num_directories++;
}

void print_directory(Directory* dir) {
    printf("Directory: %s\n", dir->name);
    printf("Number of files: %d\n", dir->num_files);
    printf("Number of directories: %d\n", dir->num_directories);
    printf("Total size: %d bytes\n\n", dir->total_size);
}

void analyze_directory(char* path, Directory* dir) {
    DIR* d;
    struct dirent* dirp;
    d = opendir(path);

    if (d) {
        while ((dirp = readdir(d))!= NULL) {
            if (dirp->d_type == DT_DIR) {
                char* full_path = malloc(strlen(path) + strlen(dirp->d_name) + 2);
                strcpy(full_path, path);
                strcat(full_path, "/");
                strcat(full_path, dirp->d_name);

                if (dir->num_directories < MAX_DIRECTORIES) {
                    Directory* subdir = malloc(sizeof(Directory));
                    initialize_directory(subdir);
                    dir->num_directories++;
                    add_directory(dir, dirp->d_name);
                    analyze_directory(full_path, subdir);
                    print_directory(subdir);
                    free(subdir);
                }
            } else {
                add_file(dir, dirp->d_name, dirp->d_off);
            }
        }
        closedir(d);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    Directory dir;
    initialize_directory(&dir);

    analyze_directory(argv[1], &dir);

    return 0;
}