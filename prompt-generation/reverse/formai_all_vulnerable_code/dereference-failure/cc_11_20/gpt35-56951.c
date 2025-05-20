//FormAI DATASET v1.0 Category: File Synchronizer ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PATH_LENGTH 1024 // Maximum path length

// Function to synchronize the contents of two directories
void sync_directories(char* source, char* destination){
    DIR *source_directory = opendir(source); // Open source directory
    if(source_directory == NULL){ // If source directory does not exist
        printf("Error opening directory %s: %s\n", source, strerror(errno));
        return;
    }
    DIR *destination_directory = opendir(destination); // Open destination directory
    if(destination_directory == NULL){ // If destination directory does not exist
        printf("Error opening directory %s: %s\n", destination, strerror(errno));
        return;
    }
    // Variables for storing file/directory paths and stats
    struct dirent *source_file;
    struct dirent *destination_file;
    char source_file_path[MAX_PATH_LENGTH];
    char destination_file_path[MAX_PATH_LENGTH];
    struct stat source_file_stat;
    struct stat destination_file_stat;
    while((source_file = readdir(source_directory)) != NULL){ // Loop through files/directories in source directory
        if(source_file->d_name[0] == '.') // Skip hidden files/directories
            continue;
        strcpy(source_file_path, source); // Copy source directory path to file path
        strcat(source_file_path, "/");
        strcat(source_file_path, source_file->d_name); // Append file/directory name
        if(stat(source_file_path, &source_file_stat) == -1){ // Get file/directory stats
            printf("Error getting stats for %s: %s\n", source_file_path, strerror(errno));
            continue;
        }
        strcpy(destination_file_path, destination); // Copy destination directory path to file path
        strcat(destination_file_path, "/");
        strcat(destination_file_path, source_file->d_name); // Append file/directory name
        if(stat(destination_file_path, &destination_file_stat) == -1){ // Get file/directory stats
            if(errno == ENOENT){ // If destination file/directory does not exist
                if(S_ISREG(source_file_stat.st_mode)){ // If source file is a regular file
                    FILE *source_file_ptr = fopen(source_file_path, "rb"); // Open source file for reading
                    if(source_file_ptr == NULL){ // If source file can't be opened
                        printf("Error opening file %s: %s\n", source_file_path, strerror(errno));
                        continue;
                    }
                    FILE *destination_file_ptr = fopen(destination_file_path, "wb"); // Open destination file for writing
                    if(destination_file_ptr == NULL){ // If destination file can't be opened
                        printf("Error opening file %s: %s\n", destination_file_path, strerror(errno));
                        fclose(source_file_ptr);
                        continue;
                    }
                    char buffer[1024]; // Buffer for copying file contents
                    int bytes_read;
                    while((bytes_read = fread(buffer, 1, sizeof(buffer), source_file_ptr)) > 0){ // Copy file contents
                        if(fwrite(buffer, 1, bytes_read, destination_file_ptr) != bytes_read){ // If there was an error writing to destination file
                            printf("Error writing to file %s: %s\n", destination_file_path, strerror(errno));
                            break;
                        }
                    }
                    fclose(source_file_ptr);
                    fclose(destination_file_ptr);
                }
                else if(S_ISDIR(source_file_stat.st_mode)){ // If source file is a directory
                    if(mkdir(destination_file_path, 0755) == -1){ // Create destination directory with permissions 0755
                        printf("Error creating directory %s: %s\n", destination_file_path, strerror(errno));
                        continue;
                    }
                    sync_directories(source_file_path, destination_file_path); // Recursively synchronize directories
                }
            }
            else{ // If there was an error getting destination file stats
                printf("Error getting stats for %s: %s\n", destination_file_path, strerror(errno));
                continue;
            }
        }
        else{ // If destination file exists
            if(S_ISREG(source_file_stat.st_mode) && S_ISREG(destination_file_stat.st_mode)){ // If both files are regular files
                if(difftime(source_file_stat.st_mtime, destination_file_stat.st_mtime) > 0){ // If source file is newer than destination file
                    FILE *source_file_ptr = fopen(source_file_path, "rb"); // Open source file for reading
                    if(source_file_ptr == NULL){ // If source file can't be opened
                        printf("Error opening file %s: %s\n", source_file_path, strerror(errno));
                        continue;
                    }
                    FILE *destination_file_ptr = fopen(destination_file_path, "wb"); // Open destination file for writing
                    if(destination_file_ptr == NULL){ // If destination file can't be opened
                        printf("Error opening file %s: %s\n", destination_file_path, strerror(errno));
                        fclose(source_file_ptr);
                        continue;
                    }
                    char buffer[1024]; // Buffer for copying file contents
                    int bytes_read;
                    while((bytes_read = fread(buffer, 1, sizeof(buffer), source_file_ptr)) > 0){ // Copy file contents
                        if(fwrite(buffer, 1, bytes_read, destination_file_ptr) != bytes_read){ // If there was an error writing to destination file
                            printf("Error writing to file %s: %s\n", destination_file_path, strerror(errno));
                            break;
                        }
                    }
                    fclose(source_file_ptr);
                    fclose(destination_file_ptr);
                    if(utime(destination_file_path, &source_file_stat.st_mtim) == -1){ // Set destination file modification time to source file modification time
                        printf("Error setting modification time for %s: %s\n", destination_file_path, strerror(errno));
                    }
                }
            }
            else if(S_ISDIR(source_file_stat.st_mode) && S_ISDIR(destination_file_stat.st_mode)){ // If both files are directories
                sync_directories(source_file_path, destination_file_path); // Recursively synchronize directories
            }
        }
    }
    closedir(source_directory);
    closedir(destination_directory);
}

int main(int argc, char *argv[]){
    if(argc < 3){ // If not enough arguments are passed
        printf("Usage: %s SOURCE_DIR DESTINATION_DIR\n", argv[0]);
        return 0;
    }
    sync_directories(argv[1], argv[2]); // Synchronize directories
    return 0;
}