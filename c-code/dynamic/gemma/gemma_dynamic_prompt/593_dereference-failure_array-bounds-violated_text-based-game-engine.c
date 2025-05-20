#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int i = 0;

    // Loop through the array and dereference the element at index i
    for (i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}
