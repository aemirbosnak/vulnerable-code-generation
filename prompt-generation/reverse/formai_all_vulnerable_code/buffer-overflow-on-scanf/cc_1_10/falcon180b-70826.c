//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100

void encrypt(char* plainText, char* key, char* cipherText) {
    int keyLength = strlen(key);
    int plainTextLength = strlen(plainText);

    if (keyLength > MAX_KEY_LENGTH) {
        printf("Error: Key is too long\n");
        exit(1);
    }

    if (plainTextLength > MAX_FILE_NAME_LENGTH) {
        printf("Error: File is too large\n");
        exit(1);
    }

    int i, j;
    for (i = 0, j = 0; i < plainTextLength; i++) {
        if (isalpha(plainText[i])) {
            cipherText[j] = (char) ((int) plainText[i] + (int) key[j % keyLength]);
            j++;
        } else {
            cipherText[j] = plainText[i];
            j++;
        }
    }
    cipherText[j] = '\0';
}

void decrypt(char* cipherText, char* key, char* plainText) {
    int keyLength = strlen(key);
    int cipherTextLength = strlen(cipherText);

    if (keyLength > MAX_KEY_LENGTH) {
        printf("Error: Key is too long\n");
        exit(1);
    }

    if (cipherTextLength > MAX_FILE_NAME_LENGTH) {
        printf("Error: File is too large\n");
        exit(1);
    }

    int i, j;
    for (i = 0, j = 0; i < cipherTextLength; i++) {
        if (isalpha(cipherText[i])) {
            plainText[j] = (char) ((int) cipherText[i] - (int) key[j % keyLength]);
            j++;
        } else {
            plainText[j] = cipherText[i];
            j++;
        }
    }
    plainText[j] = '\0';
}

int main() {
    char plainText[MAX_FILE_NAME_LENGTH];
    char cipherText[MAX_FILE_NAME_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter plain text: ");
    scanf("%s", plainText);

    printf("Enter key: ");
    scanf("%s", key);

    encrypt(plainText, key, cipherText);

    printf("Cipher text: %s\n", cipherText);

    return 0;
}