//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct {
    char filename[256];
    char backup_filename[256];
    time_t timestamp;
} FileInfo;

void backup_file(const char* filename, const char* backup_dir) {
    char backup_filename[256];
    time_t timestamp = time(NULL);
    snprintf(backup_filename, sizeof(backup_filename), "%s/%ld_%s", backup_dir, timestamp, filename);

    int backup_fd = open(backup_filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (backup_fd == -1) {
        printf("Error: Failed to create backup file '%s'\n", backup_filename);
        exit(1);
    }

    int src_fd = open(filename, O_RDONLY);
    if (src_fd == -1) {
        printf("Error: Failed to open source file '%s'\n", filename);
        close(backup_fd);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(backup_fd, buffer, bytes_read)!= bytes_read) {
            printf("Error: Failed to write to backup file '%s'\n", backup_filename);
            close(src_fd);
            close(backup_fd);
            exit(1);
        }
    }

    close(src_fd);
    close(backup_fd);
}

int main() {
    char backup_dir[256] = "backups";
    mkdir(backup_dir, 0755);

    FILE* input_file = fopen("files.txt", "r");
    if (input_file == NULL) {
        printf("Error: Failed to open input file 'files.txt'\n");
        exit(1);
    }

    FileInfo file_info;
    while (fscanf(input_file, "%s %s %ld\n", file_info.filename, file_info.backup_filename, &file_info.timestamp) == 3) {
        backup_file(file_info.filename, backup_dir);
        printf("Backed up file: %s\n", file_info.filename);
    }

    fclose(input_file);

    return 0;
}