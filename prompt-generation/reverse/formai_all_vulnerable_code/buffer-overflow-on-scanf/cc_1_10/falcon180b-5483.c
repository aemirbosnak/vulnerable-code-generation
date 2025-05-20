//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26

// Function to encrypt the message
void encrypt(char message[], int key) {
    int i, j;

    // Loop through each character in the message
    for (i = 0; message[i]!= '\0'; i++) {
        // Convert the character to uppercase
        message[i] = toupper(message[i]);

        // Encrypt the character
        if (isalpha(message[i])) {
            j = (message[i] - 'A') + key;

            // Wrap around if necessary
            if (j > 'Z') {
                j = j - 26;
            }

            message[i] = j;
        }
    }
}

// Function to decrypt the message
void decrypt(char message[], int key) {
    int i, j;

    // Loop through each character in the message
    for (i = 0; message[i]!= '\0'; i++) {
        // Convert the character to uppercase
        message[i] = toupper(message[i]);

        // Decrypt the character
        if (isalpha(message[i])) {
            j = (message[i] - 'A') - key;

            // Wrap around if necessary
            if (j < 0) {
                j = j + 26;
            }

            message[i] = j;
        }
    }
}

// Function to print the Caesar cipher table
void print_table(int key) {
    int i;

    for (i = 0; i < SIZE; i++) {
        printf("%c ", i + 'A');
    }

    printf("\n");

    for (i = 0; i < SIZE; i++) {
        printf("%c ", (i + key) % SIZE + 'A');
    }

    printf("\n");
}

// Main function
int main() {
    char message[1000];
    int key, choice;

    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    printf("\n");

    while (1) {
        printf("1. Encrypt\n2. Decrypt\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            encrypt(message, key);
            printf("\nEncrypted message: %s\n", message);
            break;

        case 2:
            decrypt(message, key);
            printf("\nDecrypted message: %s\n", message);
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

        printf("\n");
    }

    return 0;
}