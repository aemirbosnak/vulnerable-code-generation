#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int key = 0xdeadbeef;
    int result = 0;

    // Integer overflow vulnerability
    result = key * 2;

    // Print the result
    printf("The result is: %d\n", result);

    return 0;
}
