#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    char message[1024];

    printf("Enter a message: ");
    scanf("%s", message);

    // Overflow the buffer
    message[1024 - 1] = 'a';

    printf("Your message: %s", message);

    return 0;
}
