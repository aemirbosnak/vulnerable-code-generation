#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* arr = NULL;
    *arr = 10;
    printf("%d", *arr);
    free(arr);
    return 0;
}
