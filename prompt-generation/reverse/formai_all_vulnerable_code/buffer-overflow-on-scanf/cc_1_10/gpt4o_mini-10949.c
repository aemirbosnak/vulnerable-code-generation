//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16 // Size of the key, must match with the text block size
#define MAX_MESSAGE_LENGTH 256
#define MAX_KINGDOMS 10

// Function to encrypt the message using a Caesar cipher
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        // Encrypting only alphabetic characters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + shift) % 26) + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + shift) % 26) + 'a';
        }
    }
}

// Function to decrypt the message using a Caesar cipher
void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        // Decrypting only alphabetic characters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' - shift + 26) % 26) + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' - shift + 26) % 26) + 'a';
        }
    }
}

// Function to print a royal proclamation
void print_proclamation(const char *message) {
    printf("Hark! A Proclamation:\n");
    printf("%s\n", message);
}

// Main execution of the program
int main() {
    char message[MAX_MESSAGE_LENGTH];
    char kingdoms[MAX_KINGDOMS][30] = { "Avalon", "Camelot", "Gondor", "Hogwarts", "Narnia", "Rohan", "Westeros", "Valinor", "Zamunda", "Mordor" };
    int shift = 3;

    printf("To which kingdom dost thou wish to send thy message?\n");
    for (int i = 0; i < MAX_KINGDOMS; i++) {
        printf("%d. %s\n", i + 1, kingdoms[i]);
    }

    int kingdom_choice;
    scanf("%d", &kingdom_choice);
    getchar(); // To consume the newline character left in the buffer

    if (kingdom_choice < 1 || kingdom_choice > MAX_KINGDOMS) {
        printf("Alas! That is not a valid choice, dear traveler.\n");
        return 1;
    }

    printf("Speak thy message for the kingdom of %s:\n", kingdoms[kingdom_choice - 1]);
    fgets(message, sizeof(message), stdin);
    // Remove newline character if present
    message[strcspn(message, "\n")] = 0;

    print_proclamation("We now encrypt thine message.");
    encrypt(message, shift);
    printf("Encrypted message for %s: %s\n", kingdoms[kingdom_choice - 1], message);

    print_proclamation("Now, let us return this message to its original form.");
    decrypt(message, shift);
    printf("Decrypted message: %s\n", message);

    return 0;
}