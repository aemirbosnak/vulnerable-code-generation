//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define KILOBYTE    1024
#define MEGABYTE    (KILOBYTE * 1024)
#define GIGABYTE    (MEGABYTE * 1024)
#define TERABYTE    (GIGABYTE * 1024)

int main(int argc, char *argv[])
{
    struct stat st;
    int i;

    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (stat(argv[1], &st) == -1) {
        perror(argv[1]);
        return EXIT_FAILURE;
    }

    if (!S_ISDIR(st.st_mode)) {
        printf("%s is not a directory\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("Analyzing disk space usage for %s\n", argv[1]);

    i = 0;
    while (i < st.st_size) {
        if (st.st_size < KILOBYTE) {
            printf("%d bytes\n", st.st_size);
        } else if (st.st_size < MEGABYTE) {
            printf("%.2f kilobytes\n", (float)st.st_size / KILOBYTE);
        } else if (st.st_size < GIGABYTE) {
            printf("%.2f megabytes\n", (float)st.st_size / MEGABYTE);
        } else if (st.st_size < TERABYTE) {
            printf("%.2f gigabytes\n", (float)st.st_size / GIGABYTE);
        } else {
            printf("%.2f terabytes\n", (float)st.st_size / TERABYTE);
        }
        i += KILOBYTE;
    }

    return EXIT_SUCCESS;
}