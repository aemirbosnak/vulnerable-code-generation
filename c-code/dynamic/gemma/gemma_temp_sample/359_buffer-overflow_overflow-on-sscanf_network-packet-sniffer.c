#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    char data[1024];

    printf("Enter packet data: ");
    scanf("%s", buffer);

    // Deliberate overflow on sscanf
    scanf("%s", data);

    // Print captured data
    printf("Captured data: %s", data);

    return 0;
}
