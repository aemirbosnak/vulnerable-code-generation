//FormAI DATASET v1.0 Category: Encryption ; Style: Ada Lovelace
// Behold, a C Encryption Example program in the style of Ada Lovelace

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define our encryption key (let's keep it simple for this example)
#define KEY "ada"

// function to encrypt a string using our key
void encrypt(char *str)
{
    int i, j = 0;
    int str_len = strlen(str);
    int key_len = strlen(KEY);

    for (i = 0; i < str_len; i++) {
        str[i] ^= KEY[j];
        j = (j + 1) % key_len;
    }
}

// function to decrypt a string using our key
void decrypt(char *str)
{
    int i, j = 0;
    int str_len = strlen(str);
    int key_len = strlen(KEY);

    for (i = 0; i < str_len; i++) {
        str[i] ^= KEY[j];
        j = (j + 1) % key_len;
    }
}

int main()
{
    char original_str[100];
    char encrypted_str[100];
    char decrypted_str[100];

    // get a string from the user to encrypt
    printf("Please enter a string to encrypt:\n");
    scanf("%s", original_str);

    // copy the original string to the encrypted string
    strcpy(encrypted_str, original_str);

    // encrypt the string
    encrypt(encrypted_str);

    // print out the encrypted string
    printf("The encrypted string is: %s\n", encrypted_str);

    // copy the encrypted string to the decrypted string
    strcpy(decrypted_str, encrypted_str);

    // decrypt the string
    decrypt(decrypted_str);

    // print out the decrypted string
    printf("The decrypted string is: %s\n", decrypted_str);

    return 0;
}