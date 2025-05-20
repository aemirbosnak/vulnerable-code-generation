#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = NULL;
    int data = 0;

    // Attempt to dereference a NULL pointer
    *ptr = data;

    // Print the result of the dereference operation
    printf("The value of the dereferenced pointer is: %d", *ptr);

    return 0;
}
