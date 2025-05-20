#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    int size = 0;

    printf("Enter audio stream data: ");
    gets(buffer);

    size = strlen(buffer) + 1;
    buffer[size - 1] = '\0';

    printf("Decoded audio stream: %s\n", buffer);

    return 0;
}
