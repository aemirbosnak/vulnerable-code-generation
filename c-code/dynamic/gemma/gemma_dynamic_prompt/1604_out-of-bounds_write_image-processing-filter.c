#include <string.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    uint8_t *img = malloc(1024);
    img[1024] = 255; // Out of bounds write
    free(img);

    return 0;
}
