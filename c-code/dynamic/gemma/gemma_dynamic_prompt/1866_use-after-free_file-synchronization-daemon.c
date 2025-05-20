#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char *filename = "/tmp/foo.txt";
    FILE *file = fopen(filename, "w");
    fprintf(file, "Hello, world!");
    fclose(file);

    struct stat st;
    stat(filename, &st);
    printf("File size: %d bytes\n", st.st_size);

    return 0;
}
