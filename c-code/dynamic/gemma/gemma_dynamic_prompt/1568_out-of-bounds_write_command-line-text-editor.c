#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = malloc(10);
    char *ptr = buffer;

    printf("Enter text: ");
    fgets(buffer, 10, stdin);

    // Out-of-bounds write
    ptr[-1] = 'A';

    printf("Your text: %s", buffer);

    free(buffer);
    return 0;
}
