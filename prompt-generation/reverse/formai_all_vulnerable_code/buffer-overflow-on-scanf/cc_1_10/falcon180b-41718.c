//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26
#define KEY 5

void encrypt(char *message, char *key) {
    int i, j, index;
    char cipher[SIZE];
    for (i = 0; i < SIZE; i++) {
        cipher[i] = i + 'a';
    }
    for (i = 0; i < strlen(key); i++) {
        index = tolower(key[i]) - 'a';
        for (j = 0; j < SIZE; j++) {
            if (j!= index) {
                char temp = cipher[j];
                cipher[j] = cipher[index];
                cipher[index] = temp;
            }
        }
    }
    int n = strlen(message);
    for (i = 0; i < n; i++) {
        if (isalpha(message[i])) {
            char c = tolower(message[i]);
            int k = c - 'a';
            int m = (k + (i % strlen(key))) % SIZE;
            message[i] = cipher[m];
        }
    }
}

void decrypt(char *cipher, char *key) {
    int i, j, index;
    char message[SIZE];
    for (i = 0; i < SIZE; i++) {
        message[i] = i + 'a';
    }
    for (i = 0; i < strlen(key); i++) {
        index = tolower(key[i]) - 'a';
        for (j = 0; j < SIZE; j++) {
            if (j!= index) {
                char temp = message[j];
                message[j] = message[index];
                message[index] = temp;
            }
        }
    }
    int n = strlen(cipher);
    for (i = 0; i < n; i++) {
        if (isalpha(cipher[i])) {
            char c = tolower(cipher[i]);
            int k = (c - 'a') % SIZE;
            int m = (k - (i % strlen(key))) % SIZE;
            cipher[i] = message[m];
        }
    }
}

int main() {
    char message[1000];
    char key[100];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    printf("Enter the encryption key: ");
    scanf("%s", key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}