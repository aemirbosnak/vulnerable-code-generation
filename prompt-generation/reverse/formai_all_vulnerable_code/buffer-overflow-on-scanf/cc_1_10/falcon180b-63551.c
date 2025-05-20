//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to encrypt a message using the Caesar cipher
void caesar_encrypt(char* message, int key) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + key) % 26 + 'A';
            }
            else {
                message[i] = (message[i] - 'a' + key) % 26 + 'a';
            }
        }
    }
}

// Function to decrypt a message using the Caesar cipher
void caesar_decrypt(char* message, int key) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
            }
            else {
                message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
            }
        }
    }
}

int main() {
    // Prompt user for message to encrypt
    char message[1000];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Prompt user for encryption key
    int key = rand_int(1, 25);
    printf("Encryption key: %d\n", key);

    // Encrypt message using Caesar cipher
    caesar_encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Prompt user for decryption key
    int decryption_key;
    do {
        printf("Enter the decryption key: ");
        scanf("%d", &decryption_key);
    } while (decryption_key!= key);

    // Decrypt message using Caesar cipher
    caesar_decrypt(message, decryption_key);
    printf("Decrypted message: %s\n", message);

    return 0;
}