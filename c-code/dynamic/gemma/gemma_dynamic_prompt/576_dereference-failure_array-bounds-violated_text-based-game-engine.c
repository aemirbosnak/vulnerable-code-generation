#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int index = 10;

    // Attempt to dereference an array element beyond the bounds of the array
    int value = arr[index];

    // Print the value of the array element
    printf("The value of the array element is: %d\n", value);

    return 0;
}
