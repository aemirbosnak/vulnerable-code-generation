#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index = 11;

    // Accessing an element beyond the bounds of the array
    int value = arr[index];

    printf("Value: %d\n", value);

    return 0;
}
