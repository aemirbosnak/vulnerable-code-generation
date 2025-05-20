//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LENGTH 1024

// Function prototypes
void encrypt(char *input, char *output, int key);
void decrypt(char *input, char *output, int key);
void displayAct(char *act);
void prologue();
void epilogue();

int main() {
    prologue();

    char message[MAX_MSG_LENGTH];
    char encrypted[MAX_MSG_LENGTH];
    char decrypted[MAX_MSG_LENGTH];
    int key;

    // Act 1: A Message is Born
    printf("Enter the secret message to encrypt, dear Juliet: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove trailing newline

    printf("Choose a key for encryption, noble Romeo (1-25): ");
    scanf("%d", &key);
    
    // Act 2: The Encryption Dance
    encrypt(message, encrypted, key);
    printf("\nAlas, I have encrypted thy message: \n%s\n", encrypted);

    // Act 3: The Decryption Truth
    decrypt(encrypted, decrypted, key);
    printf("\nAs daylight breaks, here lies the original message: \n%s\n", decrypted);
    
    epilogue();
    return 0;
}

// Function to encrypt the message
void encrypt(char *input, char *output, int key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = (input[i] - 'a' + key) % 26 + 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = (input[i] - 'A' + key) % 26 + 'A';
        } else {
            output[i] = input[i]; // Non-alphabetic characters remain unchanged
        }
    }
    output[i] = '\0'; // Null-terminate the output string
}

// Function to decrypt the message
void decrypt(char *input, char *output, int key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = (input[i] - 'a' - key + 26) % 26 + 'a'; // Adding 26 to handle negative values
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = (input[i] - 'A' - key + 26) % 26 + 'A';
        } else {
            output[i] = input[i]; // Non-alphabetic characters remain unchanged
        }
    }
    output[i] = '\0'; // Null-terminate the output string
}

// Function for prologue
void prologue() {
    printf("A tale of two lovers and a secret, \n");
    printf("In the realm of cryptography, let us embark upon a journey. \n");
}

// Function for epilogue
void epilogue() {
    printf("Thus concludes our story, encrypted and decrypted. \n");
    printf("May the hearts remain united and the secrets kept safe!\n");
}