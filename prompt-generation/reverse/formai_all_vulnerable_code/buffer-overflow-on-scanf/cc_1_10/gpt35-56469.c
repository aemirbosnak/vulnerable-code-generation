//FormAI DATASET v1.0 Category: File Backup System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

#define BUF_SIZE 1024

int copy_file(char *src_path, char *dest_path) {
    int src_fd, dest_fd, bytes;
    char buffer[BUF_SIZE];
    struct stat stat_buf;
    if ((src_fd = open(src_path, O_RDONLY)) == -1) {
        return -1;
    }
    if ((dest_fd = open(dest_path, O_WRONLY|O_CREAT, 0666)) == -1) {
        close(src_fd);
        return -1;
    }
    if (fstat(src_fd, &stat_buf) == -1) {
        close(src_fd);
        close(dest_fd);
        return -1;
    }
    while ((bytes = read(src_fd, buffer, BUF_SIZE)) > 0) {
        write(dest_fd, buffer, bytes);
    }
    close(src_fd);
    close(dest_fd);
    if (bytes == -1) {
        return -1;
    }
    return 0;
}

int backup_files(char *src_dir, char *dest_dir) {
    DIR *dir;
    struct dirent *entry;
    char src_path[BUF_SIZE], dest_path[BUF_SIZE];
    if ((dir = opendir(src_dir)) == NULL) {
        return -1;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // regular file
            sprintf(src_path, "%s/%s", src_dir, entry->d_name);
            sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);
            if (copy_file(src_path, dest_path) == -1) {
                closedir(dir);
                return -1;
            }
        }
    }
    closedir(dir);
    return 0;
}

int main() {
    char src_dir[BUF_SIZE], dest_dir[BUF_SIZE];
    printf("Enter the directory path of the files you wish to backup: ");
    scanf("%s", src_dir);
    printf("Enter the destination path of the backup: ");
    scanf("%s", dest_dir);
    if (backup_files(src_dir, dest_dir) == -1) {
        printf("Backup failed!\n");
        return -1;
    }
    printf("Backup successful!\n");
    return 0;
}