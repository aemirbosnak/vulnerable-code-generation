//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <errno.h>

#define MAX_FILENAME_LEN 256
#define MAX_BACKUP_DIR_LEN 128

int main(int argc, char *argv[]) {
    char backup_dir[MAX_BACKUP_DIR_LEN];
    char src_dir[MAX_FILENAME_LEN];
    char dst_dir[MAX_FILENAME_LEN];
    char file_name[MAX_FILENAME_LEN];
    char file_path[MAX_FILENAME_LEN];
    char *file_ext;
    struct stat st;
    struct dirent *dir;
    DIR *dp;
    FILE *fp;
    int rc;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src_dir> <backup_dir>\n", argv[0]);
        return 1;
    }

    strncpy(src_dir, argv[1], MAX_FILENAME_LEN);
    strncpy(backup_dir, argv[2], MAX_BACKUP_DIR_LEN);

    if ((dp = opendir(src_dir)) == NULL) {
        fprintf(stderr, "Failed to open directory %s: %s\n", src_dir, strerror(errno));
        return 1;
    }

    if ((rc = stat(backup_dir, &st)) < 0) {
        fprintf(stderr, "Failed to stat directory %s: %s\n", backup_dir, strerror(errno));
        return 1;
    }

    if (!S_ISDIR(st.st_mode)) {
        fprintf(stderr, "%s is not a directory\n", backup_dir);
        return 1;
    }

    while ((dir = readdir(dp)) != NULL) {
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
            continue;
        }

        strncpy(file_name, dir->d_name, MAX_FILENAME_LEN);
        file_ext = strrchr(file_name, '.');

        if (file_ext == NULL) {
            continue;
        }

        strncpy(dst_dir, backup_dir, MAX_FILENAME_LEN);
        strncat(dst_dir, file_ext, MAX_FILENAME_LEN);

        if ((rc = stat(dst_dir, &st)) < 0) {
            fprintf(stderr, "Failed to stat directory %s: %s\n", dst_dir, strerror(errno));
            return 1;
        }

        if (!S_ISDIR(st.st_mode)) {
            fprintf(stderr, "%s is not a directory\n", dst_dir);
            return 1;
        }

        strncpy(file_path, src_dir, MAX_FILENAME_LEN);
        strncat(file_path, "/", MAX_FILENAME_LEN);
        strncat(file_path, file_name, MAX_FILENAME_LEN);

        if ((fp = fopen(file_path, "rb")) == NULL) {
            fprintf(stderr, "Failed to open file %s: %s\n", file_path, strerror(errno));
            return 1;
        }

        strncpy(file_path, dst_dir, MAX_FILENAME_LEN);
        strncat(file_path, "/", MAX_FILENAME_LEN);
        strncat(file_path, file_name, MAX_FILENAME_LEN);

        if ((fp = fopen(file_path, "wb")) == NULL) {
            fprintf(stderr, "Failed to open file %s: %s\n", file_path, strerror(errno));
            return 1;
        }

        while ((rc = fread(file_path, 1, MAX_FILENAME_LEN, fp)) > 0) {
            fwrite(file_path, 1, rc, fp);
        }

        fclose(fp);
    }

    closedir(dp);

    return 0;
}