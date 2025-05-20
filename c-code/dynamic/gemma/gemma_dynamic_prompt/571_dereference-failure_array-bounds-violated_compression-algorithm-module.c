#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    arr[10] = 11; // Array bounds violation

    for (i = 0; i < 11; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
