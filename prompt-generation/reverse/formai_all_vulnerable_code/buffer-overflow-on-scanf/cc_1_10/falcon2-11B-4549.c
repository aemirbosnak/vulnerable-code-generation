//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <string.h>

// Function to perform the XOR operation
void xor(char* str1, char* str2, char* result) {
    int i;
    for (i = 0; i < strlen(str1); i++) {
        result[i] = str1[i] ^ str2[i];
    }
}

// Function to encrypt a string using XOR encryption
void encrypt(char* str, char* key) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        str[i] = (char)(str[i] ^ key[i % 256]);
    }
}

// Function to decrypt a string using XOR encryption
void decrypt(char* str, char* key) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        str[i] = (char)(str[i] ^ key[i % 256]);
    }
}

int main() {
    // Input string and key
    char str[100];
    char key[100];

    // Get input from user
    printf("Enter the string to encrypt: ");
    scanf("%s", str);

    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the string
    encrypt(str, key);

    // Print the encrypted string
    printf("Encrypted string: %s\n", str);

    // Decrypt the encrypted string
    decrypt(str, key);

    // Print the decrypted string
    printf("Decrypted string: %s\n", str);

    return 0;
}