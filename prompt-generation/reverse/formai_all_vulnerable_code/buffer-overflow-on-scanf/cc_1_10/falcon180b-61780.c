//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define SIZE 10
#define KEY "AdaLovelace"
#define PI 3.14159265358979323846

void generate_key(char *key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = (key[i] + 3) % 26;
    }
}

void encrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] + key[j] - 65) % 26 + 65;
            j = (j + 1) % strlen(key);
        }
    }
}

void decrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - key[j] - 65 + 26) % 26 + 65;
            j = (j + 1) % strlen(key);
        }
    }
}

int main() {
    char message[SIZE];
    char key[SIZE];
    char choice;
    int i;

    printf("Enter a message to encrypt:\n");
    scanf("%s", message);

    printf("Enter a key to encrypt the message:\n");
    scanf("%s", key);

    generate_key(key);
    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    printf("Do you want to decrypt the message? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y') {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }

    return 0;
}