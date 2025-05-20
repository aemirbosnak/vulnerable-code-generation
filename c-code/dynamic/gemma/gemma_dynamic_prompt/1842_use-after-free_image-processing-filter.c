#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = NULL;
    ptr = malloc(10);
    free(ptr);

    // Use after free vulnerability
    *ptr = 5;

    printf("%d", *ptr);

    return 0;
}
