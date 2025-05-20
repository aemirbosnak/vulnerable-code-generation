//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: surprised
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int key) {
    int i = 0;
    while (message[i] != '\0') {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = c + key;
            if (c > 'z') {
                c = c - 'z' + 'a' - 1;
            }
            message[i] = c;
        } else if (c >= 'A' && c <= 'Z') {
            c = c + key;
            if (c > 'Z') {
                c = c - 'Z' + 'A' - 1;
            }
            message[i] = c;
        }
        i++;
    }
}

void decrypt(char *message, int key) {
    int i = 0;
    while (message[i] != '\0') {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = c - key;
            if (c < 'a') {
                c = c + 'z' - 'a' + 1;
            }
            message[i] = c;
        } else if (c >= 'A' && c <= 'Z') {
            c = c - key;
            if (c < 'A') {
                c = c + 'Z' - 'A' + 1;
            }
            message[i] = c;
        }
        i++;
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}