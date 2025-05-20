//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define MAX_PATH_LENGTH 256
#define MAX_FILENAME_LENGTH 32
#define MAX_FILE_SIZE 1024 * 1024 * 1024 // 1GB

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    char path[MAX_PATH_LENGTH];
    int size;
    time_t modified_time;
    int is_directory;
    int is_file;
} FileInfo;

int main(int argc, char **argv) {
    char *root_path = "/";
    char *path = (char *)malloc(MAX_PATH_LENGTH);
    char *filename = (char *)malloc(MAX_FILENAME_LENGTH);
    char *buffer = (char *)malloc(BUFFER_SIZE);

    int fd, i, n;
    FileInfo file_info;
    DIR *dir;
    struct dirent *dir_entry;

    // Initialize the file system
    mkdir(root_path, 0755);
    chdir(root_path);

    // Create a new file
    strcpy(filename, "test.txt");
    fd = open(filename, O_CREAT | O_WRONLY, 0644);
    write(fd, "Hello, world!", 13);
    close(fd);

    // Create a new directory
    strcpy(filename, "mydir");
    mkdir(filename, 0755);

    // List all files and directories
    dir = opendir(root_path);
    while ((dir_entry = readdir(dir)) != NULL) {
        strcpy(file_info.name, dir_entry->d_name);
        strcpy(file_info.path, root_path);
        strcat(file_info.path, file_info.name);
        file_info.size = lstat(file_info.path, &file_info.modified_time);
        file_info.is_directory = S_ISDIR(file_info.size);
        file_info.is_file = S_ISREG(file_info.size);
        printf("File: %s (%ld bytes, modified time: %ld)\n", file_info.name, file_info.size, file_info.modified_time);
    }
    closedir(dir);

    // Read a file
    strcpy(filename, "test.txt");
    fd = open(filename, O_RDONLY);
    n = read(fd, buffer, BUFFER_SIZE);
    printf("File contents: %s\n", buffer);
    close(fd);

    // Delete a file
    strcpy(filename, "test.txt");
    unlink(filename);

    // Delete a directory
    strcpy(filename, "mydir");
    rmdir(filename);

    free(path);
    free(filename);
    free(buffer);

    return 0;
}