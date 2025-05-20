//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct FileInfo {
    char name[256];
    off_t size;
    time_t mtime;
} FileInfo;

void get_file_info(const char *path, FileInfo *info) {
    struct stat sb;
    if (stat(path, &sb) == -1) {
        perror("stat");
        exit(1);
    }
    strcpy(info->name, path);
    info->size = sb.st_size;
    info->mtime = sb.st_mtime;
}

int compare_file_info(const FileInfo *info1, const FileInfo *info2) {
    if (info1->size != info2->size) {
        return info1->size - info2->size;
    }
    if (info1->mtime != info2->mtime) {
        return info1->mtime - info2->mtime;
    }
    return strcmp(info1->name, info2->name);
}

void sync_files(const char *src, const char *dst) {
    FileInfo src_info, dst_info;
    get_file_info(src, &src_info);
    get_file_info(dst, &dst_info);
    if (compare_file_info(&src_info, &dst_info) == 0) {
        printf("Files are already in sync.\n");
        return;
    }
    int src_fd = open(src, O_RDONLY);
    if (src_fd == -1) {
        perror("open");
        exit(1);
    }
    int dst_fd = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd == -1) {
        perror("open");
        exit(1);
    }
    char buffer[4096];
    ssize_t bytes_read;
    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        if (write(dst_fd, buffer, bytes_read) != bytes_read) {
            perror("write");
            exit(1);
        }
    }
    if (bytes_read == -1) {
        perror("read");
        exit(1);
    }
    close(src_fd);
    close(dst_fd);
    printf("Files have been synchronized.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(1);
    }
    sync_files(argv[1], argv[2]);
    return 0;
}