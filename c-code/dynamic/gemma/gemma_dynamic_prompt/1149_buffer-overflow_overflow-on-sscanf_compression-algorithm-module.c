#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    char input[1024];
    int i = 0;

    printf("Enter data: ");
    scanf("%s", input);

    while (input[i] != '\0')
    {
        buffer[i] = input[i];
        i++;
    }

    buffer[i] = '\0';

    printf("Compressed data: %s", buffer);

    return 0;
}
