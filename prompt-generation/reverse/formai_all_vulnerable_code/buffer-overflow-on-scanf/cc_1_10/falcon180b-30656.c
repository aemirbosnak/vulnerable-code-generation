//Falcon-180B DATASET v1.0 Category: Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char* message, int key) {
    int i, j, k;
    char* result = (char*)malloc(strlen(message) + 1);

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            result[j++] = (tolower(message[i]) - 'a' + key) % 26 + 'a';
        } else {
            result[j++] = message[i];
        }
    }
    result[j] = '\0';

    printf("Encrypted message: %s\n", result);
    free(result);
}

void decrypt(char* message, int key) {
    int i, j, k;
    char* result = (char*)malloc(strlen(message) + 1);

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            result[j++] = (int)message[i] - 'a' - key + 26 % 26 + 'a';
        } else {
            result[j++] = message[i];
        }
    }
    result[j] = '\0';

    printf("Decrypted message: %s\n", result);
    free(result);
}

int main() {
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter the key (shift): ");
    scanf("%d", &key);

    printf("Encrypted message: ");
    encrypt(message, key);

    printf("\nDecrypted message: ");
    decrypt(message, key);

    return 0;
}