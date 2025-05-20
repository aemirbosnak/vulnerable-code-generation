#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
    int *ptr = NULL;
    *ptr = 10;

    printf("Value of the pointer: %d", *ptr);
}
