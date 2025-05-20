//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 1024

struct file_info {
    char file_name[1024];
    char dest_name[1024];
    int is_dir;
};

void sync_files(char* source_dir, char* dest_dir) {
    DIR* dir;
    struct dirent* ent;
    dir = opendir(source_dir);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", source_dir);
        exit(1);
    }
    char path[1024];
    strcpy(path, source_dir);
    strcat(path, "/");
    while ((ent = readdir(dir))!= NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }
        strcat(path, ent->d_name);
        struct stat st;
        stat(path, &st);
        if (S_ISDIR(st.st_mode)) {
            strcpy(path, source_dir);
            strcat(path, "/");
            strcat(path, ent->d_name);
            strcat(path, "/");
            sync_files(path, dest_dir);
        } else {
            FILE* fp;
            fp = fopen(path, "r");
            if (fp == NULL) {
                printf("Error opening file: %s\n", path);
                exit(1);
            }
            fseek(fp, 0, SEEK_END);
            int size = ftell(fp);
            rewind(fp);
            char* buffer = malloc(size + 1);
            fread(buffer, size, 1, fp);
            fclose(fp);
            buffer[size] = '\0';
            strcpy(path, dest_dir);
            strcat(path, "/");
            strcat(path, ent->d_name);
            strcat(path, ".txt");
            fp = fopen(path, "w");
            if (fp == NULL) {
                printf("Error creating file: %s\n", path);
                exit(1);
            }
            fwrite(buffer, size, 1, fp);
            fclose(fp);
        }
    }
    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_directory dest_directory\n", argv[0]);
        exit(1);
    }
    sync_files(argv[1], argv[2]);
    return 0;
}