//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_TEXT_SIZE 1000

void encrypt(char* text, char* key) {
    int i, j, k;
    char encrypted_text[MAX_TEXT_SIZE];
    encrypted_text[0] = '\0';
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                j = 0;
            } else {
                j = 26;
            }
            k = (int)text[i] + (int)key[j % strlen(key)] - 97;
            if (k > 122) {
                k -= 26;
            } else if (k < 97) {
                k += 26;
            }
            encrypted_text[i] = k;
        } else {
            encrypted_text[i] = text[i];
        }
    }
    printf("Encrypted Text: %s\n", encrypted_text);
}

void decrypt(char* encrypted_text, char* key) {
    int i, j, k;
    char decrypted_text[MAX_TEXT_SIZE];
    decrypted_text[0] = '\0';
    for (i = 0; i < strlen(encrypted_text); i++) {
        if (isalpha(encrypted_text[i])) {
            if (isupper(encrypted_text[i])) {
                j = 0;
            } else {
                j = 26;
            }
            k = (int)encrypted_text[i] - (int)key[j % strlen(key)] + 97;
            if (k > 122) {
                k -= 26;
            } else if (k < 97) {
                k += 26;
            }
            decrypted_text[i] = k;
        } else {
            decrypted_text[i] = encrypted_text[i];
        }
    }
    printf("Decrypted Text: %s\n", decrypted_text);
}

int main() {
    char text[MAX_TEXT_SIZE];
    char key[MAX_KEY_SIZE];
    printf("Enter the text to be encrypted: ");
    scanf("%s", text);
    printf("Enter the encryption key: ");
    scanf("%s", key);
    encrypt(text, key);
    decrypt(text, key);
    return 0;
}