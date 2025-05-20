//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 256

// Function to encrypt the string using XOR cipher
void encrypt(char* str, char* key) {
    int i;
    char encrypted[MAX_LEN];

    for (i = 0; str[i]!= '\0'; i++) {
        encrypted[i] = str[i] ^ key[i % strlen(key)];
    }
    encrypted[i] = '\0';

    printf("Encrypted string: %s\n", encrypted);
}

// Function to decrypt the string using XOR cipher
void decrypt(char* str, char* key) {
    int i;
    char decrypted[MAX_LEN];

    for (i = 0; str[i]!= '\0'; i++) {
        decrypted[i] = str[i] ^ key[i % strlen(key)];
    }
    decrypted[i] = '\0';

    printf("Decrypted string: %s\n", decrypted);
}

int main() {
    char str[MAX_LEN], key[MAX_LEN];

    printf("Enter the string to encrypt: ");
    scanf("%s", str);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    encrypt(str, key);

    printf("\nEnter the string to decrypt: ");
    scanf("%s", str);

    printf("Enter the decryption key: ");
    scanf("%s", key);

    decrypt(str, key);

    return 0;
}