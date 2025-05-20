//Falcon-180B DATASET v1.0 Category: Encryption ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct {
    char plaintext[MAX_LENGTH];
    char ciphertext[MAX_LENGTH];
} message;

void encrypt(message *msg) {
    int i, j, n = strlen(msg->plaintext);
    char key[MAX_LENGTH] = "secret_key";
    for (i = 0, j = 0; i < n; i++) {
        if (msg->plaintext[i] >= 'A' && msg->plaintext[i] <= 'Z') {
            msg->ciphertext[j++] = (msg->plaintext[i] + key[i % strlen(key)]) % 26 + 'A';
        } else if (msg->plaintext[i] >= 'a' && msg->plaintext[i] <= 'z') {
            msg->ciphertext[j++] = (msg->plaintext[i] + key[i % strlen(key)]) % 26 + 'a';
        } else {
            msg->ciphertext[j++] = msg->plaintext[i];
        }
    }
    msg->ciphertext[j] = '\0';
}

void decrypt(message *msg) {
    int i, j, n = strlen(msg->ciphertext);
    char key[MAX_LENGTH] = "secret_key";
    for (i = 0, j = 0; i < n; i++) {
        if (msg->ciphertext[i] >= 'A' && msg->ciphertext[i] <= 'Z') {
            msg->plaintext[j++] = (msg->ciphertext[i] - key[i % strlen(key)]) % 26 + 'A';
        } else if (msg->ciphertext[i] >= 'a' && msg->ciphertext[i] <= 'z') {
            msg->plaintext[j++] = (msg->ciphertext[i] - key[i % strlen(key)]) % 26 + 'a';
        } else {
            msg->plaintext[j++] = msg->ciphertext[i];
        }
    }
    msg->plaintext[j] = '\0';
}

int main() {
    message msg;
    printf("Enter the plaintext message: ");
    scanf("%s", msg.plaintext);
    encrypt(&msg);
    printf("Encrypted message: %s\n", msg.ciphertext);
    decrypt(&msg);
    printf("Decrypted message: %s\n", msg.plaintext);
    return 0;
}