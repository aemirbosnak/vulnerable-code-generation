//Code Llama-13B DATASET v1.0 Category: Data recovery tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_FILENAME_SIZE 256
#define MAX_PATH_SIZE 1024

typedef struct {
    char filename[MAX_FILENAME_SIZE];
    char path[MAX_PATH_SIZE];
    bool is_dir;
    bool is_recovered;
} FileInfo;

void print_usage() {
    printf("Usage: data_recovery_tool <source_dir> <target_dir>\n");
}

void print_file_info(FileInfo* file) {
    printf("%s (%s) - %s\n", file->filename, file->path, file->is_recovered ? "recovered" : "not recovered");
}

void print_file_list(FileInfo* files, int num_files) {
    for (int i = 0; i < num_files; i++) {
        print_file_info(&files[i]);
    }
}

bool is_valid_file(const char* filename) {
    if (filename[0] == '.') {
        return false;
    }
    return true;
}

bool is_valid_directory(const char* dir) {
    struct stat st;
    if (stat(dir, &st) == 0 && S_ISDIR(st.st_mode)) {
        return true;
    }
    return false;
}

int count_files(const char* dir) {
    DIR* d;
    struct dirent* entry;
    int count = 0;
    d = opendir(dir);
    if (d) {
        while ((entry = readdir(d)) != NULL) {
            if (is_valid_file(entry->d_name)) {
                count++;
            }
        }
        closedir(d);
    }
    return count;
}

void get_file_list(const char* dir, FileInfo* files, int num_files) {
    DIR* d;
    struct dirent* entry;
    int i = 0;
    d = opendir(dir);
    if (d) {
        while ((entry = readdir(d)) != NULL) {
            if (is_valid_file(entry->d_name)) {
                strcpy(files[i].filename, entry->d_name);
                strcpy(files[i].path, dir);
                strcat(files[i].path, "/");
                strcat(files[i].path, files[i].filename);
                files[i].is_dir = false;
                files[i].is_recovered = false;
                i++;
            }
        }
        closedir(d);
    }
}

void get_dir_list(const char* dir, FileInfo* files, int num_files) {
    DIR* d;
    struct dirent* entry;
    int i = 0;
    d = opendir(dir);
    if (d) {
        while ((entry = readdir(d)) != NULL) {
            if (is_valid_directory(entry->d_name)) {
                strcpy(files[i].filename, entry->d_name);
                strcpy(files[i].path, dir);
                strcat(files[i].path, "/");
                strcat(files[i].path, files[i].filename);
                files[i].is_dir = true;
                files[i].is_recovered = false;
                i++;
            }
        }
        closedir(d);
    }
}

void recover_files(const char* source_dir, const char* target_dir) {
    int num_files = count_files(source_dir);
    FileInfo* files = (FileInfo*)malloc(num_files * sizeof(FileInfo));
    if (files == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    get_file_list(source_dir, files, num_files);
    get_dir_list(source_dir, files, num_files);

    for (int i = 0; i < num_files; i++) {
        if (!files[i].is_dir) {
            // recover file
            char* cmd = (char*)malloc(MAX_PATH_SIZE + 100);
            sprintf(cmd, "cp %s %s", files[i].path, target_dir);
            system(cmd);
            free(cmd);
            files[i].is_recovered = true;
        }
    }

    free(files);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    recover_files(argv[1], argv[2]);

    return 0;
}