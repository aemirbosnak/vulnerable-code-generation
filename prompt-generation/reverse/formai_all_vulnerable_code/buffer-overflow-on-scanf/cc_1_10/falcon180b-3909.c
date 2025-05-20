//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 26
#define KEY 5

void encrypt(char *message, int key) {
    int i, j;
    char *cipher = malloc(strlen(message) + 1);

    if (cipher == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                cipher[i] = (char) (((message[i] - 'A' + key) % SIZE) + 'A');
            } else {
                cipher[i] = (char) (((message[i] - 'a' + key) % SIZE) + 'a');
            }
        } else {
            cipher[i] = message[i];
        }
    }

    cipher[i] = '\0';

    printf("Encrypted message: %s\n", cipher);
}

void decrypt(char *cipher, int key) {
    int i, j;
    char *message = malloc(strlen(cipher) + 1);

    if (message == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    for (i = 0; cipher[i]!= '\0'; i++) {
        if (isalpha(cipher[i])) {
            if (isupper(cipher[i])) {
                message[i] = (char) (((cipher[i] - 'A' - key + SIZE) % SIZE) + 'A');
            } else {
                message[i] = (char) (((cipher[i] - 'a' - key + SIZE) % SIZE) + 'a');
            }
        } else {
            message[i] = cipher[i];
        }
    }

    message[i] = '\0';

    printf("Decrypted message: %s\n", message);
}

int main() {
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter a key (1-25): ");
    scanf("%d", &key);

    if ((key < 1) || (key > 25)) {
        printf("Invalid key\n");
        return 0;
    }

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}