#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];

    printf("Enter file data: ");
    scanf("%s", buffer);

    // Overflow on scanf
    buffer[1024 - 1] = '\0';

    printf("File data: %s", buffer);

    return 0;
}
