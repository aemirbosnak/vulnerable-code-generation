//Falcon-180B DATASET v1.0 Category: Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char* message, char* key) {
    int i, j, n = strlen(message);
    char encrypted_message[MAX_MESSAGE_LENGTH];
    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[j] = (message[i] + key[j % MAX_KEY_LENGTH] - 65) % 26 + 65;
            } else {
                encrypted_message[j] = (message[i] + key[j % MAX_KEY_LENGTH] - 97) % 26 + 97;
            }
            j++;
        } else {
            encrypted_message[j] = message[i];
            j++;
        }
    }
    encrypted_message[j] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* encrypted_message, char* key) {
    int i, j, n = strlen(encrypted_message);
    char decrypted_message[MAX_MESSAGE_LENGTH];
    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[j] = (encrypted_message[i] - key[j % MAX_KEY_LENGTH] - 65 + 26) % 26 + 65;
            } else {
                decrypted_message[j] = (encrypted_message[i] - key[j % MAX_KEY_LENGTH] - 97 + 26) % 26 + 97;
            }
            j++;
        } else {
            decrypted_message[j] = encrypted_message[i];
            j++;
        }
    }
    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH], key[MAX_KEY_LENGTH];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    printf("Enter the encryption key: ");
    scanf("%s", key);
    encrypt(message, key);
    printf("\n");
    decrypt(message, key);
    return 0;
}