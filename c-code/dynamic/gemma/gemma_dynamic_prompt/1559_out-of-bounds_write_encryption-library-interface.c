#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *key = "secret";
    char *message = "Hello, world!";
    int message_length = strlen(message);
    int key_length = strlen(key);

    // Allocate memory for the encrypted message
    char *encrypted_message = (char *)malloc((message_length + key_length) * 2);

    // Encrypt the message
    int i = 0;
    for (i = 0; i < message_length; i++)
    {
        encrypted_message[i] = message[i] ^ key[i % key_length];
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Free the allocated memory
    free(encrypted_message);

    return 0;
}
