//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <openssl/md5.h>

#define BUF_SIZE 1024
#define MAX_PATH_LEN 256
#define MAX_FILE_LEN 128

typedef struct {
    char path[MAX_PATH_LEN];
    char name[MAX_FILE_LEN];
    char md5sum[MD5_DIGEST_LENGTH * 2 + 1];
} file_info_t;

void file_info_init(file_info_t *fi) {
    memset(fi, 0, sizeof(file_info_t));
}

void file_info_update(file_info_t *fi, const char *path, const char *name) {
    strncpy(fi->path, path, MAX_PATH_LEN - 1);
    strncpy(fi->name, name, MAX_FILE_LEN - 1);
    MD5((unsigned char *)fi->path, strlen(fi->path), (unsigned char *)fi->md5sum);
}

void file_info_print(file_info_t *fi) {
    printf("Path: %s\n", fi->path);
    printf("Name: %s\n", fi->name);
    printf("MD5 Sum: %s\n", fi->md5sum);
}

int main() {
    DIR *dir;
    struct dirent *entry;
    file_info_t fi;
    char path[MAX_PATH_LEN];
    char name[MAX_FILE_LEN];
    int fd;
    char buf[BUF_SIZE];
    ssize_t nbytes;
    int i;

    // Open the directory
    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    // Iterate over the files in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Ignore the "." and ".." entries
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue;
        }

        // Build the full path to the file
        snprintf(path, MAX_PATH_LEN, "%s/%s", ".", entry->d_name);

        // Open the file
        fd = open(path, O_RDONLY);
        if (fd < 0) {
            perror("open");
            continue;
        }

        // Read the file contents
        nbytes = read(fd, buf, BUF_SIZE);
        if (nbytes < 0) {
            perror("read");
            close(fd);
            continue;
        }

        // Compute the MD5 sum of the file contents
        file_info_init(&fi);
        file_info_update(&fi, path, entry->d_name);

        // Print the file information
        file_info_print(&fi);

        // Close the file
        close(fd);
    }

    // Close the directory
    closedir(dir);

    return 0;
}