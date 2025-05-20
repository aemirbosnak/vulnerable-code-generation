//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

void encrypt(char* message, int key) {
    int i, j;
    char* result = malloc(strlen(message) * sizeof(char));

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[j] = (((message[i] - 65 + key) % 26) + 65);
            } else {
                result[j] = (((message[i] - 97 + key) % 26) + 97);
            }
            j++;
        } else {
            result[j] = message[i];
            j++;
        }
    }
    result[j] = '\0';

    printf("Encrypted message: %s\n", result);
}

void decrypt(char* message, int key) {
    int i, j;
    char* result = malloc(strlen(message) * sizeof(char));

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[j] = (((message[i] - 65 - key + 26) % 26) + 65);
            } else {
                result[j] = (((message[i] - 97 - key + 26) % 26) + 97);
            }
            j++;
        } else {
            result[j] = message[i];
            j++;
        }
    }
    result[j] = '\0';

    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt/decrypt: ");
    scanf("%s", message);

    printf("Enter key (1-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}