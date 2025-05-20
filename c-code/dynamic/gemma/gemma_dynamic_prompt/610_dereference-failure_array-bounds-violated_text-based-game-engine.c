#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int i = 0;

    // Array bounds violation
    arr[i] = 10;

    printf("The value of arr[i] is: %d", arr[i]);

    return 0;
}
