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

    // Overflow the buffer
    buffer[10] = 'A';

    printf("%s", buffer);

    return 0;
}
