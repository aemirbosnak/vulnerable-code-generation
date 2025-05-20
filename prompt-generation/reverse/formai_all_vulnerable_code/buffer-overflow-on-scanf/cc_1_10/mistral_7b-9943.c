//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BACKUP_DIR "backup_of_the_curious"
#define MAX_LEN 100
#define FILE_NAME "file_of_curiosity.txt"

void backup_file(char *file_path) {
    char backup_file_path[MAX_LEN];
    int fd, ret;

    // Creating backup directory if it does not exist
    if (access(BACKUP_DIR, 0) == -1) {
        ret = mkdir(BACKUP_DIR, 0755);
        if (ret != 0) {
            perror("Failed to create backup directory");
            return;
        }
    }

    // Creating backup file name with current timestamp
    strcpy(backup_file_path, BACKUP_DIR "/");
    strcat(backup_file_path, FILE_NAME);
    strcat(backup_file_path, "_");
    time_t rawtime;
    struct tm *timeinfo;
    char time_string[MAX_LEN];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(time_string, sizeof(time_string), "_%Y%m%d%H%M%S.bak", timeinfo);
    strcat(backup_file_path, time_string);

    // Opening source file for reading
    fd = open(file_path, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open source file for reading");
        return;
    }

    // Opening backup file for writing
    fd = open(backup_file_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Failed to open backup file for writing");
        close(fd);
        return;
    }

    // Copying file content to backup file
    ssize_t bytes_read;
    char buffer[1024];
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(fd, buffer, bytes_read);
    }

    // Closing source and backup files
    close(fd);
    printf("File %s backed up to %s\n", file_path, backup_file_path);
}

int main() {
    char file_path[MAX_LEN];
    printf("Enter the path of the file to be backed up: ");
    scanf("%s", file_path);

    // Calling backup function with given file path
    backup_file(file_path);

    return 0;
}