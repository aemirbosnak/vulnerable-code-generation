//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

void encrypt(char *input, int shift, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];

        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            output[i] = (c - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            output[i] = (c - 'a' + shift) % 26 + 'a';
        }
        // Non-alphabetical characters remain unchanged
        else {
            output[i] = c;
        }
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

void decrypt(char *input, int shift, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];

        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            output[i] = (c - 'A' - shift + 26) % 26 + 'A'; // Adding 26 to avoid negative
        }
        // Decrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            output[i] = (c - 'a' - shift + 26) % 26 + 'a'; // Adding 26 to avoid negative
        }
        // Non-alphabetical characters remain unchanged
        else {
            output[i] = c;
        }
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

void showBanner() {
    printf("\n*** Shape-Shifting Encryption Tool ***\n\n");
    printf("Enter your secret message, and let the encryption begin!\n");
}

int main() {
    char input[MAX_LEN];
    char encrypted[MAX_LEN];
    char decrypted[MAX_LEN];
    int shift;

    showBanner();
    
    printf("Enter a message to encrypt (max %d characters): ", MAX_LEN - 1);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline character

    printf("Enter shift value for encryption (1-25): ");
    scanf("%d", &shift);
    shift = (shift % 26 + 26) % 26; // Normalize shift value to be in range [0,25]

    encrypt(input, shift, encrypted);
    printf("\nEncrypted message: %s\n", encrypted);

    decrypt(encrypted, shift, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    printf("\nThank you for using the Shape-Shifting Encryption Tool!\n");
    return 0;
}