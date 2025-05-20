//Falcon-180B DATASET v1.0 Category: Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define KEY_LENGTH 8
#define ENCRYPT 1
#define DECRYPT 0

void generateKey(char *key, int length) {
    int i;
    for (i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt(char *text, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            text[i] = (char) (((int) text[i] - 65 + (int) key[j]) % 26 + 65);
            j = (j + 1) % KEY_LENGTH;
        }
    }
}

void decrypt(char *text, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            text[i] = (char) (((int) text[i] - 65 - (int) key[j]) % 26 + 65);
            j = (j + 1) % KEY_LENGTH;
        }
    }
}

int main() {
    char text[MAX_LENGTH];
    char key[KEY_LENGTH];
    int choice, length;

    printf("Enter the text to be encrypted/decrypted: ");
    scanf("%s", text);

    printf("Enter the length of the key (between 1 and %d): ", KEY_LENGTH);
    scanf("%d", &length);

    generateKey(key, length);

    printf("Enter 1 to encrypt or 0 to decrypt: ");
    scanf("%d", &choice);

    if (choice == ENCRYPT) {
        encrypt(text, key);
        printf("Encrypted text: %s\n", text);
    } else if (choice == DECRYPT) {
        decrypt(text, key);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}