#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
    int a = 10;
    int b = 2147483647;
    int c = a * b;
    int d = c / 2;

    printf("a: %d\nb: %d\nc: %d\nd: %d\n", a, b, c, d);

    return 0;
}
