//FormAI DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int key) {
    char c;
    for(int i = 0; message[i] != '\0'; ++i) {
        c = message[i];
        if(c >= 'a' && c <= 'z') {
            c = c + key;
            if(c > 'z') {
                c = c - 'z' + 'a' - 1;
            }
            message[i] = c;
        }
        else if(c >= 'A' && c <= 'Z') {
            c = c + key;
            if(c > 'Z') {
                c = c - 'Z' + 'A' - 1;
            }
            message[i] = c;
        }
    }
}

void decrypt(char *message, int key) {
    char c;
    for(int i = 0; message[i] != '\0'; ++i) {
        c = message[i];
        if(c >= 'a' && c <= 'z') {
            c = c - key;
            if(c < 'a') {
                c = c + 'z' - 'a' + 1;
            }
            message[i] = c;
        }
        else if(c >= 'A' && c <= 'Z') {
            c = c - key;
            if(c < 'A') {
                c = c + 'Z' - 'A' + 1;
            }
            message[i] = c;
        }
    }
}

int main() {
    char message[100];
    int key;
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter key: ");
    scanf("%d", &key);

    // Encryption
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decryption
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}