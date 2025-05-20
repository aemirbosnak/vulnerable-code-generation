#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0x7fffffff;
    int b = 0x7ffffff0;
    int c = a + b;

    printf("The result of the addition is: %d\n", c);

    return 0;
}
