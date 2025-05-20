#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buf = NULL;
    int size = 0;

    printf("Enter the size of the buffer: ");
    scanf("%d", &size);

    buf = malloc(size);

    if (buf == NULL)
    {
        printf("Error allocating memory.\n");
        exit(1);
    }

    printf("Enter the data to be encrypted: ");
    scanf("%s", buf);

    // Out-of-bounds read vulnerability
    buf[size] = 'A';

    free(buf);

    return 0;
}
