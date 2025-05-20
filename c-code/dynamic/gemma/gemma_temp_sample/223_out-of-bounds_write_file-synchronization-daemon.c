#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *filename = "test.txt";
    FILE *file = fopen(filename, "w");
    char buffer[1024];

    // Write beyond the buffer size
    buffer[1024] = 'a';
    fwrite(buffer, 1024, 1, file);

    fclose(file);

    return 0;
}
