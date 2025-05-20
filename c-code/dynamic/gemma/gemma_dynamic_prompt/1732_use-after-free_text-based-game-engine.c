#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = malloc(1024);
    int size = 0;

    printf("Enter a command: ");
    getline(buffer, &size, stdin);

    printf("You entered: %s", buffer);

    free(buffer);

    return 0;
}
