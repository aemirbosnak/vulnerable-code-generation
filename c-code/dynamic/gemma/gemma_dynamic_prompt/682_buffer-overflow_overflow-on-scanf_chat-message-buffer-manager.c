#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];

    printf("Enter a message: ");
    scanf("%s", buffer);

    // Overflow the buffer by writing more than the size of the buffer
    buffer[1024 - 1] = '\0';

    printf("Your message: %s", buffer);

    return 0;
}
