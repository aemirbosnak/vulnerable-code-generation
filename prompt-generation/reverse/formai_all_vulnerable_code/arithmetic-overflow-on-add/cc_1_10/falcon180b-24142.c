//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TEXT_LENGTH 1000

void encrypt(char *text, int key) {
    int i = 0;
    while (text[i]) {
        if (isalpha(text[i])) {
            text[i] = tolower(text[i]);
            if (isalpha(text[i])) {
                text[i] = (text[i] - 'a' + key) % 26 + 'a';
            }
        }
        i++;
    }
}

void decrypt(char *text, int key) {
    int i = 0;
    while (text[i]) {
        if (isalpha(text[i])) {
            text[i] = tolower(text[i]);
            if (isalpha(text[i])) {
                text[i] = (text[i] - 'a' - key + 26) % 26 + 'a';
            }
        }
        i++;
    }
}

int main() {
    char text[MAX_TEXT_LENGTH];
    int key;

    printf("Enter the text to be encrypted/decrypted: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    printf("Enter the encryption/decryption key (0-25): ");
    scanf("%d", &key);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(text, key);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        decrypt(text, key);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}