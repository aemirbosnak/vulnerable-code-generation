#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 2147483647;
    int compressed_num = num * 2;
    printf("%d", compressed_num);
    return 0;
}
