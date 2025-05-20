#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int index = 10;

    // Attempt to dereference an array element beyond bounds
    int value = array[index];

    // Print the value
    printf("Value: %d\n", value);

    return 0;
}
