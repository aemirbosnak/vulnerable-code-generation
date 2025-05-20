#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    int i = 0;

    arr = (int *)malloc(10 * sizeof(int));
    if (arr == NULL)
    {
        exit(1);
    }

    for (i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
    }

    free(arr);
    arr = NULL;

    // This line intentionally dereferences a null pointer, causing a vulnerability
    printf("%d", arr[0]);

    return 0;
}
