//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

#define BUF_SIZE 4096

// Function to copy a file
int copy_file(const char *src_file, const char *dst_file) {
    FILE *src, *dst;
    char buf[BUF_SIZE];
    size_t bytes_read;

    // Open the source and destination files
    src = fopen(src_file, "rb");
    if (src == NULL) {
        perror("fopen(src_file) failed");
        return -1;
    }
    dst = fopen(dst_file, "wb");
    if (dst == NULL) {
        perror("fopen(dst_file) failed");
        fclose(src);
        return -1;
    }

    // Copy the file data in chunks
    while ((bytes_read = fread(buf, 1, BUF_SIZE, src)) > 0) {
        fwrite(buf, 1, bytes_read, dst);
    }

    // Close the files
    fclose(src);
    fclose(dst);

    return 0;
}

// Function to get the current date and time as a string
char *get_date_time_str() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *date_time_str = malloc(100);
    strftime(date_time_str, 100, "%Y-%m-%d %H:%M:%S", tm);
    return date_time_str;
}

// Function to create a backup of a file
int backup_file(const char *file_name) {
    char *backup_file_name = malloc(100);
    char *date_time_str = get_date_time_str();
    sprintf(backup_file_name, "%s.%s", file_name, date_time_str);

    // Copy the file to the backup file
    int result = copy_file(file_name, backup_file_name);
    if (result != 0) {
        perror("copy_file() failed");
        return result;
    }

    // Get the file size
    struct stat statbuf;
    stat(file_name, &statbuf);

    // Print the backup file name and size
    printf("Backup file created: %s (%ld bytes)\n", backup_file_name, statbuf.st_size);

    // Free the allocated memory
    free(backup_file_name);
    free(date_time_str);

    return 0;
}

int main() {
    // Get the file name from the user
    char file_name[100];
    printf("Enter the file name to be backed up: ");
    scanf("%s", file_name);

    // Backup the file
    int result = backup_file(file_name);
    if (result != 0) {
        return result;
    }

    return 0;
}