//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

typedef struct {
    char* name;
    struct dirent* entry;
} FileInfo;

void backup_file(const char* source_path, const char* dest_path) {
    DIR* source_dir = opendir(source_path);
    if (source_dir == NULL) {
        printf("Failed to open source directory: %s\n", source_path);
        return;
    }

    DIR* dest_dir = opendir(dest_path);
    if (dest_dir == NULL) {
        printf("Failed to open destination directory: %s\n", dest_path);
        closedir(source_dir);
        return;
    }

    char path[1024];
    while ((readdir(source_dir))!= NULL) {
        FileInfo* file_info = malloc(sizeof(FileInfo));
        file_info->name = malloc(sizeof(char) * 1024);
        strcpy(file_info->name, (char*)readdir(source_dir)->d_name);
        file_info->entry = readdir(source_dir);

        sprintf(path, "%s/%s", source_path, file_info->name);
        if (file_info->entry->d_type == DT_DIR) {
            char dest_subdir[1024];
            sprintf(dest_subdir, "%s/%s", dest_path, file_info->name);
            mkdir(dest_subdir, 0777);
            backup_file(path, dest_subdir);
        } else {
            char dest_file[1024];
            sprintf(dest_file, "%s/%s", dest_path, file_info->name);
            FILE* dest_fp = fopen(dest_file, "wb");
            if (dest_fp == NULL) {
                printf("Failed to open destination file: %s\n", dest_file);
                free(file_info->name);
                free(file_info);
                continue;
            }

            FILE* source_fp = fopen(path, "rb");
            if (source_fp == NULL) {
                printf("Failed to open source file: %s\n", path);
                fclose(dest_fp);
                remove(dest_file);
                free(file_info->name);
                free(file_info);
                continue;
            }

            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), source_fp)!= NULL) {
                fwrite(buffer, strlen(buffer), 1, dest_fp);
            }

            fclose(source_fp);
            fclose(dest_fp);
        }

        free(file_info->name);
        free(file_info);
    }

    closedir(source_dir);
    closedir(dest_dir);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_path destination_path\n", argv[0]);
        return 1;
    }

    backup_file(argv[1], argv[2]);

    return 0;
}