//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_FILE_PATH_LEN 1024
#define BACKUP_DIR "./backup"

struct file_info {
    char name[MAX_FILE_NAME_LEN];
    char path[MAX_FILE_PATH_LEN];
    time_t mtime;
};

void get_file_info(const char *file_path, struct file_info *file_info) {
    struct stat st;
    stat(file_path, &st);
    strcpy(file_info->name, basename(file_path));
    strncpy(file_info->path, file_path, MAX_FILE_PATH_LEN - 1);
    file_info->mtime = st.st_mtime;
}

void backup_file(const char *file_path) {
    char backup_path[MAX_FILE_PATH_LEN];
    sprintf(backup_path, "%s/%s", BACKUP_DIR, file_path);
    mkdir(BACKUP_DIR, 0777);
    rename(file_path, backup_path);
}

int compare_mtime(const void *a, const void *b) {
    const struct file_info *file_info_a = a;
    const struct file_info *file_info_b = b;
    return difftime(file_info_b->mtime, file_info_a->mtime);
}

void backup_files(const char *dir_path) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(dir_path))!= NULL) {
        char file_path[MAX_FILE_PATH_LEN];
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                sprintf(file_path, "%s/%s", dir_path, ent->d_name);
                struct file_info file_info;
                get_file_info(file_path, &file_info);
                backup_file(file_path);
            }
        }
        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        exit(1);
    }
    backup_files(argv[1]);
    printf("Backup completed!\n");
    return 0;
}