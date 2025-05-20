//FormAI DATASET v1.0 Category: Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to perform encryption */
void encryption(char *str, int key) {
    int len = strlen(str);
    int i;

    /* Iterate through each character in the string */
    for(i=0; i<len; i++) {
        /* Encrypt each character by adding the key */
        str[i] = str[i] + key;
    }
}

/* Function to perform decryption */
void decryption(char *str, int key) {
    int len = strlen(str);
    int i;

    /* Iterate through each character in the string */
    for(i=0; i<len; i++) {
        /* Decrypt each character by subtracting the key */
        str[i] = str[i] - key;
    }
}

int main() {
    char input[100];
    char option;
    int key;

    /* Prompt the user for the input string */
    printf("Enter a string to encrypt or decrypt: ");
    fgets(input, 100, stdin);

    /* Prompt the user for the encryption/decryption key */
    printf("Enter a key for encryption/decryption: ");
    scanf("%d", &key);

    /* Prompt the user for an encryption or decryption operation */
    printf("Do you want to encrypt or decrypt? (E/D): ");
    scanf(" %c", &option);

    /* Perform encryption */
    if(option == 'E' || option == 'e') {
        encryption(input, key);
        printf("Encrypted string: %s", input);
    }
    /* Perform decryption */
    else if(option == 'D' || option == 'd') {
        decryption(input, key);
        printf("Decrypted string: %s", input);
    }
    /* Invalid option */
    else {
        printf("Invalid option! Enter E to encrypt or D to decrypt.");
    }

    return 0;
}