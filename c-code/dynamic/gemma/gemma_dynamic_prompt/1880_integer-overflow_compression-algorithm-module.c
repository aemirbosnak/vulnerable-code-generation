#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0;

    a = 2147483647;
    b = 2147483647;
    c = a + b;

    d = c / 2;
    e = d * d;
    f = e + 1;
    g = f * f;

    printf("The result is: %d", g);

    return 0;
}
