//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: excited
/*
 * Unique C Encryption Example Program
 *
 * This program demonstrates a simple encryption method using
 * the Caesar cipher.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using the Caesar cipher
void encrypt(char *str, int shift) {
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            j = str[i] - 'a';
            j = (j + shift) % 26;
            str[i] = j + 'a';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            j = str[i] - 'A';
            j = (j + shift) % 26;
            str[i] = j + 'A';
        }
    }
}

// Function to decrypt a string using the Caesar cipher
void decrypt(char *str, int shift) {
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            j = str[i] - 'a';
            j = (j - shift) % 26;
            str[i] = j + 'a';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            j = str[i] - 'A';
            j = (j - shift) % 26;
            str[i] = j + 'A';
        }
    }
}

// Main function to test the encryption and decryption functions
int main() {
    char str[100];
    int shift;
    printf("Enter a string to encrypt: ");
    scanf("%s", str);
    printf("Enter a shift value (1-25): ");
    scanf("%d", &shift);
    encrypt(str, shift);
    printf("Encrypted string: %s\n", str);
    decrypt(str, shift);
    printf("Decrypted string: %s\n", str);
    return 0;
}