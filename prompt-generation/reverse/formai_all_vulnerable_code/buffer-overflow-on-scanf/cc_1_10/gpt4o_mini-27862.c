//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using the Caesar cipher
void encrypt(char *message, int key) {
    for (int i = 0; message[i] != '\0'; i++) {
        // Shift uppercase letters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
        // Shift lowercase letters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
    }
}

// Function to decrypt the message using the Caesar cipher
void decrypt(char *message, int key) {
    // Decrypt by shifting in the reverse direction
    for (int i = 0; message[i] != '\0'; i++) {
        // Shift uppercase letters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';  // Added 26 to avoid negative
        }
        // Shift lowercase letters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';  // Added 26 to avoid negative
        }
    }
}

// Function to display the introduction to the application
void displayIntroduction() {
    printf("Welcome, dear user, to the Cryptography Chamber of Sherlock Holmes\n");
    printf("Here, we shall decode the secrets and encode our whispers\n");
    printf("Observe the secret passageways of letters and numbers!\n\n");
}

// Main function to run the cryptography application
int main() {
    displayIntroduction();

    char message[256];
    int key;
    char choice;

    while (1) {
        printf("Would you like to (E)ncrypt or (D)ecrypt a message? (Q to quit): ");
        choice = getchar();
        getchar(); // To consume newline character after choice

        if (choice == 'Q' || choice == 'q') {
            printf("Exiting the Cryptography Chamber. Farewell!\n");
            break;
        }

        printf("Please enter your message (max 255 characters): ");
        fgets(message, sizeof(message), stdin);
        
        // Remove trailing newline character added by fgets
        message[strcspn(message, "\n")] = 0;

        printf("Enter the key (1 to 25): ");
        scanf("%d", &key);
        getchar(); // To consume newline character after key input

        // Ensure the key is within the valid range
        if (key < 1 || key > 25) {
            printf("Invalid key. Please choose a key between 1 and 25.\n\n");
            continue;
        }

        if (choice == 'E' || choice == 'e') {
            encrypt(message, key);
            printf("Encrypted Message: %s\n\n", message);
        } else if (choice == 'D' || choice == 'd') {
            decrypt(message, key);
            printf("Decrypted Message: %s\n\n", message);
        } else {
            printf("Invalid choice. Please choose E, D, or Q.\n\n");
        }
    }

    return 0;
}