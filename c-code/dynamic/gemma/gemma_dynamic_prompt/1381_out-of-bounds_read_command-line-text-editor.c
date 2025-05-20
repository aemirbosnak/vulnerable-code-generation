#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buf[1024];
    int i = 0;

    printf("Enter text: ");
    fgets(buf, 1024, stdin);

    for (i = 0; buf[i] != '\0'; i++)
    {
        if (buf[i] >= 'a' && buf[i] <= 'z')
        {
            buf[i] = buf[i] - 32;
        }
    }

    printf("Modified text: ");
    puts(buf);

    return 0;
}
