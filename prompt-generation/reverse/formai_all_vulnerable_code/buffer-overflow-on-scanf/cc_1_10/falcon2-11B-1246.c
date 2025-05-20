//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RAND() (rand() % 26 + 'A')

// Generates a random shift between 1 and 25
int generateShift() {
    int shift = 1 + (rand() % 25);
    return shift;
}

// Encrypts the message using the given shift
char* encrypt(const char* message, int shift) {
    char* encrypted = (char*) malloc(sizeof(char) * strlen(message) + 1);
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted[i] = RAND();
            if (isupper(message[i])) {
                encrypted[i] = RAND() - 'A' + 'A';
            } else {
                encrypted[i] = RAND() - 'a' + 'a';
            }
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[strlen(message)] = '\0';
    return encrypted;
}

// Decrypts the message using the given shift
char* decrypt(const char* message, int shift) {
    char* decrypted = (char*) malloc(sizeof(char) * strlen(message) + 1);
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            decrypted[i] = RAND() - 'A' + 'A';
            if (isupper(message[i])) {
                decrypted[i] = RAND() - 'A' + 'A';
            } else {
                decrypted[i] = RAND() - 'a' + 'a';
            }
        } else {
            decrypted[i] = message[i];
        }
    }
    decrypted[strlen(message)] = '\0';
    return decrypted;
}

int main() {
    char* message;
    printf("Enter a message to encrypt (or 'decrypt' to decrypt): ");
    scanf("%s", &message);
    
    if (strcmp(message, "encrypt") == 0) {
        int shift = generateShift();
        char* encrypted = encrypt(message, shift);
        printf("Encrypted message: %s\n", encrypted);
        free(encrypted);
    } else if (strcmp(message, "decrypt") == 0) {
        int shift = generateShift();
        char* decrypted = decrypt(message, shift);
        printf("Decrypted message: %s\n", decrypted);
        free(decrypted);
    } else {
        printf("Invalid command. Use 'encrypt' or 'decrypt'.\n");
    }
    
    return 0;
}