//Falcon-180B DATASET v1.0 Category: Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt message
void encrypt(char *message, int key) {
    int i, j;
    char temp;

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] + key - 65) % 26 + 65;
            } else {
                message[i] = (message[i] + key - 97) % 26 + 97;
            }
        }
    }
}

// Function to decrypt message
void decrypt(char *message, int key) {
    int i, j;
    char temp;

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - key - 65) % 26 + 65;
            } else {
                message[i] = (message[i] - key - 97) % 26 + 97;
            }
        }
    }
}

int main() {
    char message[1000], key;
    int choice, i;

    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    printf("Enter the key (1-25): ");
    scanf("%d", &key);

    printf("Enter 1 to encrypt the message\nEnter 2 to decrypt the message: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s", message);
            break;

        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s", message);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}