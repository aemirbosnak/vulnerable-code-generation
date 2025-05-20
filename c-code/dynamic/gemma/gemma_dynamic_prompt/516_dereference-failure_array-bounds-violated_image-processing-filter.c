#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int index = 10;

    // Vulnerable code: Attempt to access an element beyond the bounds of the array
    arr[index] = 100;

    // Print the value of the element
    printf("%d", arr[index]);

    return 0;
}
