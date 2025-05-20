//FormAI DATASET v1.0 Category: Encryption ; Style: satisfied
#include<stdio.h>
#include<string.h>

// Function to perform Caesar Cipher encryption
void caesar_cipher_encrypt(char* plaintext, int shift) {
    int i;

    // Iterate through each character in plaintext
    for(i = 0; i < strlen(plaintext); i++) {
        // Apply the shift to each character
        plaintext[i] = (plaintext[i] + shift - 'a') % 26 + 'a';
    }

    // Print the encrypted text
    printf("Encrypted text: %s\n", plaintext);
}

// Function to perform Vigenere Cipher encryption
void vigenere_cipher_encrypt(char* plaintext, char* key) {
    int i, j;

    // Iterate through each character in plaintext
    for(i = 0, j = 0; i < strlen(plaintext); i++, j++) {
        // Wrap around key if it is shorter than plaintext
        if(j == strlen(key)) {
            j = 0;
        }

        // Apply the shift from key to each character in plaintext
        plaintext[i] = (plaintext[i] + key[j] - 2 * 'a') % 26 + 'a';
    }

    // Print the encrypted text
    printf("Encrypted text: %s\n", plaintext);
}

int main() {
    char plaintext[100], key[100];
    int choice, shift;

    // Get plaintext string from user
    printf("Enter plaintext string: ");
    gets(plaintext);

    // Get encryption method from user
    printf("Choose an encryption method:\n");
    printf("1. Caesar Cipher\n");
    printf("2. Vigenere Cipher\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform encryption based on user choice
    switch(choice) {
        case 1:
            // Get shift value from user
            printf("Enter shift value: ");
            scanf("%d", &shift);
            caesar_cipher_encrypt(plaintext, shift);
            break;
        case 2:
            // Get key from user
            printf("Enter key: ");
            scanf("%s", key);
            vigenere_cipher_encrypt(plaintext, key);
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}