#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    char buffer[10];
    int i;

    printf("Enter a word: ");
    scanf("%s", buffer);

    for (i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] < 0 || buffer[i] > 127)
        {
            printf("Error: Invalid character.\n");
            return 1;
        }
    }

    printf("Word: %s\n", buffer);

    return 0;
}
