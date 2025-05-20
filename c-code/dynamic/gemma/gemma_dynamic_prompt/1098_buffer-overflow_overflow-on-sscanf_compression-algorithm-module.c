#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    char input[1024];

    printf("Enter a string: ");
    scanf("%s", input);

    // Overflow the buffer
    sprintf(buffer, "The input string is: %s", input);

    printf("%s\n", buffer);

    return 0;
}
