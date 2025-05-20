//FormAI DATASET v1.0 Category: Encryption ; Style: decentralized
// Unique C Encryption Example Program - Decentralized Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

    // Encryption key
    char key[27] = "ZXCVBNMPOIUYTREWQASDFGHJKL";
    
    // Seed value for random number generator
    srand(time(NULL));
    
    // Generate a random integer between 1 and 26
    int shift = rand() % 26 + 1;
    
    // Message to be encrypted
    char message[100];
    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);
    
    // Remove the newline character from the end of the input string
    if ((strlen(message) > 0) && (message[strlen(message) - 1] == '\n'))
        message[strlen(message) - 1] = '\0';
    
    // Length of the input string
    int len = strlen(message);
    
    // Encrypted message
    char encrypted_message[len];
    
    // Encrypt the message using Caesar Cipher technique
    int i;
    for (i = 0; i < len; i++) {
        if (message[i] == ' ')
            encrypted_message[i] = ' ';
        else
            encrypted_message[i] = key[(message[i] - 'A' + shift) % 26];
    }
    
    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
    
    // Decrypted message
    char decrypted_message[len];
    
    // Decrypt the message using Caesar Cipher technique
    for (i = 0; i < len; i++) {
        if (encrypted_message[i] == ' ')
            decrypted_message[i] = ' ';
        else
            decrypted_message[i] = (key[(encrypted_message[i] - 'A' - shift + 26) % 26]);
    }
    
    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
    
    return 0;
}