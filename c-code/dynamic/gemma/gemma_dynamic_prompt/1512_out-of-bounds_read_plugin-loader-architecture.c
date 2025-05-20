#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("/etc/passwd", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    unsigned int offset = 0xdeadbeef;
    char buffer[1024];
    fseek(file, offset, SEEK_SET);
    size_t read_size = fread(buffer, 1, 1024, file);

    if (read_size > 0)
    {
        printf("Read data: %s", buffer);
    }
    else
    {
        printf("No data read");
    }

    fclose(file);
    return 0;
}
