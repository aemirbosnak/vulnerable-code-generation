#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n = 0x7FFFFFFF;
    int m = n + 1;

    printf("n = %x, m = %x\n", n, m);

    return 0;
}
