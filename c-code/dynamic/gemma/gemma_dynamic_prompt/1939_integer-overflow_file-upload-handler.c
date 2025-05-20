#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int upload_size = 0;
    scanf("%d", &upload_size);

    // Integer overflow vulnerability
    int file_size = upload_size * 1024 * 1024;
    if (file_size < 0)
    {
        printf("Error: file size is too large.\n");
    }
    else
    {
        printf("File size: %d bytes.\n", file_size);
    }

    return 0;
}
