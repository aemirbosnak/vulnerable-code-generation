#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Write out of bounds
    arr[100] = 100;

    // Print the array
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
