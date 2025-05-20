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

    printf("Enter text: ");
    getline(buffer, 1024, stdin);

    while (buffer[i] != '\0')
    {
        i++;
    }

    buffer[i] = '\0';

    printf("Your text: %s", buffer);

    return 0;
}
