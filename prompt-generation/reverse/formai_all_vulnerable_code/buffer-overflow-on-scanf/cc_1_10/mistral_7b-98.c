//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define MAX_BACKUPS 5
#define BACKUP_EXT ".bkp"

typedef struct {
    char name[1024];
    time_t modification_time;
} FileInfo;

FileInfo files[1024];
int num_files = 0;

void create_backup(char *file_name) {
    int file_fd, backup_fd;
    char backup_file_name[1024];
    struct stat file_stat;

    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, BACKUP_EXT);

    if (stat(file_name, &file_stat) < 0) {
        perror("Error statting file");
        return;
    }

    if ((file_fd = open(file_name, O_RDWR)) < 0) {
        perror("Error opening file for read/write");
        return;
    }

    if ((backup_fd = creat(backup_file_name, file_stat.st_mode)) < 0) {
        perror("Error creating backup file");
        close(file_fd);
        return;
    }

    ssize_t bytes_read;
    char buffer[4096];

    while ((bytes_read = read(file_fd, buffer, sizeof(buffer))) > 0) {
        write(backup_fd, buffer, bytes_read);
    }

    close(file_fd);
    close(backup_fd);

    for (int i = num_files; i >= 0; --i) {
        if (strcmp(files[i].name, file_name) == 0) {
            files[i].modification_time = time(NULL);
            return;
        }
        if (i == 0) {
            for (int j = num_files; j > i; --j) {
                strcpy(files[j].name, files[j-1].name);
            }
            strcpy(files[i].name, file_name);
            files[i].modification_time = time(NULL);
            num_files++;
            return;
        }
    }
}

int main() {
    char file_name[1024];

    while (1) {
        printf("Enter file name to backup (or type 'exit' to quit): ");
        scanf("%s", file_name);

        if (strcmp(file_name, "exit") == 0) {
            break;
        }

        create_backup(file_name);
        printf("Backup created: %s\n", file_name);
    }

    return 0;
}