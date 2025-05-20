#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 10;
    int* arr = (int*)malloc(size * sizeof(int));
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    free(arr[0]);
    free(arr[1]);

    printf("The remaining elements in the array are:");
    for (int i = 2; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }

    return 0;
}
