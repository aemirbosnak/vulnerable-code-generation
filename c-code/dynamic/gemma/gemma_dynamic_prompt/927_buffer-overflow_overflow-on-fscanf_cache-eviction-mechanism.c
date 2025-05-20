#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    char buffer[1024];

    printf("Enter data: ");
    scanf("%s", buffer);

    // Overflow on fscanf
    scanf("%c", buffer);

    printf("Data stored: %s", buffer);

    return 0;
}
