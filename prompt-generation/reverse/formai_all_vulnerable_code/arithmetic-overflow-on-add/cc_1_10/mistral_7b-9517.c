//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BACKUP_DIR "backups/"

void create_backup(const char *file_path) {
    char backup_file_name[128];
    struct tm *tm;
    struct stat file_stat;

    stat(file_path, &file_stat);

    tm = localtime(&file_stat.st_mtime);

    sprintf(backup_file_name, "%s%s_%s_%04d-%02d-%02d_%02d-%02d-%02d.bak",
            BACKUP_DIR, file_path, ctime(tm), tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

    int fd_in = open(file_path, O_RDONLY);
    int fd_out = open(backup_file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd_in < 0 || fd_out < 0) {
        perror("Error opening files");
        exit(1);
    }

    ssize_t bytes_read;
    char buffer[1024];

    while ((bytes_read = read(fd_in, buffer, sizeof(buffer))) > 0) {
        write(fd_out, buffer, bytes_read);
    }

    close(fd_in);
    close(fd_out);

    printf("Backup created: %s\n", backup_file_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    create_backup(argv[1]);

    return 0;
}