#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *file_data = NULL;
    int file_size = 0;

    // Allocate memory for file data
    file_data = malloc(1024);

    // Read file data from client
    file_size = read(0, file_data, 1024);

    // Free memory allocated for file data
    free(file_data);

    return 0;
}
