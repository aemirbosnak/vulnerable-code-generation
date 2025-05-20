#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *filename = malloc(1024);
    FILE *fp = fopen("test.txt", "w");
    fscanf(stdin, "%s", filename);
    fp = fopen(filename, "w");
    fprintf(fp, "Hello, world!");
    fclose(fp);
    free(filename);
    return 0;
}
