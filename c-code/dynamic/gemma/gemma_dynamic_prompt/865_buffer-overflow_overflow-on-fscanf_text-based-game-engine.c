#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    char buffer[1024];
    int i = 0;

    printf("Enter a message: ");
    fscanf(stdin, "%s", buffer);

    for (i = 0; buffer[i] != '\0'; i++)
    {
        printf("%c", buffer[i]);
    }

    return 0;
}
