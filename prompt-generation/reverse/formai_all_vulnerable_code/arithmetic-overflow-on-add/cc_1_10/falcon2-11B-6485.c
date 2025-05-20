//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: relaxed
#include <stdio.h>
#include <string.h>

// Function to encrypt a string using the Caesar cipher
void encrypt(char* str, int shift) {
    // Iterate through each character in the string
    for (int i = 0; str[i]!= '\0'; i++) {
        // If the character is a letter, encrypt it
        if (str[i] >= 'a' && str[i] <= 'z') {
            char c = str[i] - 'a' + shift;
            if (c > 'z') {
                c = c - 26;
            }
            str[i] = c + 'a';
        }
        // If the character is a number, leave it unchanged
        else if (str[i] >= '0' && str[i] <= '9') {
            str[i] = str[i];
        }
        // If the character is a special character, leave it unchanged
        else {
            str[i] = str[i];
        }
    }
}

// Function to decrypt a string using the Caesar cipher
void decrypt(char* str, int shift) {
    // Iterate through each character in the string
    for (int i = 0; str[i]!= '\0'; i++) {
        // If the character is a letter, decrypt it
        if (str[i] >= 'a' && str[i] <= 'z') {
            char c = str[i] - 'a' - shift;
            if (c < 'a') {
                c = c + 26;
            }
            str[i] = c + 'a';
        }
        // If the character is a number, leave it unchanged
        else if (str[i] >= '0' && str[i] <= '9') {
            str[i] = str[i];
        }
        // If the character is a special character, leave it unchanged
        else {
            str[i] = str[i];
        }
    }
}

int main() {
    // Prompt the user for an input string
    printf("Enter a string to encrypt: ");
    char input[100];
    scanf("%s", input);

    // Prompt the user for an encryption shift
    printf("Enter an encryption shift (0-25): ");
    int shift;
    scanf("%d", &shift);

    // Encrypt the input string
    encrypt(input, shift);

    // Print the encrypted string
    printf("Encrypted string: %s\n", input);

    // Prompt the user for a decryption shift
    printf("Enter a decryption shift (0-25): ");
    int decrypt_shift;
    scanf("%d", &decrypt_shift);

    // Decrypt the encrypted string
    decrypt(input, decrypt_shift);

    // Print the decrypted string
    printf("Decrypted string: %s\n", input);

    return 0;
}