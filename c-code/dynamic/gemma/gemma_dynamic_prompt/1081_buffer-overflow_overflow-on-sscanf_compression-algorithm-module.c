#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10];
    scanf("%s", buffer);

    // Overflow the buffer by reading more than the size of the buffer
    scanf("%s", buffer);

    printf("The buffer is overflowed!\n");

    return 0;
}
