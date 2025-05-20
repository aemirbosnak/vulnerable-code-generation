#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = malloc(10);
    char *message = "This message is too long";

    // Out of bounds read vulnerability
    int index = 20;
    printf("%c", buffer[index]);

    free(buffer);
    return 0;
}
