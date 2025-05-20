//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: scientific
/*
 * File Backup System Example Program
 *
 * This program demonstrates how to create a backup system for files in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>

// Function to get the current time
time_t get_current_time() {
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return timeinfo->tm_hour * 3600 + timeinfo->tm_min * 60 + timeinfo->tm_sec;
}

// Function to copy a file
int copy_file(char* src, char* dst) {
    FILE* src_file = fopen(src, "r");
    if (src_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for reading\n", src);
        return 1;
    }
    FILE* dst_file = fopen(dst, "w");
    if (dst_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", dst);
        fclose(src_file);
        return 1;
    }
    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), 1024, src_file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, dst_file);
    }
    fclose(src_file);
    fclose(dst_file);
    return 0;
}

// Function to create a backup file
int create_backup(char* file_name) {
    char backup_file_name[100];
    sprintf(backup_file_name, "backup_%s_%ld", file_name, get_current_time());
    return copy_file(file_name, backup_file_name);
}

// Function to iterate through files in a directory
void iterate_directory(char* directory_name) {
    DIR* dir = opendir(directory_name);
    if (dir == NULL) {
        fprintf(stderr, "Error: Could not open directory %s\n", directory_name);
        return;
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char file_name[100];
            sprintf(file_name, "%s/%s", directory_name, entry->d_name);
            create_backup(file_name);
        }
    }
    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    iterate_directory(argv[1]);
    return 0;
}