#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[1024];
    scanf("%s", buffer);

    // Overflow the buffer
    buffer[1024 - 1] = 'a';

    printf("The captured packet is: %s", buffer);

    return 0;
}
