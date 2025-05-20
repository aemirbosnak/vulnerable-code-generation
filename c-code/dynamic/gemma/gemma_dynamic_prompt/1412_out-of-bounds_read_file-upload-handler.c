#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("large_file.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Read file contents out of bounds
    unsigned char buffer[1024 * 1024];
    size_t read_bytes = fread(buffer, 1, 10 * 1024 * 1024, file);

    fclose(file);

    return 0;
}
