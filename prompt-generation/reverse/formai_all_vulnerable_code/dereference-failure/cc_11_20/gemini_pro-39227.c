//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    struct stat statbuf;
    if (stat(argv[1], &statbuf) == -1)
    {
        perror("stat");
        return 1;
    }

    if (!S_ISREG(statbuf.st_mode))
    {
        printf("%s is not a regular file\n", argv[1]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    char *buf = malloc(statbuf.st_size);
    if (buf == NULL)
    {
        perror("malloc");
        close(fd);
        return 1;
    }

    if (read(fd, buf, statbuf.st_size) != statbuf.st_size)
    {
        perror("read");
        close(fd);
        free(buf);
        return 1;
    }

    char *ptr = buf;
    while (*ptr != '\0')
    {
        if (*ptr == 'e' && *(ptr + 1) == 'x' && *(ptr + 2) == 'e')
        {
            printf("Possible virus signature found at offset %ld\n", ptr - buf);
        }
        ptr++;
    }

    close(fd);
    free(buf);
    return 0;
}