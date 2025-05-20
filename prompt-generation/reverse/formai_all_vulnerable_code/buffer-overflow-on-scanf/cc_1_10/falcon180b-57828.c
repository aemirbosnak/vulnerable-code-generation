//Falcon-180B DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

void encrypt(char message[], int key) {
    int i, j;
    char encrypted_message[SIZE];

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[j] = (message[i] + key - 65) % 26 + 65;
            } else {
                encrypted_message[j] = (message[i] + key - 97) % 26 + 97;
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

void decrypt(char encrypted_message[], int key) {
    int i, j;
    char decrypted_message[SIZE];

    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[j] = (encrypted_message[i] - 65 - key + 26) % 26 + 65;
            } else {
                decrypted_message[j] = (encrypted_message[i] - 97 - key + 26) % 26 + 97;
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
    char message[SIZE];
    int key;

    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%[^\n]", message);

    printf("Enter the key (1-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}