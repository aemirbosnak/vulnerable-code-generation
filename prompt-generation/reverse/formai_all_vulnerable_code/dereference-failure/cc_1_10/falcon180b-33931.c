//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc!= 3) {
        printf("Usage: %s <filename> <destination>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *destination = argv[2];

    int fd_in = open(filename, O_RDONLY);
    if(fd_in == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    struct stat st;
    if(fstat(fd_in, &st) == -1) {
        printf("Error: %s\n", strerror(errno));
        close(fd_in);
        return 1;
    }

    char *buffer = malloc(st.st_size + 1);
    if(!buffer) {
        printf("Error: No memory\n");
        close(fd_in);
        return 1;
    }

    int bytes_read = read(fd_in, buffer, st.st_size);
    if(bytes_read!= st.st_size) {
        printf("Error: %s\n", strerror(errno));
        free(buffer);
        close(fd_in);
        return 1;
    }

    close(fd_in);

    int fd_out = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd_out == -1) {
        printf("Error: %s\n", strerror(errno));
        free(buffer);
        return 1;
    }

    int bytes_written = write(fd_out, buffer, st.st_size);
    if(bytes_written!= st.st_size) {
        printf("Error: %s\n", strerror(errno));
        free(buffer);
        close(fd_out);
        return 1;
    }

    close(fd_out);

    free(buffer);

    printf("File recovery completed successfully\n");
    return 0;
}