//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if command line arguments are provided
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    
    // Get the directory name from the command line argument
    char *directory = argv[1];
    
    // Open the directory
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        printf("Error opening directory %s\n", directory);
        return 1;
    }
    
    // Initialize variables for disk space usage
    unsigned long long total_size = 0;
    unsigned long long used_size = 0;
    unsigned long long free_size = 0;
    
    // Iterate over files in the directory
    struct dirent *entry;
    while ((entry = readdir(dir))!= NULL) {
        // Get the file name from the entry
        char *file_name = entry->d_name;
        
        // Get the file size
        struct stat file_stat;
        if (stat(file_name, &file_stat) == 0) {
            total_size += file_stat.st_size;
            used_size += file_stat.st_blocks * file_stat.st_blksize;
        }
    }
    
    // Close the directory
    closedir(dir);
    
    // Calculate disk space usage
    unsigned long long total_bytes = total_size * 1024;
    unsigned long long used_bytes = used_size * 1024;
    unsigned long long free_bytes = total_bytes - used_bytes;
    
    // Print disk space usage
    printf("Disk Space Usage:\n");
    printf("Total Size: %llu bytes\n", total_bytes);
    printf("Used Size: %llu bytes\n", used_bytes);
    printf("Free Size: %llu bytes\n", free_bytes);
    
    return 0;
}