//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BLKSIZE 512

int main(int argc, char *argv[])
{
    int fd, i, j, k, l, m, n;
    char buf[BLKSIZE];
    char *zeros = calloc(BLKSIZE, sizeof(char));
    struct stat st;

    if (argc < 2)
    {
        printf("Usage: %s <device>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDWR);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    if (fstat(fd, &st) < 0)
    {
        perror("fstat");
        return 1;
    }

    for (i = 0; i < st.st_size; i += BLKSIZE)
    {
        if (read(fd, buf, BLKSIZE) < 0)
        {
            perror("read");
            return 1;
        }

        for (j = 0; j < BLKSIZE; j++)
        {
            if (buf[j] != 0)
            {
                break;
            }
        }

        if (j == BLKSIZE)
        {
            if (lseek(fd, i, SEEK_SET) < 0)
            {
                perror("lseek");
                return 1;
            }

            if (write(fd, zeros, BLKSIZE) < 0)
            {
                perror("write");
                return 1;
            }
        }
        else
        {
            break;
        }
    }

    close(fd);

    return 0;
}