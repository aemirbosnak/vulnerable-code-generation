#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 12;
    int compressed_num = 0;

    compressed_num = num * 2 - 1;

    printf("Original number: %d\n", num);
    printf("Compressed number: %d\n", compressed_num);

    return 0;
}
