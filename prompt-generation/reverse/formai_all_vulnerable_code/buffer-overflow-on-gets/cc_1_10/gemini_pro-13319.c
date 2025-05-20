//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: creative
// Cryptic Castle: A C Encryption Adventure

#include <stdio.h>
#include <stdlib.h>

// The secret passphrase to unlock the castle
#define PASSPHRASE "abracadabra"

// Initialize a maze of characters
char maze[10][10] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};

// Define the encryption key
int encryptionKey = 13;

// Function to encrypt a character
char encryptCharacter(char character) {
    return character + encryptionKey;
}

// Function to print the encrypted message
void printEncryptedMessage(char *message) {
    while (*message) {
        printf("%c", encryptCharacter(*message));
        message++;
    }
}

// Function to navigate the maze and find the key
char findKey(char **maze, char *passphrase) {
    int i, j;

    // Loop through the maze and check for the passphrase
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (maze[i][j] == passphrase[0]) {
                // Found the first character of the passphrase

                // Check if the rest of the passphrase matches
                int k = 1;
                while (passphrase[k] != '\0' && maze[i][j + k] == passphrase[k]) {
                    k++;
                }

                // If the passphrase matches, return the key
                if (passphrase[k] == '\0') {
                    return maze[i + 1][j + 1];
                }
            }
        }
    }

    // Return a blank character if the key was not found
    return '\0';
}

// Main function
int main() {
    // Get the message from the user
    char message[100];
    printf("Enter your secret message: ");
    gets(message);

    // Find the key in the maze
    char key = findKey(maze, PASSPHRASE);

    // Encrypt the message using the key
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        message[i] = encryptCharacter(message[i]);
    }

    // Print the encrypted message
    printf("Your encrypted message: ");
    printEncryptedMessage(message);

    printf("\n");

    return 0;
}