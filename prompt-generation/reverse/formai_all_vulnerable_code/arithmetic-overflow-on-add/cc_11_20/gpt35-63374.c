//FormAI DATASET v1.0 Category: modern Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple Caesar Cipher encryption and decryption program

int main() {
    // User input for encryption text
    char message[1000];
    printf("Enter message to encrypt: ");
    fgets(message, 1000, stdin);
    
    // User input for key
    int key;
    printf("Enter key (between 1-26): ");
    scanf("%d", &key);
    
    // Encryption process
    int i = 0;
    while (message[i] != '\0') {
        // If letter is uppercase
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        }
        // If letter is lowercase
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
        i++;
    }
    
    printf("Your encrypted message is: %s\n", message);
    
    // Decryption process
    i = 0;
    while (message[i] != '\0') {
        // If letter is uppercase
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') - key + 26) % 26 + 'A';
        }
        // If letter is lowercase
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') - key + 26) % 26 + 'a';
        }
        i++;
    }
    
    printf("Your original message is: %s\n", message);
    
    return 0;
}