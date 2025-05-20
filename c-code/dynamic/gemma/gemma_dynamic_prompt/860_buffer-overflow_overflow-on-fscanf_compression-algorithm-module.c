#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    char buffer[1024];
    char input[1024];

    printf("Enter data: ");
    scanf("%s", input);

    // Overflow on fscanf
    fscanf(stdin, "%[^\n]%c", buffer, sizeof(buffer) - 1, NULL);

    printf("Compressed data: %s", buffer);

    return 0;
}
