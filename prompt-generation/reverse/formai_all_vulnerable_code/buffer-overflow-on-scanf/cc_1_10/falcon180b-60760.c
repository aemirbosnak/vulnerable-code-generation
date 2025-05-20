//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for encryption and decryption
#define KEY "MySecretKey"

// Function to encrypt the given string using the key
void encrypt(char* str, int len) {
    int i;
    for(i=0;i<len;i++) {
        str[i] = str[i] ^ KEY[i % strlen(KEY)];
    }
}

// Function to decrypt the given string using the key
void decrypt(char* str, int len) {
    int i;
    for(i=0;i<len;i++) {
        str[i] = str[i] ^ KEY[i % strlen(KEY)];
    }
}

// Function to display the given string
void display(char* str, int len) {
    int i;
    for(i=0;i<len;i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// Main function to test the encryption and decryption
int main() {
    char str[100];
    int len;

    // Prompt the user to enter a string
    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);

    // Display the original string
    printf("Original string: %s\n", str);

    // Encrypt the string
    encrypt(str, len);
    printf("Encrypted string: ");
    display(str, len);

    // Decrypt the string
    decrypt(str, len);
    printf("Decrypted string: ");
    display(str, len);

    return 0;
}