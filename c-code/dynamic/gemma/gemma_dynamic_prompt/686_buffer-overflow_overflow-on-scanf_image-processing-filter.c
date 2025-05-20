#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    int i;

    printf("Enter a command: ");
    scanf("%s", buffer);

    for (i = 0; buffer[i] != '\0'; i++)
    {
        printf("%c", buffer[i]);
    }

    printf("\n");

    return 0;
}
