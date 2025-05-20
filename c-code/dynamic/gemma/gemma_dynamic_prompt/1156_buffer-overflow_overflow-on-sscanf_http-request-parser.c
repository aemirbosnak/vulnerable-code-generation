#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10];
    char input[20];

    printf("Enter an HTTP request header: ");
    scanf("%s", input);

    // Overflow on sscanf
    sscanf(input, "%s", buffer);

    printf("The parsed header is: %s\n", buffer);

    return 0;
}
