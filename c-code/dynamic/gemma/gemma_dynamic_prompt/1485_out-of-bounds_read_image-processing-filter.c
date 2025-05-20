#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int img[1024] = {0};
    img[1024] = 1; // Out of bounds access
    printf("%d", img[1024]);
    return 0;
}
