#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *arr = NULL;
    int size = 0;
    int i = 0;

    while (1)
    {
        printf("Enter the size of the array: ");
        scanf("%d", &size);

        if (size > 0)
        {
            arr = (int *)malloc(size * sizeof(int));
            break;
        }
        else
        {
            printf("Invalid size.\n");
        }
    }

    for (i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }

    printf("The array is:");
    for (i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }

    free(arr);

    return 0;
}
