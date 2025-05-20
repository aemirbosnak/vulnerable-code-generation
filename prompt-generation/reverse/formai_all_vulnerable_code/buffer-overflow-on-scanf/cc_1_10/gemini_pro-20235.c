//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPTION_KEY "MY_SECRET_KEY"

unsigned char* encrypt(unsigned char* message) {
    size_t message_length = strlen(message);
    unsigned char* encrypted_message = (unsigned char*)malloc(message_length + 1);

    for (size_t i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i] ^ ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
    }

    encrypted_message[message_length] = '\0';

    return encrypted_message;
}

unsigned char* decrypt(unsigned char* encrypted_message) {
    size_t encrypted_message_length = strlen(encrypted_message);
    unsigned char* decrypted_message = (unsigned char*)malloc(encrypted_message_length + 1);

    for (size_t i = 0; i < encrypted_message_length; i++) {
        decrypted_message[i] = encrypted_message[i] ^ ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
    }

    decrypted_message[encrypted_message_length] = '\0';

    return decrypted_message;
}

int main() {
    // Get the message to be encrypted from the user.
    char message[100];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Encrypt the message using the secret key.
    unsigned char* encrypted_message = encrypt((unsigned char*)message);

    // Print the encrypted message to the console.
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the encrypted message using the secret key.
    unsigned char* decrypted_message = decrypt(encrypted_message);

    // Print the decrypted message to the console.
    printf("Decrypted message: %s\n", decrypted_message);

    // Free the memory allocated for the encrypted and decrypted messages.
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}