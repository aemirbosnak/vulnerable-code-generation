//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to shift a character by a certain amount
char shift(char c, int shift) {
    if (isupper(c)) {
        if (c + shift > 'Z') {
            return 'A' + (c + shift - 'Z' - 1);
        }
        return c + shift;
    } else if (islower(c)) {
        if (c + shift > 'z') {
            return 'a' + (c + shift - 'z' - 1);
        }
        return c + shift;
    }
    return c;
}

// Function to encrypt a string using a key
void encrypt(char* str, char* key) {
    int i, j;
    for (i = 0, j = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            str[i] = shift(str[i], toupper(key[j]) - 'A');
            j = (j + 1) % strlen(key);
        }
    }
}

// Function to decrypt a string using a key
void decrypt(char* str, char* key) {
    int i, j;
    for (i = 0, j = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            str[i] = shift(str[i], tolower(key[j]) - 'a');
            j = (j + 1) % strlen(key);
        }
    }
}

int main() {
    char str[100], key[100];
    printf("Enter a string to encrypt: ");
    scanf("%s", str);
    printf("Enter a key: ");
    scanf("%s", key);

    // Encrypt the string
    encrypt(str, key);
    printf("Encrypted string: %s\n", str);

    // Decrypt the string
    decrypt(str, key);
    printf("Decrypted string: %s\n", str);

    return 0;
}