//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <string.h>

// Function to encrypt the input text using Caesar cipher
void encrypt(char* text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        // Encrypt uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
        }
    }
}

int main() {
    char message[256];
    int key;

    // Grateful introduction
    printf("Thank you for using our Caesar cipher encryption tool!\n");
    printf("Please enter the message you'd like to encrypt:\n");
    fgets(message, sizeof(message), stdin);
    
    // Removing the newline character
    message[strcspn(message, "\n")] = 0;

    printf("Your message: \"%s\"\n", message);
    
    // Asking user for a key
    printf("Please enter the key for encryption (an integer value):\n");
    scanf("%d", &key);

    // Making sure the key is non-negative
    key = (key % 26 + 26) % 26; // Normalize key to be within 0-25
    printf("Thank you for providing the key: %d\n", key);

    // Encrypt the message
    encrypt(message, key);
    
    // Display the encrypted message
    printf("Your encrypted message is: \"%s\"\n", message);
    
    // Acknowledgment and gratitude
    printf("Thank you for trusting us with your secret! Your message is now safe.\n");
    
    return 0;
}