//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using Caesar cipher
void encrypt(char message[], int key) {
    int i = 0;
    while(message[i]!= '\0') {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = toupper(message[i] + key - 65);
            } else {
                message[i] = toupper(message[i] + key - 97);
            }
        }
        i++;
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char message[], int key) {
    int i = 0;
    while(message[i]!= '\0') {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = toupper(message[i] - key - 65);
            } else {
                message[i] = toupper(message[i] - key - 97);
            }
        }
        i++;
    }
}

int main() {
    char message[100];
    int key, choice;

    // Get the message and key from the user
    printf("Enter the message: ");
    scanf("%s", message);
    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt the message using Caesar cipher
    encrypt(message, key);

    // Display the encrypted message
    printf("Encrypted message: %s\n", message);

    // Ask the user if they want to decrypt the message
    printf("Do you want to decrypt the message? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);

    // Decrypt the message if the user chooses to
    if(choice == 1) {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }

    return 0;
}