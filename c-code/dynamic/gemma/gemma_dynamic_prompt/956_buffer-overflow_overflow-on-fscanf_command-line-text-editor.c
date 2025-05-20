#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];

    printf("Enter text: ");
    fscanf(stdin, "%s", buffer);

    printf("You entered: %s", buffer);

    return 0;
}
