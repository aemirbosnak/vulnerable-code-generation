//FormAI DATASET v1.0 Category: File Synchronizer ; Style: complex
//Header files
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<errno.h>

//Global variables
char source_dir[100], destination_dir[100];

//Function to check if directory exists
int directory_exists(const char *directory_path) {
    struct stat info;
    if (stat(directory_path, &info) != 0) {
        return 0;
    }
    else if (info.st_mode & S_IFDIR) {
        return 1;
    }
    else {
        return 0;
    }
}

//Function to create directory
void create_directory(const char *directory_path) {
    int status;
    if(!directory_exists(directory_path)) {
        status = mkdir(directory_path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        if(status != 0) {
            printf("Error creating directory : %s\n", directory_path);
            exit(EXIT_FAILURE);
        }
    }
}

//Function to copy file
void copy_file(const char *source, const char *destination) {
    int source_file, destination_file, read_bytes;
    char buffer[BUFSIZ];
    source_file = open(source, O_RDONLY);
    if(source_file == -1) {
        printf("Error opening source file : %s\n", source);
        exit(EXIT_FAILURE);
    }
    destination_file = open(destination, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if(destination_file == -1) {
        printf("Error opening destination file : %s\n", destination);
        exit(EXIT_FAILURE);
    }
    while((read_bytes = read(source_file, buffer, BUFSIZ)) > 0) {
        if(write(destination_file, buffer, read_bytes) != read_bytes) {
            printf("Error writing to destination file : %s\n", destination);
            exit(EXIT_FAILURE);
        }
    }
    if(read_bytes == -1) {
        printf("Error reading from source file : %s\n", source);
        exit(EXIT_FAILURE);
    }
    close(source_file);
    close(destination_file);
}

//Function to process directory recursively
void process_directory(const char *source, const char *destination) {
    DIR *source_directory, *destination_directory;
    struct dirent *dir_entry;
    char source_path[100], destination_path[100];
    source_directory = opendir(source);
    if(source_directory == NULL) {
        printf("Could not open source directory : %s\n", source);
        exit(EXIT_FAILURE);
    }
    while((dir_entry = readdir(source_directory)) != NULL) {
        if(strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
            continue;
        }
        sprintf(source_path, "%s/%s", source, dir_entry->d_name);
        sprintf(destination_path, "%s/%s", destination, dir_entry->d_name);
        if(dir_entry->d_type == DT_DIR) {
            create_directory(destination_path);
            process_directory(source_path, destination_path);
        }
        else if(dir_entry->d_type == DT_REG) {
            copy_file(source_path, destination_path);
        }
        else {
            printf("Unknown file type : %s\n", source_path);
        }
    }
    closedir(source_directory);
}

//Main function
int main() {
    printf("Enter the source directory path : ");
    scanf("%s", source_dir);
    printf("Enter the destination directory path : ");
    scanf("%s", destination_dir);
    create_directory(destination_dir);
    process_directory(source_dir, destination_dir);
    printf("Synchronization successful!\n");
    return 0;
}