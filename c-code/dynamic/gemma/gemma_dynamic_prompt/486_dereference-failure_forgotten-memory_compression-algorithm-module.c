#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* a = NULL;
    *a = 10;
    printf("%d", *a);
    return 0;
}
