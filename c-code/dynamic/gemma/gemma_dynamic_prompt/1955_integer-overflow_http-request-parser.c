#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[100];
    int i = 0;
    int length = 0;

    printf("Enter HTTP request: ");
    fgets(buffer, 100, stdin);

    // Iterate over the buffer to find the end of the request line
    for (i = 0; buffer[i] != '\n'; i++)
    {
        length++;
    }

    // Allocate memory for the request line
    char *request = malloc(length + 1);

    // Copy the request line from the buffer
    memcpy(request, buffer, length);

    // Print the request line
    printf("Request line: %s\n", request);

    return 0;
}
