#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    int len = 0;

    printf("Enter a message: ");
    scanf("%s", buffer);

    len = strlen(buffer);

    if (len > 1024)
    {
        printf("Error: Message too long.\n");
    }
    else
    {
        printf("Your message: %s\n", buffer);
    }

    return 0;
}
