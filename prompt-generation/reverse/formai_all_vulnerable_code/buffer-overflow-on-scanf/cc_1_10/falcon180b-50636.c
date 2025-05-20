//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message
void encrypt(char message[], int key) {
    int i, j, k;
    char ch;
    for (i = 0; message[i]!= '\0'; i++) {
        ch = tolower(message[i]);
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = 'a' + (ch - 'A' + key) % 26;
            } else {
                ch = 'a' + (ch - 'a' + key) % 26;
            }
        }
        printf("%c", ch);
    }
}

// Function to decrypt the message
void decrypt(char message[], int key) {
    int i, j, k;
    char ch;
    for (i = 0; message[i]!= '\0'; i++) {
        ch = tolower(message[i]);
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = 'A' + (ch - 'a' - key + 26) % 26;
            } else {
                ch = 'a' + (ch - 'a' - key + 26) % 26;
            }
        }
        printf("%c", ch);
    }
}

int main() {
    char message[100];
    int key = 13; // Example key
    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]", message);
    printf("Encrypted message: ");
    encrypt(message, key);
    printf("\n");
    printf("Decrypted message: ");
    decrypt(message, key);
    printf("\n");
    return 0;
}