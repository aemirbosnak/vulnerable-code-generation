//FormAI DATASET v1.0 Category: Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

//Function to encrypt the string
void encrypt(char *message, int key) {
    int i;
    //iterating through each character of the string
    for (i = 0; message[i] != '\0'; ++i) {
        // encrypting uppercase characters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        } 
        // encrypting lowercase characters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
    }
    printf("Encrypted Message: %s\n", message);
}

//Function to decrypt the string
void decrypt(char *message, int key) {
    int i;
    //iterating through each character of the string
    for (i = 0; message[i] != '\0'; ++i) {
        // decrypting uppercase characters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') - key + 26) % 26 + 'A';
        }
        // decrypting lowercase characters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') - key + 26) % 26 + 'a';
        }
    }
    printf("Decrypted Message: %s\n", message);
}

int main() {
    char message[100];
    int key, choice;
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter the key: ");
    scanf("%d", &key);
    // Displaying the menu
    printf("Choose the operation:\n");
    printf("1 => Encrypt\n2 => Decrypt\n");
    scanf("%d", &choice);
    // Removing unwanted characters from message
    message[strcspn(message, "\n")] = 0;
    // Calling encrypt or decrypt based on user choice
    if (choice == 1) {
        encrypt(message, key);
    } else if (choice == 2) {
        decrypt(message, key);
    } else {
        printf("Invalid Choice!\n");
    }
    return 0;
}