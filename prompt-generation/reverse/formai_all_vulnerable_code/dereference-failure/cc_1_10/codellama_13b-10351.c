//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: detailed
// FileBackup.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILE_SIZE 1048576 // 1MB

// Struct to store file information
typedef struct {
    char path[MAX_PATH_LENGTH];
    char name[MAX_PATH_LENGTH];
    unsigned long size;
    time_t modified;
} FileInfo;

// Function to get file information
void getFileInfo(const char *path, FileInfo *file) {
    struct stat st;
    if (stat(path, &st) == 0) {
        file->size = st.st_size;
        file->modified = st.st_mtime;
    }
    strcpy(file->path, path);
    strcpy(file->name, path + strlen(path) + 1);
}

// Function to backup a file
void backupFile(const char *src, const char *dst) {
    int src_fd, dst_fd;
    char buffer[MAX_FILE_SIZE];
    int bytes_read;

    src_fd = open(src, O_RDONLY);
    if (src_fd == -1) {
        perror("Error opening source file");
        return;
    }

    dst_fd = open(dst, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (dst_fd == -1) {
        perror("Error opening destination file");
        close(src_fd);
        return;
    }

    while ((bytes_read = read(src_fd, buffer, MAX_FILE_SIZE)) > 0) {
        write(dst_fd, buffer, bytes_read);
    }

    close(src_fd);
    close(dst_fd);
}

// Function to backup a directory
void backupDirectory(const char *src, const char *dst) {
    DIR *dir;
    struct dirent *entry;
    FileInfo file;

    dir = opendir(src);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Ignore directories
            continue;
        }

        getFileInfo(entry->d_name, &file);
        backupFile(file.path, dst);
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: FileBackup <source> <destination>\n");
        return 1;
    }

    backupDirectory(argv[1], argv[2]);

    return 0;
}