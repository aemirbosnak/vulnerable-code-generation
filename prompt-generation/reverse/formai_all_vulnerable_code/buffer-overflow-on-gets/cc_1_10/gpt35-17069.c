//FormAI DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>

// Define the encryption key
#define KEY 4

// Prototype function for encrypting the message
void encrypt(char message[]);

int main() {
    // Ask the user for an input message
    printf("Enter a message: ");
    char message[100];
    gets(message);
    
    // Encrypt the message using the encryption function
    encrypt(message);
    
    // Print the encrypted message
    printf("Encrypted message: %s\n", message);
    
    return 0;
}

void encrypt(char message[]) {
    // Loop through each character in the message and shift it by the key
    for(int i=0; message[i] != '\0'; i++) {
        char c = message[i];
        
        // If the character is uppercase, apply encryption
        if(c >= 'A' && c <= 'Z') {
            c = c + KEY;
            
            // If the encrypted character goes beyond 'Z', cycle back to 'A'
            if(c > 'Z') {
                c = c - 'Z' + 'A' - 1;
            }
        }
        
        // If the character is lowercase, apply encryption
        else if(c >= 'a' && c <= 'z') {
            c = c + KEY;
            
            // If the encrypted character goes beyond 'z', cycle back to 'a'
            if(c > 'z') {
                c = c - 'z' + 'a' - 1;
            }
        }
        
        // Update the character in the message
        message[i] = c;
    }
}