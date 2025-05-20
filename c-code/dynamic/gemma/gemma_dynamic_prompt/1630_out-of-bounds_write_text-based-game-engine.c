#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    char buffer[1024];
    int index = 0;

    printf("Enter a message: ");
    fgets(buffer, 1024, stdin);

    // Write out of bounds
    buffer[index++] = 'a';
    buffer[index++] = 'b';
    buffer[index++] = 'c';

    printf("Your message: %s", buffer);

    return 0;
}
