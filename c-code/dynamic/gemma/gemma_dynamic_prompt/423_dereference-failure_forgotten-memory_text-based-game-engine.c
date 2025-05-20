#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **data = NULL;
    int i = 0;

    // Allocate memory for data
    data = malloc(10 * sizeof(char *));
    if (data == NULL)
    {
        return 1;
    }

    // Fill data with random characters
    for (i = 0; i < 10; i++)
    {
        data[i] = rand() % 256;
    }

    // Dereference failure - try to access data[10]
    printf("%c", data[10]);

    // Free memory
    free(data);

    return 0;
}
