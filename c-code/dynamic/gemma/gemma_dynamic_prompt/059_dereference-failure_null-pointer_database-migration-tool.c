#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p = NULL;
    *p = 10;
    printf("%d", *p);
    return 0;
}
