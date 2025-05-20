//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: complete
#include <stdio.h>
#include <string.h>

void encrypt(char* message, int key) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = c + key - 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = c + key - 'A';
        }
        message[i] = c;
    }
}

void decrypt(char* message, int key) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = c - key - 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = c - key - 'A';
        }
        message[i] = c;
    }
}

int main() {
    char message[100];
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);

    int key;
    printf("Enter the encryption key (between 1 and 26): ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    printf("Enter the decryption key (between 1 and 26): ");
    scanf("%d", &key);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}