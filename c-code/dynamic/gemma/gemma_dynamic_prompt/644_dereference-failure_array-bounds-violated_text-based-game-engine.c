#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **arr = NULL;
    int i = 0;

    arr = (char **)malloc(10 * sizeof(char *));
    for (i = 0; i < 10; i++)
    {
        arr[i] = (char *)malloc(20 * sizeof(char));
    }

    arr[i][0] = 'H';
    printf("%c", arr[i][0]);

    free(arr);
    return 0;
}
