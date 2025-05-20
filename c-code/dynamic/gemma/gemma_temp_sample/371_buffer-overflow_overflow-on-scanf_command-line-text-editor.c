#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];

    printf("Enter text: ");
    scanf("%s", buffer);

    // Buffer overflow
    buffer[1024 - 1] = '\x0a';

    printf("Your text: %s", buffer);

    return 0;
}
