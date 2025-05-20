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
    fscanf(stdin, "%s", buffer);

    if (strlen(buffer) > 1024)
    {
        printf("Error: Buffer overflow.\n");
    }
    else
    {
        printf("Message: %s\n", buffer);
    }

    return 0;
}
