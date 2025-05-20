#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10];
    char input[1024];

    printf("Enter a string: ");
    scanf("%s", input);

    // Buffer overflow vulnerability
    sprintf(buffer, "The input is: %s", input);

    printf("The compressed output is: %s", buffer);

    return 0;
}
