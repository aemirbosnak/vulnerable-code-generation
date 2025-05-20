//Falcon-180B DATASET v1.0 Category: Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 1000

// Function to encrypt a message using a key
void encrypt(char* message, char* key) {
    int i, j, k;
    char encrypted_message[strlen(message)];
    memset(encrypted_message, 0, strlen(message));
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            if (isalpha(key[j])) {
                key[j] = toupper(key[j]);
                encrypted_message[i] = ((message[i] + key[j]) % 26) + 'A';
            } else {
                encrypted_message[i] = message[i];
            }
            j = (j + 1) % strlen(key);
        } else {
            encrypted_message[i] = message[i];
        }
    }
    printf("Encrypted Message: %s\n", encrypted_message);
}

// Function to decrypt an encrypted message using a key
void decrypt(char* encrypted_message, char* key) {
    int i, j, k;
    char decrypted_message[strlen(encrypted_message)];
    memset(decrypted_message, 0, strlen(encrypted_message));
    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            encrypted_message[i] = toupper(encrypted_message[i]);
            if (isalpha(key[j])) {
                key[j] = toupper(key[j]);
                decrypted_message[i] = ((encrypted_message[i] - key[j] + 26) % 26) + 'A';
            } else {
                decrypted_message[i] = encrypted_message[i];
            }
            j = (j + 1) % strlen(key);
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    printf("Decrypted Message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_KEY_LENGTH];
    char key[MAX_KEY_LENGTH];
    int length;
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter key length: ");
    scanf("%d", &length);
    printf("Enter key: ");
    scanf("%s", key);
    encrypt(message, key);
    printf("\nDecrypting...\n");
    decrypt(message, key);
    return 0;
}