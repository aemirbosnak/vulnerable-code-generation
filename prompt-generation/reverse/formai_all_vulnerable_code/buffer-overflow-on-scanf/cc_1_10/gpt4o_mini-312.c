//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: romantic
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024

// A function to encrypt the text
void encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] += key; // Shift each character
    }
}

// A function to decrypt the text
void decrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] -= key; // Reverse the shift
    }
}

// A function to greet the user in a romantic style
void greet() {
    printf("************************************\n");
    printf("*                                  *\n");
    printf("*   Welcome to the Love Cipher!    *\n");
    printf("*   Where your secrets are cherished *\n");
    printf("************************************\n");
}

// A function to get user input gracefully
void get_input(char *buffer, const char *prompt) {
    printf("%s", prompt);
    fgets(buffer, MAX_TEXT_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Strip newline character
}

// The main function
int main() {
    char text[MAX_TEXT_LENGTH];
    int key;

    greet(); // Start the romance with a soft voice

    // Get the text to encrypt
    get_input(text, "Please share your romantic message: ");
    
    // Get the secret key
    printf("Now, share your secret key (a number to secure your words): ");
    scanf("%d", &key);
    while (getchar() != '\n'); // Clean the buffer

    // Encrypt the message for that special someone
    printf("Encrypting your message...\n");
    encrypt(text, key);

    // Show the encrypted message
    printf("Your encrypted message is: \"%s\"\n", text);

    // Ask if they want to decrypt the message
    char choice;
    printf("Would you like to decode your message? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y') {
        while (getchar() != '\n'); // Clean the buffer again
        decrypt(text, key); // Decrypting the affectionate words
        printf("Your decrypted message is: \"%s\"\n", text);
    } else {
        printf("Keeping your words safe for now...\n");
    }

    // A heartfelt closing
    printf("Remember, love is a secret that is worth keeping...\n");
    printf("Until next time, keep your heart open!\n");

    return 0;
}