//FormAI DATASET v1.0 Category: Modern Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* C Modern Encryption Program */

void encrypt(char *plaintext, int key){

    int length = strlen(plaintext);

    // Loop through every character
    for(int i=0; i<length; i++){
        // Add the key to the ASCII value of the character
        plaintext[i] = plaintext[i] + key;

        // If the new character value is outside the ASCII range (0-127),
        // subtract 127 to keep it within range
        if(plaintext[i] > 127){
            plaintext[i] = plaintext[i] - 127;
        }
    }
}

void decrypt(char *ciphertext, int key){

    int length = strlen(ciphertext);

    // Loop through every character
    for(int i=0; i<length; i++){
        // Subtract the key from the ASCII value of the character
        ciphertext[i] = ciphertext[i] - key;

        // If the new character value is outside the ASCII range (0-127),
        // add 127 to keep it within range
        if(ciphertext[i] < 0){
            ciphertext[i] = ciphertext[i] + 127;
        }
    }
}

int main(){

    char message[1000];
    int key;

    printf("Welcome to the C Modern Encryption Program!\n");
    printf("Please enter a message to encrypt: ");

    // Read in the message from the user
    fgets(message, 1000, stdin);

    printf("Please enter a key to use for encryption: ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);

    // Print out the encrypted message
    printf("\nThe encrypted message is: %s\n", message);

    // Decrypt the message
    decrypt(message, key);

    // Print out the decrypted message
    printf("\nThe decrypted message is: %s\n", message);

    return 0;
}