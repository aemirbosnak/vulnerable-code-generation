//Falcon-180B DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int key) {
    int i, j;
    char *result = (char *)malloc(strlen(message) + 1);
    result[0] = '\0';
    for (i = 0, j = strlen(message) - 1; i < strlen(message); i++, j--) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + key) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' + key) % 26 + 'a';
            }
        } else {
            message[i] = message[j];
        }
        strncat(result, &message[i], 1);
    }
    printf("Encrypted message: %s\n", result);
}

void decrypt(char *message, int key) {
    int i, j;
    char *result = (char *)malloc(strlen(message) + 1);
    result[0] = '\0';
    for (i = 0, j = strlen(message) - 1; i < strlen(message); i++, j--) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
            }
        } else {
            message[i] = message[j];
        }
        strncat(result, &message[i], 1);
    }
    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[1000];
    int key;
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);
    encrypt(message, key);
    printf("Enter message to decrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter decryption key: ");
    scanf("%d", &key);
    decrypt(message, key);
    return 0;
}