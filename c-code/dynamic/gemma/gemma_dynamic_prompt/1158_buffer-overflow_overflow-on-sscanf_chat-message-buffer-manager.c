#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10];
    char message[100];

    printf("Enter a message: ");
    scanf("%s", message);

    // Overflow on sscanf
    snprintf(buffer, 10, "%s", message);

    printf("Your message: %s\n", buffer);

    return 0;
}
