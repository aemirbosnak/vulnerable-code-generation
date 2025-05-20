//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void encrypt(char *plaintext, char *ciphertext, int key);
void decrypt(char *ciphertext, char *plaintext, int key);
void to_uppercase(char *text);
int is_alpha(char c);
void print_menu();

// Main function
int main() {
    int choice, key;
    char input[256];
    char output[256];

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character

        if (choice == 3) {
            printf("Exiting...\n");
            break;
        }

        printf("Enter the key (1-25): ");
        scanf("%d", &key);
        getchar();  // Consume the newline character
        
        if (key < 1 || key > 25) {
            printf("Invalid key. Please enter a key between 1 and 25.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter plaintext: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;  // Remove newline character
                
                encrypt(input, output, key);
                printf("Ciphertext: %s\n", output);
                break;

            case 2:
                printf("Enter ciphertext: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;  // Remove newline character
                
                decrypt(input, output, key);
                printf("Plaintext: %s\n", output);
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

// Function to encrypt plaintext using Caesar cipher
void encrypt(char *plaintext, char *ciphertext, int key) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (is_alpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = (plaintext[i] - base + key) % 26 + base;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';  // Null-terminate the ciphertext
}

// Function to decrypt ciphertext using Caesar cipher
void decrypt(char *ciphertext, char *plaintext, int key) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (is_alpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            plaintext[i] = (ciphertext[i] - base - key + 26) % 26 + base;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0';  // Null-terminate the plaintext
}

// Function to check if a character is an alphabetic character
int is_alpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Function to print the menu
void print_menu() {
    printf("\n--- Caesar Cipher ---\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
}