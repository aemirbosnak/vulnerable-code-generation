#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 2147483647;
    int b = 2147483647;
    int c = a + b;

    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);

    return 0;
}
