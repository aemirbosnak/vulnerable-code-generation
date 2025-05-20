#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    char data[1024];
    int i = 0;

    printf("Enter data: ");
    scanf("%s", buffer);

    for (i = 0; buffer[i] != '\0'; i++)
    {
        data[i] = buffer[i];
    }

    printf("Decoded data: ");
    for (i = 0; data[i] != '\0'; i++)
    {
        printf("%c ", data[i]);
    }

    printf("\n");

    return 0;
}
