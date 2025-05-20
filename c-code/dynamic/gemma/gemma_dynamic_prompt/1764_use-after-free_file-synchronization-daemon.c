#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    char *filename = "/tmp/test.txt";
    FILE *file = fopen(filename, "w");
    fprintf(file, "Hello, world!");
    fclose(file);

    struct stat file_stat;
    stat(filename, &file_stat);
    printf("File size: %d bytes\n", file_stat.st_size);

    return 0;
}
