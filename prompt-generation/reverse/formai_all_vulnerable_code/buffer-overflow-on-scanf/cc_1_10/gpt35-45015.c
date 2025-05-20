//FormAI DATASET v1.0 Category: modern Encryption ; Style: content
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main() {
    char message[1000];
    char cipher[1000];
    int key, choice, i;

    // Get user input
    printf("Enter message: ");
    fgets(message, 1000, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Enter 1 to encrypt and 2 to decrypt: ");
    scanf("%d", &choice);

    // Define array of characters to be used in cipher
    char char_array[62] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    srand(time(NULL));

    // Encryption
    if (choice == 1) {
        for (i = 0; i < strlen(message); i++) {
            if (message[i] == ' ') {
                cipher[i] = ' ';
                continue;
            }

            int index = ((int)message[i] % 65) + key;
            cipher[i] = char_array[index % 62];
        }

        printf("Encrypted message: %s\n", cipher);
    }

    // Decryption
    else if (choice == 2) {
        for (i = 0; i < strlen(message); i++) {
            if (message[i] == ' ') {
                cipher[i] = ' ';
                continue;
            }

            int index = ((int)message[i] % 65) - key;
            if (index < 0) {
                index = 62 + index;
            }
            cipher[i] = char_array[index % 62];
        }

        printf("Decrypted message: %s\n", cipher);
    }

    // If invalid choice
    else {
        printf("Invalid choice\n");
    }

    return 0;
}