//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: creative
#include <stdio.h>
#include <string.h>

// Function to encrypt the plaintext using Caesar Cipher
void encrypt(char *plaintext, int shift) {
    int i;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        char current = plaintext[i];
        // Encrypt uppercase letters
        if (current >= 'A' && current <= 'Z') {
            plaintext[i] = (current + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (current >= 'a' && current <= 'z') {
            plaintext[i] = (current + shift - 'a') % 26 + 'a';
        }
    }
}

// Function to decrypt the ciphertext using Caesar Cipher
void decrypt(char *ciphertext, int shift) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; ++i) {
        char current = ciphertext[i];
        // Decrypt uppercase letters
        if (current >= 'A' && current <= 'Z') {
            ciphertext[i] = (current - shift - 'A' + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (current >= 'a' && current <= 'z') {
            ciphertext[i] = (current - shift - 'a' + 26) % 26 + 'a';
        }
    }
}

// Function to display the menu for user interaction
void display_menu() {
    printf("Caesar Cipher Encryption and Decryption\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}

int main() {
    char input[256];
    int shift, choice;

    // Display the menu to the user
    while (1) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please select again.\n");
            continue;
        }

        printf("Enter the shift value (1-25): ");
        scanf("%d", &shift);
        if (shift < 1 || shift > 25) {
            printf("Invalid shift value. Please enter a value between 1 and 25.\n");
            continue;
        }

        printf("Enter the message: ");
        getchar(); // clear the newline character after shift input
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // remove the newline character

        if (choice == 1) {
            encrypt(input, shift);
            printf("Encrypted message: %s\n", input);
        } else if (choice == 2) {
            decrypt(input, shift);
            printf("Decrypted message: %s\n", input);
        }
    }

    return 0;
}