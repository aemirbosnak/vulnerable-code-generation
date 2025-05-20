#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data = 0x80000000;
    int decoded_data = data * 2;
    printf("%d", decoded_data);
    return 0;
}
