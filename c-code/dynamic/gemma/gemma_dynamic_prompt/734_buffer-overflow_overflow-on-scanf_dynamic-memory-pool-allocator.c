#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = NULL;
    int size = 0;

    scanf("Enter the size of the buffer: ", &size);

    buffer = malloc(size);

    if (buffer == NULL)
    {
        printf("Error allocating memory.\n");
        return 1;
    }

    printf("Enter data into the buffer: ");

    scanf("%s", buffer);

    printf("Data stored in the buffer: %s\n", buffer);

    free(buffer);

    return 0;
}
