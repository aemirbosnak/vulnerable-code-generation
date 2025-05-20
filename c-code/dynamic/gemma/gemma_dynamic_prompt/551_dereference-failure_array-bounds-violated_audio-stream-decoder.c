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

    // Intentionally dereference an array element beyond the bounds of the array
    arr[i] = 10;

    printf("The value of the element at index %d is: %d", i, arr[i]);

    return 0;
}
