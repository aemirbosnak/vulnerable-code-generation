//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <ctype.h>

#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 100
#define MAX_FILE_TYPE 20
#define MAX_FILE_PERMISSION 20
#define MAX_FILE_OWNER 20
#define MAX_FILE_GROUP 20

typedef struct {
    char file_name[MAX_FILE_NAME];
    int file_size;
    char file_type[MAX_FILE_TYPE];
    char file_permission[MAX_FILE_PERMISSION];
    char file_owner[MAX_FILE_OWNER];
    char file_group[MAX_FILE_GROUP];
} FileInfo;

void read_directory(char* path, int level) {
    DIR* dir = opendir(path);
    struct dirent* dirent;
    while ((dirent = readdir(dir))!= NULL) {
        if (dirent->d_type == DT_DIR) {
            char new_path[MAX_FILE_NAME];
            strcpy(new_path, path);
            strcat(new_path, "/");
            strcat(new_path, dirent->d_name);
            printf("%*s%s/\n", level*4, "", dirent->d_name);
            read_directory(new_path, level+1);
        } else {
            FileInfo file_info;
            strcpy(file_info.file_name, dirent->d_name);
            file_info.file_size = dirent->d_reclen;
            strcpy(file_info.file_type, "");
            strcpy(file_info.file_permission, "");
            strcpy(file_info.file_owner, "");
            strcpy(file_info.file_group, "");
            printf("%*s%s\n", level*4, "", dirent->d_name);
        }
    }
    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }
    char path[MAX_FILE_NAME];
    strcpy(path, argv[1]);
    read_directory(path, 0);
    return 0;
}