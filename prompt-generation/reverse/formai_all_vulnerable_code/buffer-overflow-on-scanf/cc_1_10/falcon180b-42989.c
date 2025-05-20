//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void generate_key(char key[SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char message[SIZE], char key[SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        message[i] = (message[i] + key[i]) % 26 + 'a';
    }
}

void decrypt(char message[SIZE], char key[SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        message[i] = (message[i] - key[i] + 26) % 26 + 'a';
    }
}

int main() {
    char message[SIZE];
    char key[SIZE];
    int choice;
    srand(time(NULL));

    printf("Enter message to encrypt: ");
    fgets(message, SIZE, stdin);

    printf("Enter choice:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    if (choice == 1) {
        generate_key(key);
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 2) {
        printf("Enter key: ");
        fgets(key, SIZE, stdin);
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}