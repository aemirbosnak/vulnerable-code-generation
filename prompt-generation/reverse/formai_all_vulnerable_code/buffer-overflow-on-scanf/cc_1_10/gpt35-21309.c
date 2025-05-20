//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multivariable
#include<stdio.h>
#include<string.h>

void convertToUpper(char* message) {// Function to convert plaintext message to uppercase
    int i;
    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - 32;
        }
    }
}

void encryptMessage(char* message, int key) {// Function to encrypt the plaintext message using key
    int i;
    for(i = 0; message[i] != '\0'; i++) {
        int charValue = message[i] - 65;
        charValue = (charValue + key) % 26;
        message[i] = charValue + 65;
    }
}

void decryptMessage(char* message, int key) {// Function to decrypt the encrypted message using key
    int i;
    for(i = 0; message[i] != '\0'; i++) {
        int charValue = message[i] - 65;
        charValue = (charValue - key + 26) % 26;
        message[i] = charValue + 65;
    }
}

int main() {
    char message[100], choice;
    int key;
    do {
        printf("Enter the message to encrypt: ");
        scanf(" %[^\n]", message);

        printf("Enter the key value (0-25): ");
        scanf("%d", &key);

        convertToUpper(message);// Convert message to uppercase

        printf("Plaintext message: %s\n", message);

        encryptMessage(message, key);// Call encryptMessage function to encrypt the message

        printf("Encrypted message: %s\n", message);

        decryptMessage(message, key);// Call decryptMessage function to decrypt the message

        printf("Decrypted message: %s\n", message);

        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');

    return 0;
}