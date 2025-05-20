//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_NAME 1024
#define MAX_PATH_NAME 2048

typedef struct {
    char *file_name;
    int is_file;
    int is_infected;
} FileInfo;

int is_infected(FileInfo *file_info) {
    FILE *fp;
    char buffer[1024];
    int count = 0;
    fp = fopen(file_info->file_name, "r");
    if (fp == NULL) {
        return 0;
    }
    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        if (strstr(buffer, "virus")!= NULL) {
            count++;
        }
    }
    fclose(fp);
    if (count > 0) {
        return 1;
    } else {
        return 0;
    }
}

void scan_directory(char *path, int depth) {
    DIR *dp;
    struct dirent *dirp;
    dp = opendir(path);
    if (dp == NULL) {
        return;
    }
    while ((dirp = readdir(dp))!= NULL) {
        if (dirp->d_type == DT_DIR) {
            char sub_path[MAX_PATH_NAME];
            sprintf(sub_path, "%s/%s", path, dirp->d_name);
            scan_directory(sub_path, depth + 1);
        } else {
            char file_path[MAX_PATH_NAME];
            sprintf(file_path, "%s/%s", path, dirp->d_name);
            FileInfo file_info;
            strcpy(file_info.file_name, file_path);
            file_info.is_file = 1;
            file_info.is_infected = is_infected(&file_info);
            if (file_info.is_infected) {
                printf("%s is infected\n", file_path);
            }
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }
    scan_directory(argv[1], 0);
    return 0;
}