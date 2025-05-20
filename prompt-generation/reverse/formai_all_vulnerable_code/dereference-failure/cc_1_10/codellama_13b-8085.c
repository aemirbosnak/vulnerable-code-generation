//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define BUFFER_SIZE 1024

struct file_data {
    char* name;
    time_t last_modified;
};

int file_exists(const char* path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        return 1;
    }
    return 0;
}

int is_file(const char* path) {
    struct stat st;
    if (stat(path, &st) == 0 && S_ISREG(st.st_mode)) {
        return 1;
    }
    return 0;
}

void backup_file(const char* file_path, const char* backup_path) {
    FILE* file = fopen(file_path, "rb");
    FILE* backup = fopen(backup_path, "wb");
    char buffer[BUFFER_SIZE];
    while (fread(buffer, 1, BUFFER_SIZE, file) > 0) {
        fwrite(buffer, 1, BUFFER_SIZE, backup);
    }
    fclose(file);
    fclose(backup);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <source_dir> <backup_dir>\n", argv[0]);
        return 1;
    }

    char* source_dir = argv[1];
    char* backup_dir = argv[2];

    DIR* dir = opendir(source_dir);
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (is_file(entry->d_name)) {
            char* file_path = malloc(strlen(source_dir) + strlen(entry->d_name) + 2);
            sprintf(file_path, "%s/%s", source_dir, entry->d_name);
            char* backup_path = malloc(strlen(backup_dir) + strlen(entry->d_name) + 2);
            sprintf(backup_path, "%s/%s", backup_dir, entry->d_name);
            backup_file(file_path, backup_path);
            free(file_path);
            free(backup_path);
        }
    }
    closedir(dir);

    return 0;
}