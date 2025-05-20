//FormAI DATASET v1.0 Category: Encryption ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// Function to generate a random key for encryption
char *generateRandomKey(int keyLength){

    // Set of possible characters for key
    char possibleChar[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    char *key = (char*)malloc(keyLength*sizeof(char));

    // Generate a key randomly
    srand(time(NULL));
    for(int i=0; i<keyLength; i++){
        int randomIndex = rand() % strlen(possibleChar); // Generating random index from possibleChar array
        key[i] = possibleChar[randomIndex];
    }

    return key;
}

// Function to implement Caesar Cipher encryption
void caesarCipherEncrypt(char *message, int shift){

    int messageLength = strlen(message);

    // Loop through each character of message and shift the character
    for(int i=0; i<messageLength; i++){
        char currentChar = message[i];

        // Handle uppercase letters
        if(currentChar >= 'A' && currentChar <= 'Z'){
            currentChar = (currentChar + shift - 'A') % 26 + 'A';
        }

        // Handle lowercase letters
        else if(currentChar >= 'a' && currentChar <= 'z'){
            currentChar = (currentChar + shift - 'a') % 26 + 'a';
        }

        // Reassign the shifted character to message
        message[i] = currentChar;
    }
}

int main(){

    // Get the message to be encrypted
    char message[100];
    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]s", message);

    // Get the length of key from user
    int keyLength;
    printf("\nEnter the length of key: ");
    scanf("%d", &keyLength);

    // Generate a random key
    char *key = generateRandomKey(keyLength);
    printf("\nGenerated Key: %s", key);

    // Implement Caesar Cipher encryption using the generated key
    int keyIndex = 0;
    for(int i=0; i<strlen(message); i++){
        caesarCipherEncrypt(&message[i], key[keyIndex] - '0');
        keyIndex = (keyIndex + 1) % keyLength;
    }
    printf("\nEncrypted Message: %s", message);

    return 0;
}