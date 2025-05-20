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

    printf("Enter data: ");
    scanf("%s", buffer);

    while (buffer[i] != '\0')
    {
        i++;
    }

    printf("Data stored: %s", buffer);

    return 0;
}
