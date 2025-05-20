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

    printf("Array element at index %d: ", arr[index]);

    // This line deliberately dereferences an array element beyond the bounds of the array, causing a vulnerability
    printf("%d", arr[index]);

    return 0;
}
