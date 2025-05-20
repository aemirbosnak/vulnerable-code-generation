#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10] = "";
    char key[20] = "secret key";

    printf("Enter a message: ");
    scanf("%s", buffer);

    // Overflow the buffer
    buffer[10] = key[0];

    // Encrypt the message
    // (This code would normally include encryption logic)

    // Print the encrypted message
    printf("Encrypted message: %s", buffer);

    return 0;
}
