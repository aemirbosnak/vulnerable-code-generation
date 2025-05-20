//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 1000

// Function to generate a random key of specified length
void generate_key(char* key, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[]|;:,.<>/?~";
    int charset_length = strlen(charset);
    for (int i = 0; i < length; i++) {
        key[i] = charset[rand() % charset_length];
    }
    key[length] = '\0';
}

// Function to encrypt a message using the Caesar cipher
void caesar_encrypt(char* message, int key) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        char ch = toupper(message[i]);
        if (isalpha(ch)) {
            ch = ch + key - 65;
            if (ch > 90) {
                ch = ch - 26;
            }
        }
        message[i] = ch;
    }
}

// Function to decrypt a message using the Caesar cipher
void caesar_decrypt(char* message, int key) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        char ch = toupper(message[i]);
        if (isalpha(ch)) {
            ch = ch - key - 65;
            if (ch < 65) {
                ch = ch + 26;
            }
        }
        message[i] = ch;
    }
}

int main() {
    char message[MAX_KEY_LENGTH];
    char key[MAX_KEY_LENGTH];
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter key: ");
    scanf("%s", key);

    if (strlen(key) > MAX_KEY_LENGTH) {
        printf("Error: Key is too long.\n");
        return 1;
    }

    srand(time(NULL));
    generate_key(key, strlen(key));

    printf("Encrypted message: ");
    caesar_encrypt(message, atoi(key));
    printf("\n");

    printf("Decrypted message: ");
    caesar_decrypt(message, atoi(key));
    printf("\n");

    return 0;
}