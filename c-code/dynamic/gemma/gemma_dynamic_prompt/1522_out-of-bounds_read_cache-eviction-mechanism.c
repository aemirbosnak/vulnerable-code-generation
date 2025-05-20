#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int index = 11;

    // Attempt to access element beyond the array bounds
    arr[index] = 11;

    printf("Element at index %d is: %d\n", index, arr[index]);

    return 0;
}
