#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    char message[1024];

    scanf("%s", message);

    // Overflow the buffer
    snprintf(buffer, 1024, "%s", message);

    printf("Message: %s", buffer);

    return 0;
}
