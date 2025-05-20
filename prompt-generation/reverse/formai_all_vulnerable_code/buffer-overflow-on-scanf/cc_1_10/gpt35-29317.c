//FormAI DATASET v1.0 Category: File Synchronizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_NUM_FILES 10000
#define MAX_FILE_NAME 1000
#define BUF_SIZE 1024

// Struct to hold file info
typedef struct File {
    char name[MAX_FILE_NAME];
    char path[MAX_FILE_NAME];
    int size;
} File;

// Global variables
char source_dir[MAX_FILE_NAME];
char destination_dir[MAX_FILE_NAME];
int num_files_in_source;
int num_files_in_destination;
File source_files[MAX_NUM_FILES];
File destination_files[MAX_NUM_FILES];

// Function to get file size
int get_file_size(char* file_path) {
    struct stat file_stats;
    if (stat(file_path, &file_stats) == -1) {
        perror("Error getting file stats");
        exit(EXIT_FAILURE);
    }
    return file_stats.st_size;
}

// Function to get file path
void get_file_path(char* file_path, char* dir_path, char* file_name) {
    strcpy(file_path, dir_path);
    strcat(file_path, "/");
    strcat(file_path, file_name);
}

// Function to check if a file exists
bool file_exists(char* file_path) {
    return access(file_path, F_OK) == 0;
}

// Function to copy a file
void copy_file(char* source_file_path, char* destination_file_path) {
    int source_file_fd = open(source_file_path, O_RDONLY);
    if (source_file_fd == -1) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }
    int destination_file_fd = creat(destination_file_path, 0666);
    if (destination_file_fd == -1) {
        perror("Error creating destination file");
        exit(EXIT_FAILURE);
    }
    char buffer[BUF_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(source_file_fd, buffer, BUF_SIZE)) > 0) {
        ssize_t bytes_written = write(destination_file_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Write error");
            exit(EXIT_FAILURE);
        }
    }
    if (bytes_read == -1) {
        perror("Read error");
        exit(EXIT_FAILURE);
    }
    close(destination_file_fd);
    close(source_file_fd);
}

// Function to compare files in source and destination directories
void compare_files() {
    for (int i = 0; i < num_files_in_source; i++) {
        bool file_exists_in_destination = false;
        for (int j = 0; j < num_files_in_destination; j++) {
            if (strcmp(source_files[i].name, destination_files[j].name) == 0) {
                if (source_files[i].size == destination_files[j].size) {
                    file_exists_in_destination = true;
                    break;
                } else {
                    if (remove(destination_files[j].path) == -1) {
                        perror("Error deleting file");
                        exit(EXIT_FAILURE);
                    }
                    copy_file(source_files[i].path, destination_files[j].path);
                    file_exists_in_destination = true;
                    break;
                }
            }
        }
        if (!file_exists_in_destination) {
            char destination_file_path[MAX_FILE_NAME];
            get_file_path(destination_file_path, destination_dir, source_files[i].name);
            copy_file(source_files[i].path, destination_file_path);
        }
    }
}

// Function to get list of files in a directory
void get_files_in_directory(File* files, int* num_files, char* dir_path) {
    DIR* dir = opendir(dir_path);
    if (!dir) {
        perror("Could not open directory");
        exit(EXIT_FAILURE);
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char file_path[MAX_FILE_NAME];
            get_file_path(file_path, dir_path, entry->d_name);
            strcpy(files[*num_files].name, entry->d_name);
            strcpy(files[*num_files].path, file_path);
            files[*num_files].size = get_file_size(file_path);
            (*num_files)++;
        }
    }
    closedir(dir);
}

// Function to synchronize two directories
void synchronize_directories() {
    get_files_in_directory(source_files, &num_files_in_source, source_dir);
    get_files_in_directory(destination_files, &num_files_in_destination, destination_dir);
    compare_files();
}

// Main function
int main() {
    printf("Enter source directory: ");
    scanf("%s", source_dir);
    printf("Enter destination directory: ");
    scanf("%s", destination_dir);
    synchronize_directories();
    printf("Synchronization successful!\n");
    return 0;
}