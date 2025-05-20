//Falcon-180B DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "MySecretKey"
#define ENCRYPTION 1
#define DECRYPTION 0

void encrypt(char *message, int mode);
void decrypt(char *message, int mode);

int main() {
    char message[100];
    int mode;

    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);

    printf("Enter the mode (0 for decryption, 1 for encryption): ");
    scanf("%d", &mode);

    if(mode == ENCRYPTION) {
        encrypt(message, mode);
    }
    else if(mode == DECRYPTION) {
        decrypt(message, mode);
    }
    else {
        printf("Invalid mode\n");
    }

    return 0;
}

void encrypt(char *message, int mode) {
    int i, j;
    char newMessage[100];

    for(i = 0; message[i]!= '\0'; i++) {
        newMessage[i] = message[i] + KEY[i % strlen(KEY)];
    }

    printf("Encrypted message: %s\n", newMessage);
}

void decrypt(char *message, int mode) {
    int i, j;
    char newMessage[100];

    for(i = 0; message[i]!= '\0'; i++) {
        newMessage[i] = message[i] - KEY[i % strlen(KEY)];
    }

    printf("Decrypted message: %s\n", newMessage);
}