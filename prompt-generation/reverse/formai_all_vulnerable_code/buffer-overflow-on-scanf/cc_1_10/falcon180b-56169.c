//Falcon-180B DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY "MySecretKey"

void encrypt(char* message, int message_len) {
    int i = 0, j = 0;
    char encrypted_message[message_len];

    while (i < message_len) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[j] = ((message[i] - 65 + 13) % 26) + 65;
            } else {
                encrypted_message[j] = ((message[i] - 97 + 13) % 26) + 97;
            }
        } else {
            encrypted_message[j] = message[i];
        }
        i++;
        j++;
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* message, int message_len) {
    int i = 0, j = 0;
    char decrypted_message[message_len];

    while (i < message_len) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[j] = ((message[i] - 65 - 13 + 26) % 26) + 65;
            } else {
                decrypted_message[j] = ((message[i] - 97 - 13 + 26) % 26) + 97;
            }
        } else {
            decrypted_message[j] = message[i];
        }
        i++;
        j++;
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    encrypt(message, strlen(message));

    printf("Enter the encrypted message to decrypt: ");
    scanf("%s", message);

    decrypt(message, strlen(message));

    return 0;
}