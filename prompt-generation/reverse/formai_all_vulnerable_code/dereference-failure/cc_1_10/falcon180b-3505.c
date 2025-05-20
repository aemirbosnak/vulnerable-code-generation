//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_FILE_NAME 1024

// Function to read a directory
int read_directory(char *path) {
    DIR *dir;
    struct dirent *ent;
    dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Could not open directory %s\n", path);
        return -1;
    }
    while ((ent = readdir(dir))!= NULL) {
        printf("%s\n", ent->d_name);
    }
    closedir(dir);
    return 0;
}

// Function to recover deleted files
int recover_deleted_files(char *path) {
    char deleted_file_name[MAX_FILE_NAME];
    sprintf(deleted_file_name, ".%s.deleted", path);
    int fd = open(deleted_file_name, O_RDONLY);
    if (fd == -1) {
        printf("No deleted files found in directory %s\n", path);
        return 0;
    }
    char buffer[1024];
    int bytes_read;
    while ((bytes_read = read(fd, buffer, 1024)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s\n", buffer);
    }
    close(fd);
    return 0;
}

// Function to recover lost files
int recover_lost_files(char *path) {
    char lost_file_name[MAX_FILE_NAME];
    sprintf(lost_file_name, ".%s.lost", path);
    int fd = open(lost_file_name, O_RDONLY);
    if (fd == -1) {
        printf("No lost files found in directory %s\n", path);
        return 0;
    }
    char buffer[1024];
    int bytes_read;
    while ((bytes_read = read(fd, buffer, 1024)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s\n", buffer);
    }
    close(fd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return -1;
    }
    char path[MAX_FILE_NAME];
    strcpy(path, argv[1]);
    read_directory(path);
    recover_deleted_files(path);
    recover_lost_files(path);
    return 0;
}