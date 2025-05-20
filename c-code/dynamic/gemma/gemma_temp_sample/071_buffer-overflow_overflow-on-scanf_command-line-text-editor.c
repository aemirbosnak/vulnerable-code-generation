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
    scanf("%s", buffer);

    for (i = 0; buffer[i] != '\0'; i++)
    {
        printf("%c", buffer[i]);
    }

    return 0;
}
