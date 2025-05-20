#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data = 0xDEADBEEF;
    int out_of_bounds = data + 10;

    printf("Value of out_of_bounds variable: %d\n", out_of_bounds);

    return 0;
}
