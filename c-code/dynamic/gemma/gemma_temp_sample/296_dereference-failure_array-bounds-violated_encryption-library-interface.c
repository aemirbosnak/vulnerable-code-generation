#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int index = 10;

    // Array bounds violation
    int value = arr[index];

    // Use the value
    printf("%d", value);

    return 0;
}
