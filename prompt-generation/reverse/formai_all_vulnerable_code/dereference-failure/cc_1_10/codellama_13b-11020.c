//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: complete
// backup.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

// Struct to store file information
typedef struct {
    char filename[256];
    char filepath[256];
    char filetype[16];
    int filesize;
} file_info_t;

// Function to get the file information
void get_file_info(const char *filepath, file_info_t *info) {
    struct stat file_stat;
    stat(filepath, &file_stat);
    info->filesize = file_stat.st_size;
    strcpy(info->filepath, filepath);
    strcpy(info->filename, basename(filepath));
    if (S_ISREG(file_stat.st_mode)) {
        strcpy(info->filetype, "file");
    } else if (S_ISDIR(file_stat.st_mode)) {
        strcpy(info->filetype, "directory");
    } else {
        strcpy(info->filetype, "other");
    }
}

// Function to copy a file
void copy_file(const char *src, const char *dest) {
    int src_fd, dest_fd;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    src_fd = open(src, O_RDONLY);
    if (src_fd == -1) {
        fprintf(stderr, "Error opening file %s\n", src);
        exit(1);
    }

    dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        fprintf(stderr, "Error creating file %s\n", dest);
        exit(1);
    }

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        write(dest_fd, buffer, bytes_read);
    }

    close(src_fd);
    close(dest_fd);
}

// Function to backup a file
void backup_file(const char *filepath) {
    file_info_t info;
    char backup_filepath[256];

    get_file_info(filepath, &info);
    sprintf(backup_filepath, "%s.bak", info.filepath);
    copy_file(info.filepath, backup_filepath);
}

// Function to backup all files in a directory
void backup_dir(const char *dirpath) {
    DIR *dir;
    struct dirent *entry;
    char filepath[256];

    dir = opendir(dirpath);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory %s\n", dirpath);
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            sprintf(filepath, "%s/%s", dirpath, entry->d_name);
            backup_file(filepath);
        }
    }

    closedir(dir);
}

// Function to backup all files in the system
void backup_all() {
    DIR *dir;
    struct dirent *entry;
    char dirpath[256];

    dir = opendir("/");
    if (dir == NULL) {
        fprintf(stderr, "Error opening root directory\n");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            sprintf(dirpath, "/%s", entry->d_name);
            backup_dir(dirpath);
        }
    }

    closedir(dir);
}

int main() {
    backup_all();
    return 0;
}