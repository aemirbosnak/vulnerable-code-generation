//Falcon-180B DATASET v1.0 Category: Encryption ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

void encrypt(char* message, int key) {
    int i, j;
    char shifted;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            shifted = (char) (((int) message[i] - 97 + key) % 26 + 97);
            if (isupper(message[i])) {
                message[i] = toupper(shifted);
            } else {
                message[i] = tolower(shifted);
            }
        }
    }
}

void decrypt(char* message, int key) {
    int i, j;
    char shifted;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            shifted = (char) (((int) message[i] - 97 - key + 26) % 26 + 97);
            if (isupper(message[i])) {
                message[i] = toupper(shifted);
            } else {
                message[i] = tolower(shifted);
            }
        }
    }
}

int main() {
    char message[MAX_LENGTH];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);

    printf("Enter a key (0-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}