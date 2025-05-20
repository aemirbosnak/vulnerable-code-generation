#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[10];
    int i;

    printf("Enter a string: ");
    fscanf(stdin, "%s", buffer);

    for (i = 0; buffer[i] != '\0'; i++)
    {
        printf("%c", buffer[i]);
    }

    return 0;
}
