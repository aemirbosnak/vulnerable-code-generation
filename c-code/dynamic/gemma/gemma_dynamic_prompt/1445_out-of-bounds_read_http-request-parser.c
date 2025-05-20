#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char *buffer = malloc(1024);
    char *ptr = buffer;

    // Read the request header
    printf("Enter the request header: ");
    scanf("%s", buffer);

    // Out-of-bounds read
    ptr = buffer + 1024;

    // Print the parsed header
    printf("The parsed header is: %s", ptr);

    return 0;
}
