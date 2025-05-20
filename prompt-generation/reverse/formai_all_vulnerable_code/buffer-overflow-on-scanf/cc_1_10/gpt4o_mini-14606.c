//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 1024

// Function to encrypt the text using a simple Caesar cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A'; // Define base for lower and upper case
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

// Function to decrypt the text using a simple Caesar cipher
void decrypt(char *text, int shift) {
    encrypt(text, 26 - shift); // Decrypting is just reversing the shift
}

// Function to get the user's preference for encryption or decryption
int get_user_choice() {
    int choice;
    printf("Doo-doo-doo! Welcome to the Funny Encryptor Wizard!\n");
    printf("Would you like to: \n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("Choose wisely (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // Discard leftover newline character from buffer
    
    if (choice != 1 && choice != 2) {
        printf("Oops! You didn't choose 1 or 2. Let's just say you selected option 1 (Encryption)!\n");
        choice = 1;
    } 
    return choice;
}

// Function to get the shift value from the user
int get_shift_value() {
    int shift;
    printf("How many steps do you want to shift? Give me a number (1-25): ");
    scanf("%d", &shift);
    // Making sure the shift is in the valid range
    if (shift < 1 || shift > 25) {
        printf("Yikes! You picked a number that's outta bounds. I'm gonna use 3 instead!\n");
        shift = 3; // default shift value
    }
    return shift;
}

int main() {
    char text[MAX_INPUT];
    
    int choice = get_user_choice();
    int shift = get_shift_value();

    printf("Please enter your message (up to %d characters): ", MAX_INPUT - 1);
    fgets(text, MAX_INPUT, stdin);

    // Removing newline character from fgets
    text[strcspn(text, "\n")] = '\0';

    printf("\nYou entered: \"%s\"\n", text);

    if (choice == 1) {
        printf("Encrypting your message...\n");
        encrypt(text, shift);
        printf("🚀 Encrypted message: \"%s\"\n", text);
    } else {
        printf("Decrypting your message...\n");
        decrypt(text, shift);
        printf("🧐 Decrypted message: \"%s\"\n", text);
    }

    printf("\nThank you for using the Funny Encryptor Wizard! 💃💃\n");
    printf("Remember, with great power comes great responsibility... especially when it comes to secrets!\n");
    
    return 0;
}