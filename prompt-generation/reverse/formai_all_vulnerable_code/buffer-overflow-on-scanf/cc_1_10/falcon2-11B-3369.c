//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: surprised
#include <stdio.h>
#include <string.h>

// Function to encrypt a message using the Caesar Cipher
void encrypt(char *message, int key, int salt) {
    int len = strlen(message);
    int i;

    // Encrypt each character in the message
    for (i = 0; i < len; i++) {
        // Get the ASCII value of the character
        int ascii = (int) message[i];

        // Encrypt the character using the Caesar Cipher
        if (ascii >= 65 && ascii <= 90) {
            ascii += key + salt;
            if (ascii > 90) {
                ascii -= 26;
            }
        }
        else if (ascii >= 97 && ascii <= 122) {
            ascii += key + salt;
            if (ascii > 122) {
                ascii -= 26;
            }
        }

        // Convert the ASCII value back to a character
        message[i] = (char) ascii;
    }
}

int main() {
    char message[100];
    int key, salt;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove the newline character

    // Prompt the user to enter a key and salt
    printf("Enter a key: ");
    scanf("%d", &key);
    printf("Enter a salt: ");
    scanf("%d", &salt);

    // Encrypt the message
    encrypt(message, key, salt);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}