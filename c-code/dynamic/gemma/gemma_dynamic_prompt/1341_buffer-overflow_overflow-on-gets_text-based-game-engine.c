#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10];

    printf("Enter a message: ");
    gets(buffer);

    printf("Your message: %s", buffer);

    return 0;
}
