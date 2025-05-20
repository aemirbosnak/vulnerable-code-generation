#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = NULL;
    int value = 0;

    // Attempt to dereference the null pointer
    value = *(ptr);

    // Print the result
    printf("The value is: %d\n", value);

    return 0;
}
