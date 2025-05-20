//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 1000
#define ALPHABET_SIZE 26

void init_key(char *key) {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        key[i] = 0;
    }
}

void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        key[i] = rand() % ALPHABET_SIZE + 'A';
    }
}

void encrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            int k = tolower(key[j % MAX_SIZE]) - 'a';
            c = (c - 'a' + k) % ALPHABET_SIZE + 'a';
            message[i] = c;
            j++;
        }
    }
}

void decrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            int k = tolower(key[j % MAX_SIZE]) - 'a';
            c = (c - 'a' - k + ALPHABET_SIZE) % ALPHABET_SIZE + 'a';
            message[i] = c;
            j++;
        }
    }
}

int main() {
    char message[MAX_SIZE], key[MAX_SIZE];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    init_key(key);
    generate_key(key);
    printf("The encrypted message is: ");
    encrypt(message, key);
    printf("%s\n", message);
    printf("Enter the encrypted message to be decrypted: ");
    scanf("%s", message);
    printf("The decrypted message is: ");
    decrypt(message, key);
    printf("%s\n", message);
    return 0;
}