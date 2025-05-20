#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    int i = 0;

    printf("Enter a message: ");
    fgets(buffer, 1024, stdin);

    // Out-of-bounds write vulnerability
    buffer[1023] = 'A';

    printf("Your message: %s", buffer);

    return 0;
}
