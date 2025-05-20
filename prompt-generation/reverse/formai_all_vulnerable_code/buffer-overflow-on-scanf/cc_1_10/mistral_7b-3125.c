//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 1
#define ALPHABET_SIZE 26

char key[KEY_SIZE];
char encryptedText[100];
char decryptedText[100];
char plainText[100];

void setKey(int shift) {
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        key[i] = (char) (i + shift % ALPHABET_SIZE);
    }
}

void encrypt(char text[]) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            encryptedText[i] = key[(text[i] - 'a')];
        } else {
            encryptedText[i] = text[i];
        }
    }
    encryptedText[i] = '\0';
}

void decrypt(char text[]) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            decryptedText[i] = key[(text[i] - 'a') ^ (KEY_SIZE - 1)];
        } else {
            decryptedText[i] = text[i];
        }
    }
    decryptedText[i] = '\0';
}

void printText(char text[]) {
    printf("%s\n", text);
}

int main() {
    int keyShift;
    char userInput[100];

    printf("Enter the shift value for the encryption key: ");
    scanf("%d", &keyShift);

    setKey(keyShift);

    printf("Enter the plaintext: ");
    scanf("%s", plainText);

    encrypt(plainText);

    printf("Encrypted text: ");
    printText(encryptedText);

    decrypt(encryptedText);

    printf("Decrypted text: ");
    printText(decryptedText);

    return 0;
}