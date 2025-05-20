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

    printf("Enter file name: ");
    scanf("%s", buffer);

    // Overflow on scanf
    for (i = 0; buffer[i] != '\0'; i++)
    {
        buffer[i] = 'A';
    }

    printf("File name: %s\n", buffer);

    return 0;
}
