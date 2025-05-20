#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *ptr = NULL;
    *ptr = 10;
    printf("%d", *ptr);
    return 0;
}
