#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
    int a = 1;
    int b = 2;
    int c = a + b;
    int d = c * 3;
    int e = d / 4;
    int f = e * 5;

    printf("The value of e is: %d", e);

    return 0;
}
