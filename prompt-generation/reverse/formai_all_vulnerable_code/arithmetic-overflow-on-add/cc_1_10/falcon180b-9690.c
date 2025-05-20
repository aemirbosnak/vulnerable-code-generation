//Falcon-180B DATASET v1.0 Category: Memory management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define PAGE_SIZE 4096

int main(int argc, char *argv[]) {

    char *filename = argv[1];
    int fd = open(filename, O_RDWR | O_CREAT, 0666);

    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    struct stat sb;
    fstat(fd, &sb);
    int filesize = sb.st_size;

    char *buffer = (char *) malloc(filesize + PAGE_SIZE);

    if (buffer == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    if (write(fd, buffer, filesize)!= filesize) {
        printf("Error writing to file\n");
        return 1;
    }

    int *ptr = (int *) (buffer + filesize);
    *ptr = 42;

    if (msync(buffer, filesize + PAGE_SIZE, MS_SYNC) == -1) {
        printf("Error syncing memory: %s\n", strerror(errno));
        return 1;
    }

    if (munmap(buffer, filesize + PAGE_SIZE) == -1) {
        printf("Error unmapping memory: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}