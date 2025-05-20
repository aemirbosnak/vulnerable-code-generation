#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    char buffer[10];
    int index = 0;

    printf("Enter text: ");
    scanf("%s", buffer);

    while (index < 10)
    {
        printf("%c", buffer[index]);
        index++;
    }

    return 0;
}
