//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PATH_LEN 1024
#define MAX_FILES 1024

struct file_info {
    char path[MAX_PATH_LEN];
    struct stat stats;
};

void backup_file(const char* file) {
    // Get the file's information
    struct stat file_stats;
    if (stat(file, &file_stats) < 0) {
        fprintf(stderr, "Error getting file information for %s: %s\n", file, strerror(errno));
        return;
    }

    // Copy the file to the backup directory
    char backup_path[MAX_PATH_LEN];
    sprintf(backup_path, "backup/%s", file);
    int backup_fd = open(backup_path, O_CREAT | O_WRONLY, 0644);
    if (backup_fd < 0) {
        fprintf(stderr, "Error creating backup file %s: %s\n", backup_path, strerror(errno));
        return;
    }
    int file_fd = open(file, O_RDONLY);
    if (file_fd < 0) {
        fprintf(stderr, "Error opening file %s for reading: %s\n", file, strerror(errno));
        close(backup_fd);
        return;
    }
    char buf[4096];
    ssize_t bytes_read;
    while ((bytes_read = read(file_fd, buf, sizeof(buf))) > 0) {
        write(backup_fd, buf, bytes_read);
    }
    close(file_fd);
    close(backup_fd);
}

int main(int argc, char* argv[]) {
    // Get the directory to back up
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    char* directory = argv[1];

    // Get the files in the directory
    struct dirent** file_list;
    int num_files = scandir(directory, &file_list, NULL, alphasort);
    if (num_files < 0) {
        fprintf(stderr, "Error getting files in %s: %s\n", directory, strerror(errno));
        return 1;
    }

    // Back up each file
    for (int i = 0; i < num_files; i++) {
        struct file_info file;
        sprintf(file.path, "%s/%s", directory, file_list[i]->d_name);
        backup_file(file.path);
    }

    return 0;
}