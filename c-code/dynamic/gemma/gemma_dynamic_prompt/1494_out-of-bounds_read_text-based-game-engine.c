#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    int i = 0;

    printf("Enter text: ");
    fgets(buffer, 1024, stdin);

    for (i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] >= 'a' && buffer[i] <= 'z')
        {
            buffer[i] = buffer[i] - 32;
        }
    }

    printf("Modified text: ");
    puts(buffer);

    return 0;
}
