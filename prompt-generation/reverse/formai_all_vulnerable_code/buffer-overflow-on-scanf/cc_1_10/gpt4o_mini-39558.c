//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the text using Caesar cipher
void encrypt(char *plaintext, int key, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        // Only encrypt alphabetic characters
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = 'a' + (plaintext[i] - 'a' + key) % 26;
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = 'A' + (plaintext[i] - 'A' + key) % 26;
        } else {
            ciphertext[i] = plaintext[i]; // Non-alphabetic characters remain unchanged
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the string
}

// Function to decrypt the text using Caesar cipher
void decrypt(char *ciphertext, int key, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        // Only decrypt alphabetic characters
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = 'a' + (ciphertext[i] - 'a' - key + 26) % 26;
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = 'A' + (ciphertext[i] - 'A' - key + 26) % 26;
        } else {
            plaintext[i] = ciphertext[i]; // Non-alphabetic characters remain unchanged
        }
    }
    plaintext[i] = '\0'; // Null-terminate the string
}

// The wise scribe's event that unfolds in the castle of alphabets
void print_intro() {
    printf("Greetings, noble traveler!\n");
    printf("In this enchanted world of letters, vile foes lurk.\n");
    printf("Wield the power of the Caesar cipher and safeguard thy secrets.\n\n");
}

// Main function where the tale begins
int main() {
    int key;
    char plaintext[1024], ciphertext[1024], decryptedtext[1024];

    // Introduce the tale
    print_intro();

    // The noble scribe requests plaintext
    printf("Speak your message (plain text): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove trailing newline

    // Ask for the key from the wise seer
    printf("What legendary key dost thou choose? (1-25): ");
    scanf("%d", &key);
    while (key < 1 || key > 25) { // Key should be in the range 1-25
        printf("Choose wisely, for the key must be between 1 and 25: ");
        scanf("%d", &key);
    }

    // Encrypt the message
    encrypt(plaintext, key, ciphertext);
    printf("\nThy encoded message shall be:\n%s\n", ciphertext);

    // Now, let us decrypt the message
    decrypt(ciphertext, key, decryptedtext);
    printf("\nWith the seer's art, your original message returns:\n%s\n", decryptedtext);

    // The tale concludes
    printf("\nThus ends this chapter of encryption and decryption.\n");
    printf("May your secrets remain cloaked in shadows!\n");

    return 0; // Exit the wise scribe's abode
}