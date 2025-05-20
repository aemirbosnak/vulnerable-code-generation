//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <fcntl.h>

#define BUF_SIZE 4096
#define FILE_NAME_LEN 1024

typedef struct {
    char name[FILE_NAME_LEN];
    char path[FILE_NAME_LEN];
    char type; // d - directory, f - file
} file_t;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char *directory = argv[1];
    char *file_name = NULL;
    char *file_path = NULL;
    char *file_content = NULL;

    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    int file_fd;
    int file_size;

    if ((dir = opendir(directory)) == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        file_name = entry->d_name;
        file_path = malloc(strlen(directory) + strlen(file_name) + 2);
        sprintf(file_path, "%s/%s", directory, file_name);

        if (lstat(file_path, &statbuf) == -1) {
            perror("lstat");
            return 1;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            continue;
        }

        file_fd = open(file_path, O_RDONLY);
        if (file_fd == -1) {
            perror("open");
            return 1;
        }

        file_size = statbuf.st_size;
        file_content = malloc(file_size);
        if (file_content == NULL) {
            perror("malloc");
            return 1;
        }

        if (read(file_fd, file_content, file_size) == -1) {
            perror("read");
            return 1;
        }

        // backup the file
        time_t now = time(NULL);
        struct tm *tm = localtime(&now);
        char backup_file_name[FILE_NAME_LEN];
        sprintf(backup_file_name, "%s.%04d%02d%02d%02d%02d%02d", file_name, tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
        char backup_file_path[FILE_NAME_LEN];
        sprintf(backup_file_path, "%s/%s", directory, backup_file_name);

        int backup_fd = open(backup_file_path, O_WRONLY | O_CREAT, 0644);
        if (backup_fd == -1) {
            perror("open");
            return 1;
        }

        if (write(backup_fd, file_content, file_size) == -1) {
            perror("write");
            return 1;
        }

        close(backup_fd);

        free(file_content);
        close(file_fd);
        free(file_path);
    }

    closedir(dir);

    return 0;
}