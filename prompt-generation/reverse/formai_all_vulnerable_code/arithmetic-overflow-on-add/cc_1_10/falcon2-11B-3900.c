//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

void backup_file(const char* source_file, const char* destination_file) {
    int source_fd, destination_fd;
    struct stat source_stat, destination_stat;
    char* source_buffer = NULL;
    int source_buffer_size = 0;

    source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        exit(1);
    }

    source_stat.st_size = lseek(source_fd, 0, SEEK_END);
    close(source_fd);

    source_buffer_size = source_stat.st_size + 1;
    source_buffer = malloc(source_buffer_size);
    if (source_buffer == NULL) {
        perror("Error allocating memory for source buffer");
        exit(1);
    }

    source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        exit(1);
    }

    lseek(source_fd, 0, SEEK_SET);
    read(source_fd, source_buffer, source_stat.st_size);
    close(source_fd);

    destination_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (destination_fd == -1) {
        perror("Error opening destination file");
        exit(1);
    }

    write(destination_fd, source_buffer, source_stat.st_size);
    close(destination_fd);

    free(source_buffer);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    backup_file(argv[1], argv[2]);

    printf("Backup completed successfully!\n");
    return 0;
}