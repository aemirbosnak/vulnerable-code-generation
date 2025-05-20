#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[16];
    char key[16] = "secret key";

    printf("Enter a message: ");
    scanf("%s", buffer);

    // Overflow the buffer
    buffer[15] = key[0];

    // Use the encrypted message
    printf("Your encrypted message is: %s", buffer);

    return 0;
}
