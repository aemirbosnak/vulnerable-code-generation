//FormAI DATASET v1.0 Category: Encryption ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the Caesar Cipher Encryption Program!\n");
    
    char message[1000];
    int key, choice, i;
    
    printf("Please enter your message: ");
    fgets(message, 1000, stdin);
    
    printf("\nPlease enter the encryption key: ");
    scanf("%d", &key);
    
    printf("\nWould you like to encrypt or decrypt?\n");
    printf("Enter 1 to encrypt, 2 to decrypt: ");
    scanf("%d", &choice);
    
    // Encryption
    if (choice == 1) {
        for (i = 0; i < strlen(message); i++) {
            if (message[i] >= 'A' && message[i] <= 'Z') {
                message[i] = ((message[i] - 'A' + key) % 26) + 'A';
            }
            else if (message[i] >= 'a' && message[i] <= 'z') {
                message[i] = ((message[i] - 'a' + key) % 26) + 'a';
            }
        }
        printf("\nYour encrypted message is: %s", message);
    }
    // Decryption
    else if (choice == 2) {
        for (i = 0; i < strlen(message); i++) {
            if (message[i] >= 'A' && message[i] <= 'Z') {
                message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
            }
            else if (message[i] >= 'a' && message[i] <= 'z') {
                message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
            }
        }
        printf("\nYour decrypted message is: %s", message);
    }
    // Invalid input
    else {
        printf("\nInvalid input. Please choose either 1 or 2.");
    }
    
    return 0;
}