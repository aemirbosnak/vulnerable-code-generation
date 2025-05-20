#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10];
    char input[100];

    printf("Enter a message: ");
    scanf("%s", input);

    // Overflow the buffer
    sprintf(buffer, "This is a message that is longer than the buffer size, but I will write it anyway.", input);

    printf("Your message is: %s", buffer);

    return 0;
}
