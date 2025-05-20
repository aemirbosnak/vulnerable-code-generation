//Code Llama-13B DATASET v1.0 Category: File Synchronizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_FILENAME_LEN 256
#define MAX_BUF_SIZE 4096

struct file_sync_config {
    char src_dir[MAX_FILENAME_LEN];
    char dest_dir[MAX_FILENAME_LEN];
};

struct file_sync_config *parse_config(int argc, char *argv[]) {
    struct file_sync_config *config = malloc(sizeof(struct file_sync_config));
    if (argc < 3) {
        printf("Usage: file_sync src_dir dest_dir\n");
        exit(1);
    }
    strcpy(config->src_dir, argv[1]);
    strcpy(config->dest_dir, argv[2]);
    return config;
}

int compare_files(char *src_file, char *dest_file) {
    int src_fd = open(src_file, O_RDONLY);
    int dest_fd = open(dest_file, O_RDONLY);
    if (src_fd < 0 || dest_fd < 0) {
        return 0;
    }
    struct stat src_stat;
    struct stat dest_stat;
    if (fstat(src_fd, &src_stat) < 0 || fstat(dest_fd, &dest_stat) < 0) {
        return 0;
    }
    if (src_stat.st_size != dest_stat.st_size) {
        return 0;
    }
    char src_buf[MAX_BUF_SIZE];
    char dest_buf[MAX_BUF_SIZE];
    int src_bytes_read = read(src_fd, src_buf, MAX_BUF_SIZE);
    int dest_bytes_read = read(dest_fd, dest_buf, MAX_BUF_SIZE);
    if (src_bytes_read < 0 || dest_bytes_read < 0) {
        return 0;
    }
    if (memcmp(src_buf, dest_buf, src_bytes_read) != 0) {
        return 0;
    }
    return 1;
}

void file_sync(struct file_sync_config *config) {
    DIR *src_dir = opendir(config->src_dir);
    DIR *dest_dir = opendir(config->dest_dir);
    if (src_dir == NULL || dest_dir == NULL) {
        printf("Error opening directories\n");
        exit(1);
    }
    struct dirent *src_entry;
    struct dirent *dest_entry;
    while ((src_entry = readdir(src_dir)) != NULL) {
        if (src_entry->d_type == DT_REG) {
            char src_file[MAX_FILENAME_LEN];
            char dest_file[MAX_FILENAME_LEN];
            sprintf(src_file, "%s/%s", config->src_dir, src_entry->d_name);
            sprintf(dest_file, "%s/%s", config->dest_dir, src_entry->d_name);
            if (!compare_files(src_file, dest_file)) {
                printf("Copying file %s to %s\n", src_file, dest_file);
                int src_fd = open(src_file, O_RDONLY);
                int dest_fd = open(dest_file, O_WRONLY | O_CREAT, 0644);
                if (src_fd < 0 || dest_fd < 0) {
                    printf("Error opening files\n");
                    exit(1);
                }
                char buf[MAX_BUF_SIZE];
                int bytes_read;
                while ((bytes_read = read(src_fd, buf, MAX_BUF_SIZE)) > 0) {
                    write(dest_fd, buf, bytes_read);
                }
                close(src_fd);
                close(dest_fd);
            }
        }
    }
    closedir(src_dir);
    closedir(dest_dir);
}

int main(int argc, char *argv[]) {
    struct file_sync_config *config = parse_config(argc, argv);
    file_sync(config);
    return 0;
}