//Falcon-180B DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the given string using Caesar cipher
void encrypt(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = tolower(str[i]);
        if (isalpha(c)) {
            if (c >= 'a' && c <= 'z') {
                str[i] = (char) (((int) c - 97 + key) % 26 + 97);
            } else {
                str[i] = (char) (((int) c - 65 + key) % 26 + 65);
            }
        }
    }
}

// Function to decrypt the given string using Caesar cipher
void decrypt(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = tolower(str[i]);
        if (isalpha(c)) {
            if (c >= 'a' && c <= 'z') {
                str[i] = (char) (((int) c - 97 - key + 26) % 26 + 97);
            } else {
                str[i] = (char) (((int) c - 65 - key + 26) % 26 + 65);
            }
        }
    }
}

int main() {
    char str[1000];
    printf("Enter the string to be encrypted: ");
    scanf("%[^\n]", str);

    int key;
    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(str, key);
    printf("Encrypted string: %s\n", str);

    decrypt(str, key);
    printf("Decrypted string: %s\n", str);

    return 0;
}