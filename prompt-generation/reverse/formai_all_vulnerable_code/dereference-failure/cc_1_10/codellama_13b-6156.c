//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <time.h>

#define MAX_PATH_LEN 1024
#define MAX_FILE_LEN 256
#define MAX_FILE_EXT_LEN 16

struct file_data {
    char path[MAX_PATH_LEN];
    char name[MAX_FILE_LEN];
    char ext[MAX_FILE_EXT_LEN];
    struct stat sb;
};

int backup_file(const char *path, const char *backup_dir) {
    struct file_data file;
    FILE *fp;
    char *file_name, *backup_path;
    int ret;

    // Get the file information
    ret = stat(path, &file.sb);
    if (ret < 0) {
        perror("stat");
        return -1;
    }

    // Create the backup path
    file_name = basename(path);
    backup_path = malloc(strlen(backup_dir) + strlen(file_name) + 1);
    strcpy(backup_path, backup_dir);
    strcat(backup_path, file_name);

    // Open the file for reading
    fp = fopen(path, "r");
    if (!fp) {
        perror("fopen");
        return -1;
    }

    // Create the backup file
    ret = creat(backup_path, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (ret < 0) {
        perror("creat");
        return -1;
    }

    // Copy the file data to the backup file
    while (fread(file.name, sizeof(file.name), 1, fp) == 1) {
        fwrite(file.name, sizeof(file.name), 1, backup_path);
    }

    // Close the file and free the memory
    fclose(fp);
    free(backup_path);

    return 0;
}

int main(int argc, char **argv) {
    char *backup_dir;
    int ret;

    // Check the number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s backup_dir\n", argv[0]);
        return -1;
    }

    // Get the backup directory
    backup_dir = argv[1];

    // Backup the file
    ret = backup_file(argv[1], backup_dir);
    if (ret < 0) {
        fprintf(stderr, "Failed to backup file\n");
        return -1;
    }

    return 0;
}