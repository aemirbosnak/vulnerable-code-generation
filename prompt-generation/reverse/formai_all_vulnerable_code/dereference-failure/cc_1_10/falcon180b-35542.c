//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define ERR_MSG_SIZE 256

// Function to print error message
void perror_exit(const char* msg) {
    char err_msg[ERR_MSG_SIZE];
    strerror_r(errno, err_msg, ERR_MSG_SIZE);
    fprintf(stderr, "%s: %s\n", msg, err_msg);
    exit(1);
}

// Function to recover deleted files
int recover_deleted_files(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror_exit("Failed to open directory");
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_UNKNOWN) { // deleted file
            char file_path[1024];
            snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);

            int fd = open(file_path, O_RDWR | O_CREAT, 0644);
            if (fd == -1) {
                perror_exit("Failed to open file");
            }

            char buffer[BUFFER_SIZE];
            memset(buffer, 0, BUFFER_SIZE);
            write(fd, buffer, BUFFER_SIZE);

            close(fd);
            printf("Recovered deleted file: %s\n", entry->d_name);
        }
    }

    closedir(dir);
    return 0;
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    recover_deleted_files(argv[1]);

    return 0;
}