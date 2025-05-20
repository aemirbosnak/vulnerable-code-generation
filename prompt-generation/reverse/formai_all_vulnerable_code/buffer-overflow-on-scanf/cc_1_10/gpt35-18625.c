//FormAI DATASET v1.0 Category: Modern Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a given message using the Caesar Cipher
char* encrypt(char* message, int key){
    int i;
    char ch;
    char* result = (char*) malloc(sizeof(char) * strlen(message));
    
    for(i = 0; message[i] != '\0'; i++){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = (ch + key - 'a') % 26 + 'a';
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = (ch + key - 'A') % 26 + 'A';
        }
        result[i] = ch;
    }
    result[i] = '\0';
    return result;
}

// Function to decrypt a given message using the Caesar Cipher
char* decrypt(char* message, int key){
    int i;
    char ch;
    char* result = (char*) malloc(sizeof(char) * strlen(message));
    
    for(i = 0; message[i] != '\0'; i++){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = (ch - key - 'a' + 26) % 26 + 'a';
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = (ch - key - 'A' + 26) % 26 + 'A';
        }
        result[i] = ch;
    }
    result[i] = '\0';
    return result;
}

// Main function to test the encryption and decryption functions
int main(){
    char message[100], *encrypted, *decrypted;
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    // Encrypt the message
    encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    // Decrypt the message
    decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);

    // Free the memory allocated for encrypted and decrypted messages
    free(encrypted);
    free(decrypted);

    return 0;
}