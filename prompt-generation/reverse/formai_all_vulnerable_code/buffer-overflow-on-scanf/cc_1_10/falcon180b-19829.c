//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void vigenere(char *message, char *key, char *ciphertext) {
    int i, j, k, l;
    char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int m = strlen(message);
    int n = strlen(key);

    for(i = 0; i < n; i++) {
        if(key[i] >= 'A' && key[i] <= 'Z') {
            key[i] = key[i] - 'A';
        } else if(key[i] >= 'a' && key[i] <= 'z') {
            key[i] = key[i] - 'a';
        } else {
            key[i] = 0;
        }
    }

    for(i = 0; i < m; i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] - 'A';
        } else if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - 'a';
        } else {
            message[i] = 0;
        }
    }

    for(i = 0; i < m; i++) {
        j = message[i] + key[i % n];
        if(j > 25) {
            j = j - 26;
        } else if(j < 0) {
            j = j + 26;
        }
        ciphertext[i] = alpha[j];
    }
    ciphertext[m] = '\0';
}

int main() {
    char message[100], key[100], ciphertext[200];

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter key: ");
    scanf("%s", key);

    vigenere(message, key, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    return 0;
}