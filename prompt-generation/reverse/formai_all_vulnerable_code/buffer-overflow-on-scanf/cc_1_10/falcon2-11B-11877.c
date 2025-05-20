//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_FILENAME_SIZE 100

void backup_file(const char *src, const char *dest) {
    int src_fd, dest_fd;
    char src_name[MAX_FILENAME_SIZE], dest_name[MAX_FILENAME_SIZE];

    sprintf(src_name, "%s", src);
    sprintf(dest_name, "%s", dest);

    src_fd = open(src_name, O_RDONLY);
    dest_fd = open(dest_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    if (src_fd == -1 || dest_fd == -1) {
        perror("Failed to open file");
        return;
    }

    char buffer[4096];
    ssize_t bytes_read = read(src_fd, buffer, sizeof(buffer));
    while (bytes_read > 0) {
        bytes_read = write(dest_fd, buffer, bytes_read);
        if (bytes_read < 0) {
            perror("Failed to write to file");
            close(src_fd);
            close(dest_fd);
            return;
        }
        bytes_read = read(src_fd, buffer, sizeof(buffer));
    }

    close(src_fd);
    close(dest_fd);
}

int main() {
    char *src, *dest;
    printf("Enter the source file name: ");
    scanf("%s", &src);

    printf("Enter the destination file name: ");
    scanf("%s", &dest);

    backup_file(src, dest);

    printf("Backup completed!\n");

    return 0;
}