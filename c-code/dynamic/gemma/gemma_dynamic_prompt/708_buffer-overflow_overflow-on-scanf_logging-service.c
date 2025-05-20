#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];

    printf("Enter a message: ");
    scanf("%s", buffer);

    printf("Your message: %s", buffer);

    return 0;
}
