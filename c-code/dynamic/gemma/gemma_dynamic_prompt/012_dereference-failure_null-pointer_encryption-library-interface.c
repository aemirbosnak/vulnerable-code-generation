#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = NULL;
    *ptr = 42;

    printf("The value of the pointer is: %d", *ptr);

    return 0;
}
