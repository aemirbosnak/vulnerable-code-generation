//Falcon-180B DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE_LEN 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <file> <old_string> <new_string>\n", argv[0]);
        return 1;
    }

    char *file = argv[1];
    char *old_str = argv[2];
    char *new_str = argv[3];

    int fd = open(file, O_RDWR);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        printf("Error getting file status: %s\n", strerror(errno));
        close(fd);
        return 1;
    }

    size_t file_size = sb.st_size;
    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        close(fd);
        return 1;
    }

    if (read(fd, buffer, file_size)!= file_size) {
        printf("Error reading file: %s\n", strerror(errno));
        free(buffer);
        close(fd);
        return 1;
    }

    char *pos = buffer;
    while ((pos = strstr(pos, old_str))!= NULL) {
        size_t len = strlen(new_str);
        if (len > strlen(old_str)) {
            printf("Error: new string is longer than old string\n");
            free(buffer);
            close(fd);
            return 1;
        }

        memmove(pos + len, pos + strlen(old_str), file_size - (pos - buffer) - strlen(old_str) + 1);
        memcpy(pos, new_str, len);
        pos += len;
    }

    lseek(fd, 0, SEEK_SET);
    if (write(fd, buffer, file_size)!= file_size) {
        printf("Error writing file: %s\n", strerror(errno));
        free(buffer);
        close(fd);
        return 1;
    }

    free(buffer);
    close(fd);

    printf("File updated successfully\n");
    return 0;
}