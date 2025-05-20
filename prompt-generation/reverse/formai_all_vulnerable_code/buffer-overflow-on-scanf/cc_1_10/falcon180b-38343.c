//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int encrypt(char *message, int key, int mode) {
    int i, j;
    int length = strlen(message);
    char result[MAX_LENGTH];

    if (mode == 1) {
        for (i = 0; i < length; i++) {
            if (isalpha(message[i])) {
                message[i] = tolower(message[i]);
            }
        }
    }

    for (i = 0, j = 0; i < length; i++) {
        if (isalpha(message[i])) {
            result[j] = (char) (((message[i] + key - 97) % 26) + 97);
            j++;
        } else {
            result[j] = message[i];
            j++;
        }
    }

    result[j] = '\0';
    strcpy(message, result);

    return 0;
}

int decrypt(char *message, int key) {
    int i, j;
    int length = strlen(message);
    char result[MAX_LENGTH];

    for (i = 0, j = 0; i < length; i++) {
        if (isalpha(message[i])) {
            result[j] = (char) (((message[i] - key - 97) % 26) + 97);
            j++;
        } else {
            result[j] = message[i];
            j++;
        }
    }

    result[j] = '\0';
    strcpy(message, result);

    return 0;
}

int main() {
    char message[MAX_LENGTH];
    int key, mode;

    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    printf("Enter the key: ");
    scanf("%d", &key);

    printf("Enter the mode (1 for encryption, 2 for decryption): ");
    scanf("%d", &mode);

    if (mode == 1) {
        encrypt(message, key, mode);
        printf("Encrypted message: %s\n", message);
    } else if (mode == 2) {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid mode\n");
    }

    return 0;
}