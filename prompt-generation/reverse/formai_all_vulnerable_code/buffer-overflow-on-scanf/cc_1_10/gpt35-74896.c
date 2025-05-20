//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: careful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// function to encrypt the message using Caesar cipher algorithm
char* caesar_cipher_encrypt(char message[], int shift) {
    int length = strlen(message);
    char* encrypted_message = (char*) malloc(length * sizeof(char));
    
    for(int i = 0; i < length; i++) {
        char ch = message[i];
        if(isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + shift) % 26 + base;
        } 
        encrypted_message[i] = ch;
    }
    encrypted_message[length] = '\0';
    return encrypted_message;
}

// function to decrypt the message using Caesar cipher algorithm
char* caesar_cipher_decrypt(char cipher[], int shift) {
    int length = strlen(cipher);
    char* decrypted_message = (char*) malloc(length * sizeof(char));
    
    for(int i = 0; i < length; i++) {
        char ch = cipher[i];
        if(isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base - shift + 26) % 26 + base;
        } 
        decrypted_message[i] = ch;
    }
    decrypted_message[length] = '\0';
    return decrypted_message;
}

int main() {
    char message[100], cipher[100], choice;
    int shift;
    printf("Enter 'E' to encrypt a message or 'D' to decrypt a message: ");
    scanf("%c", &choice);
    
    if(choice == 'E') {
        printf("Enter the message to encrypt: ");
        scanf(" %[^\n]%*c", message);
        
        printf("Enter the shift value: ");
        scanf("%d", &shift);
        
        char* encrypted_message = caesar_cipher_encrypt(message, shift);
        printf("Encrypted message: %s\n", encrypted_message);
        free(encrypted_message);
    } else if(choice == 'D') {
        printf("Enter the cipher to decrypt: ");
        scanf(" %[^\n]%*c", cipher);
        
        printf("Enter the shift value: ");
        scanf("%d", &shift);
        
        char* decrypted_message = caesar_cipher_decrypt(cipher, shift);
        printf("Decrypted message: %s\n", decrypted_message);
        free(decrypted_message);
    } else {
        printf("Invalid choice!\n");
    }
    
    return 0;
}