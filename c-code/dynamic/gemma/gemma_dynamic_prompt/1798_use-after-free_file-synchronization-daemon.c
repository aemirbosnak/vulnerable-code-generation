#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *file_name = malloc(1024);
    FILE *file_ptr = fopen("test.txt", "w");
    strcpy(file_name, "test.txt");
    fprintf(file_ptr, "Hello, world!");
    fclose(file_ptr);
    free(file_name);
    return 0;
}
