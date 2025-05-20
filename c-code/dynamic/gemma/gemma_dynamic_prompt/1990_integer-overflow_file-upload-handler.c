#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int file_size = 1000000000; // 1GB
    char *file_data = malloc(file_size);
    FILE *file = fopen("test.jpg", "w");

    fwrite(file_data, file_size, 1, file);
    fclose(file);

    free(file_data);
    return 0;
}
