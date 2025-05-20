//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *output, int key) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        output[i] = input[i] + key; // Simple Caesar cipher
    }
    output[i] = '\0'; // Null terminate the output string
}

void decrypt(char *input, char *output, int key) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        output[i] = input[i] - key; // Reverse the Caesar cipher
    }
    output[i] = '\0'; // Null terminate the output string
}

int main() {
    char input[256], encrypted[256], decrypted[256];
    int key;

    printf("Welcome to the C Encryption Program!\n");
    printf("Please enter a string to encrypt (max 255 characters): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline character

    printf("Enter a key for encryption (a positive integer): ");
    scanf("%d", &key);
    
    // Ensuring key is positive
    if (key < 0) {
        printf("Key must be a positive integer. Using absolute value.\n");
        key = abs(key);
    }

    encrypt(input, encrypted, key);
    printf("Encrypted string: %s\n", encrypted);

    // Now decrypt the string
    decrypt(encrypted, decrypted, key);
    printf("Decrypted string: %s\n", decrypted);

    // Provide an option for further encryption
    char choice;
    printf("Do you want to encrypt another string? (y/n): ");
    getchar(); // Clear the newline character from buffer
    scanf("%c", &choice);

    while (choice == 'y' || choice == 'Y') {
        printf("Please enter a new string to encrypt (max 255 characters): ");
        getchar(); // Clear the newline character from buffer
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove trailing newline character

        printf("Enter a new key for encryption (a positive integer): ");
        scanf("%d", &key);
        
        if (key < 0) {
            printf("Key must be a positive integer. Using absolute value.\n");
            key = abs(key);
        }

        encrypt(input, encrypted, key);
        printf("Encrypted string: %s\n", encrypted);
        decrypt(encrypted, decrypted, key);
        printf("Decrypted string: %s\n", decrypted);

        printf("Do you want to encrypt another string? (y/n): ");
        getchar(); // Clear the newline character from buffer
        scanf("%c", &choice);
    }

    printf("Thank you for using the C Encryption Program! Goodbye.\n");
    return 0;
}