#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    arr = (int *)malloc(10);

    // Use after free vulnerability
    free(arr);
    arr[0] = 10;

    printf("%d", arr[0]);

    return 0;
}
