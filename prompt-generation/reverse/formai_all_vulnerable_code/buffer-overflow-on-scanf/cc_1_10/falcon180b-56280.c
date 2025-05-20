//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 26

// Function to encrypt the message
void encrypt(char *message) {
    int i, j, k = 0;
    char temp[1000];

    // Copy the message to temporary string
    strcpy(temp, message);

    // Convert message to uppercase
    for (i = 0; temp[i]!= '\0'; i++) {
        temp[i] = toupper(temp[i]);
    }

    // Encrypt the message
    for (i = 0; temp[i]!= '\0'; i++) {
        if (isalpha(temp[i])) {
            if (isupper(temp[i])) {
                temp[i] = (char) (((int) temp[i] - 65 + k) % SIZE + 65);
            }
            else {
                temp[i] = (char) (((int) temp[i] - 97 + k) % SIZE + 97);
            }
        }
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", temp);
}

// Function to decrypt the message
void decrypt(char *message) {
    int i, j, k = 0;
    char temp[1000];

    // Copy the message to temporary string
    strcpy(temp, message);

    // Convert message to uppercase
    for (i = 0; temp[i]!= '\0'; i++) {
        temp[i] = toupper(temp[i]);
    }

    // Decrypt the message
    for (i = 0; temp[i]!= '\0'; i++) {
        if (isalpha(temp[i])) {
            if (isupper(temp[i])) {
                temp[i] = (char) (((int) temp[i] - 65 - k + 26) % SIZE + 65);
            }
            else {
                temp[i] = (char) (((int) temp[i] - 97 - k + 26) % SIZE + 97);
            }
        }
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", temp);
}

int main() {
    char message[1000], choice;
    int i;

    printf("Enter the message to encrypt/decrypt: ");
    scanf("%[^\n]", message);

    printf("Enter 'e' to encrypt or 'd' to decrypt: ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'e':
            encrypt(message);
            break;
        case 'd':
            decrypt(message);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}