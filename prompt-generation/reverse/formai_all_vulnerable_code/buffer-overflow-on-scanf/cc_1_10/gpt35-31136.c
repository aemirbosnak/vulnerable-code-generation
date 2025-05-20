//FormAI DATASET v1.0 Category: File Synchronizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>

#define MAX_PATH_LENGTH 200

bool is_dir(const char* path) {
    struct stat test_stat;
    if (stat(path, &test_stat) != 0) return false;
    return S_ISDIR(test_stat.st_mode);
}

void sync_files(const char* source_dir, const char* target_dir) {
    DIR* source = opendir(source_dir);
    if (source == NULL) {
        printf("\nCould not open source directory\n");
        exit(1);
    }
    DIR* target = opendir(target_dir);
    if (target == NULL) {
        printf("\nCould not open target directory\n");
        exit(1);
    }
    struct dirent* de;
    while ((de = readdir(source)) != NULL) {
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) continue;
        char source_path[MAX_PATH_LENGTH];
        char target_path[MAX_PATH_LENGTH];
        sprintf(source_path, "%s/%s", source_dir, de->d_name);
        sprintf(target_path, "%s/%s", target_dir, de->d_name);
        if (is_dir(source_path)) {
            sync_files(source_path, target_path);
        } else {
            FILE* source_file = fopen(source_path, "rb");
            if (source_file == NULL) {
                printf("\nCould not open %s for reading\n", source_path);
                exit(1);
            }
            FILE* target_file = fopen(target_path, "rb");
            if (target_file == NULL) {
                printf("\nCould not open %s for writing\n", target_path);
                fclose(source_file);
                exit(1);
            }
            fseek(source_file, 0, SEEK_END);
            long source_size = ftell(source_file);
            fseek(source_file, 0, SEEK_SET);
            fseek(target_file, 0, SEEK_END);
            long target_size = ftell(target_file);
            fseek(target_file, 0, SEEK_SET);
            if (source_size > target_size) {
                char* buffer = (char*)malloc(source_size);
                fread(buffer, 1, source_size, source_file);
                fclose(source_file);
                fclose(target_file);
                target_file = fopen(target_path, "wb");
                if (target_file == NULL) {
                    printf("\nCould not open %s for writing\n", target_path);
                    free(buffer);
                    exit(1);
                }
                fwrite(buffer, 1, source_size, target_file);
                printf("\nSyncing %s\n", target_path);
                free(buffer);
            }
            fclose(source_file);
            fclose(target_file);
        }
    }
    closedir(source);
    closedir(target);
}

int main() {
    printf("Welcome to C File Synchronizer!\n\n");
    char source_dir[MAX_PATH_LENGTH], target_dir[MAX_PATH_LENGTH];
    printf("Enter source directory path: ");
    scanf("%s", source_dir);
    printf("Enter target directory path: ");
    scanf("%s", target_dir);
    sync_files(source_dir, target_dir);
    printf("\nSync successful!\n");
    return 0;
}