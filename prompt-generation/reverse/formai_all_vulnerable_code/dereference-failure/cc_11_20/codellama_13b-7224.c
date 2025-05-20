//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: Ada Lovelace
/*
 * C Metadata Extractor
 *
 * This program demonstrates how to extract metadata from a file in C.
 *
 * Usage:
 *  $ ./metadata_extractor <file_path>
 *
 * Output:
 *  Metadata:
 *   - Creation date: <creation_date>
 *   - Modification date: <modification_date>
 *   - Access date: <access_date>
 *   - File size: <file_size>
 *   - File type: <file_type>
 *   - File permissions: <file_permissions>
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Check if the file path is provided
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    // Get the file path from the command line arguments
    char *file_path = argv[1];

    // Open the file
    int fd = open(file_path, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    // Get the file metadata
    struct stat file_stat;
    if (fstat(fd, &file_stat) < 0) {
        perror("Failed to get file metadata");
        close(fd);
        return 1;
    }

    // Get the creation date
    time_t creation_date = file_stat.st_ctime;

    // Get the modification date
    time_t modification_date = file_stat.st_mtime;

    // Get the access date
    time_t access_date = file_stat.st_atime;

    // Get the file size
    off_t file_size = file_stat.st_size;

    // Get the file type
    char file_type[10];
    switch (file_stat.st_mode & S_IFMT) {
        case S_IFREG:
            strcpy(file_type, "Regular file");
            break;
        case S_IFDIR:
            strcpy(file_type, "Directory");
            break;
        case S_IFLNK:
            strcpy(file_type, "Symbolic link");
            break;
        case S_IFBLK:
            strcpy(file_type, "Block device");
            break;
        case S_IFCHR:
            strcpy(file_type, "Character device");
            break;
        case S_IFIFO:
            strcpy(file_type, "FIFO");
            break;
        case S_IFSOCK:
            strcpy(file_type, "Socket");
            break;
        default:
            strcpy(file_type, "Unknown");
    }

    // Get the file permissions
    char file_permissions[10];
    strcpy(file_permissions, "");
    if (file_stat.st_mode & S_IRUSR) {
        strcat(file_permissions, "r");
    }
    if (file_stat.st_mode & S_IWUSR) {
        strcat(file_permissions, "w");
    }
    if (file_stat.st_mode & S_IXUSR) {
        strcat(file_permissions, "x");
    }

    // Print the metadata
    printf("Metadata:\n");
    printf("  - Creation date: %s\n", ctime(&creation_date));
    printf("  - Modification date: %s\n", ctime(&modification_date));
    printf("  - Access date: %s\n", ctime(&access_date));
    printf("  - File size: %lld\n", (long long)file_size);
    printf("  - File type: %s\n", file_type);
    printf("  - File permissions: %s\n", file_permissions);

    // Close the file
    close(fd);

    return 0;
}