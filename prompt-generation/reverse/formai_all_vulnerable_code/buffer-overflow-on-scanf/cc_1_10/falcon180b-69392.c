//Falcon-180B DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Prompt the user for a message to encrypt
    char message[100];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message using a simple Caesar cipher
    int key = rand() % 26; // Generate a random key between 0 and 25
    char encrypted_message[100];
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            message[i] = (char) (((int) message[i] - 65 + key) % 26 + 65); // Shift the character by the key and wrap around if necessary
        }
        encrypted_message[i] = message[i];
        i++;
    }
    encrypted_message[i] = '\0';

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Prompt the user for a key to decrypt the message
    int decryption_key;
    printf("Enter a key to decrypt the message: ");
    scanf("%d", &decryption_key);

    // Decrypt the message using the provided key
    char decrypted_message[100];
    i = 0;
    while (encrypted_message[i]!= '\0') {
        if (isalpha(encrypted_message[i])) {
            encrypted_message[i] = (char) (((int) encrypted_message[i] - 65 - decryption_key) % 26 + 65); // Shift the character back by the key and wrap around if necessary
        }
        decrypted_message[i] = encrypted_message[i];
        i++;
    }
    decrypted_message[i] = '\0';

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}