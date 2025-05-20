//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void encrypt(char* message, int key) {
    int i;
    char c;

    for(i = 0; i < strlen(message); i++) {
        c = message[i];
        if(isupper(c)) {
            c = (c + key - 'A') % 26 + 'A';
        } else if(islower(c)) {
            c = (c + key - 'a') % 26 + 'a';
        }
        message[i] = c;
    }

    printf("Encrypted message: %s\n", message);
}

void decrypt(char* message, int key) {
    int i;
    char c;

    for(i = 0; i < strlen(message); i++) {
        c = message[i];
        if(isupper(c)) {
            c = (c - key + 'A') % 26 + 'A';
        } else if(islower(c)) {
            c = (c - key + 'a') % 26 + 'a';
        }
        message[i] = c;
    }

    printf("Decrypted message: %s\n", message);
}

int main() {
    char message[MAX_LENGTH];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}