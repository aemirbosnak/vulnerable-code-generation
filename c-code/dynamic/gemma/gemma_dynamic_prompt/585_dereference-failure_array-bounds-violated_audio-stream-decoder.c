#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* arr = (int*)malloc(10 * sizeof(int));
    arr[10] = 5; // Array bounds violation

    printf("%d", arr[10]);

    free(arr);

    return 0;
}
