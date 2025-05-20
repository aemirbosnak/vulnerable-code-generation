#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **arr = NULL;
    arr = (char**)malloc(10 * sizeof(char*));

    for (int i = 0; i < 10; i++)
    {
        arr[i] = (char*)malloc(10 * sizeof(char));
    }

    arr[10][0] = 'a';
    printf("%c", arr[10][0]);

    for (int i = 0; i < 10; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
