#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **arr = NULL;
    arr = malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = malloc(10 * sizeof(char));
    }

    // Attempt to dereference an element beyond the bounds of the array
    arr[10] = "Hello, world!";

    free(arr);
    return 0;
}
