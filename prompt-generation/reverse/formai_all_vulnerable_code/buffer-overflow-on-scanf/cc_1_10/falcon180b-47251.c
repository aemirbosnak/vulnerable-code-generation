//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 100
#define KEY_SIZE 16

void generate_key(char* key);
void encrypt(char* plaintext, char* key, char* ciphertext);
void decrypt(char* ciphertext, char* key, char* plaintext);

int main() {
    char plaintext[SIZE];
    char key[KEY_SIZE];
    char ciphertext[SIZE];
    int choice;

    printf("Enter your message: ");
    fgets(plaintext, SIZE, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    generate_key(key);

    printf("Encrypted message: %s\n", ciphertext);

    printf("Enter 1 to decrypt, 0 to exit: ");
    scanf("%d", &choice);

    if (choice == 1) {
        decrypt(ciphertext, key, plaintext);
        printf("Decrypted message: %s\n", plaintext);
    }

    return 0;
}

void generate_key(char* key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int i, j;
    for (i = 0, j = 0; plaintext[i]!= '\0'; i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[j] = (char) ((int) plaintext[i] + (int) key[i % KEY_SIZE]);
            j++;
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    int i, j;
    for (i = 0, j = 0; ciphertext[i]!= '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[j] = (char) ((int) ciphertext[i] - (int) key[i % KEY_SIZE]);
            j++;
        }
    }
    plaintext[j] = '\0';
}