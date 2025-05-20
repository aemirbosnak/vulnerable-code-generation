//Falcon-180B DATASET v1.0 Category: System administration ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

char *program_name;

void usage(void)
{
    fprintf(stderr, "Usage: %s <file>\n", program_name);
    exit(1);
}

int main(int argc, char *argv[])
{
    program_name = argv[0];

    if (argc!= 2) {
        usage();
    }

    FILE *fp;
    char *buf = malloc(BUF_SIZE);
    int fd;
    int c;
    int count = 0;

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: Could not open file %s.\n", argv[1]);
        exit(1);
    }

    while ((c = fgetc(fp))!= EOF) {
        if (c == '\n') {
            count++;
        }
    }

    rewind(fp);
    fclose(fp);

    if ((fd = open(argv[1], O_RDWR)) == -1) {
        fprintf(stderr, "Error: Could not open file %s.\n", argv[1]);
        exit(1);
    }

    lseek(fd, 0, SEEK_SET);

    while ((c = getc(fp))!= EOF) {
        if (c == '\n') {
            count++;
            if (count % 10 == 0) {
                printf("\r%d lines processed...", count);
                fflush(stdout);
            }
        }
        write(fd, &c, 1);
    }

    close(fd);
    fclose(fp);

    printf("\n%d lines processed.\n", count);

    return 0;
}