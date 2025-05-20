//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 256

// Encryption function
void encrypt(char* text, int shift) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        char c = text[i];
        c += shift;
        if (c > 'z') c -= 26;
        text[i] = c;
    }
}

// Decryption function
void decrypt(char* text, int shift) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        char c = text[i];
        c -= shift;
        if (c < 'a') c += 26;
        text[i] = c;
    }
}

// Main function
int main() {
    char text[MAX_SIZE];
    printf("Enter the text to encrypt/decrypt: ");
    fgets(text, sizeof(text), stdin);

    // Get shift value from user
    printf("Enter the shift value (0-25): ");
    int shift;
    scanf("%d", &shift);

    // Check if shift is valid
    if (shift < 0 || shift > 25) {
        printf("Invalid shift value!\n");
        return 1;
    }

    // Prompt user for encryption or decryption
    printf("Encrypt or Decrypt (e/d)?: ");
    char choice;
    scanf(" %c", &choice);

    // Encrypt or decrypt the text
    if (choice == 'e') {
        encrypt(text, shift);
    } else if (choice == 'd') {
        decrypt(text, shift);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    // Display the encrypted/decrypted text
    printf("Encrypted/Decrypted text: %s\n", text);

    return 0;
}