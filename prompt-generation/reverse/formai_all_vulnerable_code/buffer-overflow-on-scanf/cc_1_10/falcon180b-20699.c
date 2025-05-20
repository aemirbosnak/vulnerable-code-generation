//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB
#define BACKUP_DIR "backup"
#define BACKUP_EXT ".bak"

void backup_file(char *filename) {
    char backup_filename[strlen(filename) + strlen(BACKUP_EXT) + 1];
    strcpy(backup_filename, filename);
    strcat(backup_filename, BACKUP_EXT);

    int backup_fd = open(backup_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (backup_fd == -1) {
        perror("open");
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int bytes_read;

    while ((bytes_read = read(fileno(stdin), buffer, MAX_FILE_SIZE)) > 0) {
        if (write(backup_fd, buffer, bytes_read)!= bytes_read) {
            perror("write");
            exit(1);
        }
    }

    close(backup_fd);
    printf("Backup file created: %s\n", backup_filename);
}

int main() {
    char filename[MAX_FILE_SIZE];

    printf("Enter file name: ");
    scanf("%s", filename);

    struct stat st;
    if (stat(filename, &st) == -1) {
        perror("stat");
        exit(1);
    }

    if (st.st_size > MAX_FILE_SIZE) {
        printf("File is too large to backup.\n");
        exit(1);
    }

    char backup_filename[strlen(filename) + strlen(BACKUP_EXT) + 1];
    strcpy(backup_filename, filename);
    strcat(backup_filename, BACKUP_EXT);

    int backup_fd = open(backup_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (backup_fd == -1) {
        perror("open");
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int bytes_read;

    while ((bytes_read = read(fileno(stdin), buffer, MAX_FILE_SIZE)) > 0) {
        if (write(backup_fd, buffer, bytes_read)!= bytes_read) {
            perror("write");
            exit(1);
        }
    }

    close(backup_fd);
    printf("Backup file created: %s\n", backup_filename);

    return 0;
}