#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int* arr = NULL;
    int i = 0;

    arr = (int*)malloc(10 * sizeof(int));
    for (i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
    }

    free(arr);
    arr = NULL;

    arr = (int*)malloc(10 * sizeof(int));
    arr[10] = 10; // This line will cause a dereference failure

    printf("%d", arr[10]); // This line will crash

    return 0;
}
