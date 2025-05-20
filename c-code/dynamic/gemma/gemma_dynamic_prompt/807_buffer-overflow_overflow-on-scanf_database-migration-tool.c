#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];

    printf("Enter database migration script: ");
    scanf("%s", buffer);

    // Overflow the buffer
    buffer[1024 - 1] = 'a';

    printf("Migrated script: %s\n", buffer);

    return 0;
}
