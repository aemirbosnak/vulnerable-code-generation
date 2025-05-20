//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a string using a key
void encrypt(char *message, int key, char *result) {
    int i = 0, j = 0;
    while (message[i]) {
        if (isalpha(message[i])) {
            result[j] = (char) (((int) message[i] + key - 65) % 26 + 65);
        } else {
            result[j] = message[i];
        }
        i++;
        j++;
    }
    result[j] = '\0';
}

// Function to decrypt a string using a key
void decrypt(char *message, int key, char *result) {
    int i = 0, j = 0;
    while (message[i]) {
        if (isalpha(message[i])) {
            result[j] = (char) (((int) message[i] - key - 65) % 26 + 65);
        } else {
            result[j] = message[i];
        }
        i++;
        j++;
    }
    result[j] = '\0';
}

int main() {
    char message[100], result[100], key = 0;

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    // Remove newline character from input
    message[strcspn(message, "\n")] = 0;

    // Encrypt message using key
    printf("Enter key (0-25): ");
    scanf("%d", &key);
    encrypt(message, key, result);

    // Print encrypted message
    printf("Encrypted message: %s\n", result);

    // Decrypt message using key
    printf("Enter key (0-25): ");
    scanf("%d", &key);
    decrypt(result, key, message);

    // Print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}