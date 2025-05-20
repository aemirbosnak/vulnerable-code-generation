//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Declare variables for the message and secret key
    char message[100];
    char key[100];

    // Get the message and secret key from the user
    printf("Enter the message: ");
    scanf("%s", message);
    printf("Enter the secret key: ");
    scanf("%s", key);

    // Calculate the length of the message and the key
    int msg_len = strlen(message);
    int key_len = strlen(key);

    // Check if the message and key lengths are equal
    if (msg_len != key_len) {
        printf("Error: message and key lengths are not equal.\n");
        return 1;
    }

    // Declare a new string for the encrypted message
    char encrypted_msg[100];

    // Loop through each character in the message and key
    for (int i = 0; i < msg_len; i++) {

        // Extract the ASCII codes for the current characters in the message and key
        int msg_char = (int) message[i];
        int key_char = (int) key[i];

        // Add the ASCII codes together and make sure the result is less than or equal to 127
        int encrypted_char = (msg_char + key_char) % 128;

        // Convert the encrypted ASCII code back into a character and add it to the encrypted message
        encrypted_msg[i] = (char) encrypted_char;
    }

    // Print out the encrypted message
    printf("Encrypted message: %s\n", encrypted_msg);

    // Declare a new string for the decrypted message
    char decrypted_msg[100];

    // Loop through each character in the encrypted message and key
    for (int i = 0; i < msg_len; i++) {

        // Extract the ASCII codes for the current characters in the encrypted message and key
        int encrypted_char = (int) encrypted_msg[i];
        int key_char = (int) key[i];

        // Subtract the ASCII codes and add 128 if the result is negative
        int decrypted_char = (encrypted_char - key_char);
        if (decrypted_char < 0) {
            decrypted_char += 128;
        }

        // Convert the decrypted ASCII code back into a character and add it to the decrypted message
        decrypted_msg[i] = (char) decrypted_char;
    }

    // Print out the decrypted message
    printf("Decrypted message: %s\n", decrypted_msg);

    return 0;
}