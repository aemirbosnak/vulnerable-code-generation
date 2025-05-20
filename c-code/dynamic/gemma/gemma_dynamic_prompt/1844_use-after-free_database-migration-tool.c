#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = NULL;
    *ptr = malloc(10);
    free(ptr);

    // Use after free vulnerability - attempts to write to a freed memory location
    *ptr = "Hello, world!";
    printf("%s", *ptr);

    return 0;
}
