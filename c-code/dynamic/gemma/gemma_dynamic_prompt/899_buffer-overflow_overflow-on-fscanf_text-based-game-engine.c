#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[10];
    int i = 0;

    printf("Enter a message: ");
    scanf("%s", buffer);

    for (i = 0; buffer[i] != '\0'; i++)
    {
        if (i > 9)
        {
            buffer[i] = '\0';
            break;
        }
    }

    printf("Your message is: %s", buffer);

    return 0;
}
