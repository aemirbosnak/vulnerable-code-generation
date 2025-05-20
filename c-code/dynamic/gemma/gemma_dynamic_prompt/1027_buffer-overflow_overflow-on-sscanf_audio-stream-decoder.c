#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    char input[1024];

    printf("Enter audio stream data: ");
    scanf("%s", input);

    // Overflow on sscanf
    sscanf(input, "%1024s", buffer);

    printf("Decoded audio stream: \n");
    printf("%s", buffer);

    return 0;
}
