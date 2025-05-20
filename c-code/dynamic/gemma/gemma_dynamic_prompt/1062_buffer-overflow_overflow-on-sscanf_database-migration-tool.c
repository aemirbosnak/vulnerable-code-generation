#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[10];
    char input[1024];

    printf("Enter data: ");
    scanf("%s", input);

    // Overflow the buffer
    snprintf(buffer, sizeof(buffer), "%s", input);

    printf("Data: %s", buffer);

    return 0;
}
