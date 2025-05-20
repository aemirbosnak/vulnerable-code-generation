//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

// Function to encrypt the message using a simple substitution cipher
void encrypt(char message[], int shift){
    int i;
    for(i=0; message[i]!='\0'; i++){
        if(message[i]>='a' && message[i]<='z'){
            message[i] = (message[i] + shift - 'a') % 26 + 'a'; // Shift each letter by "shift" position
        }
        else if(message[i]>='A' && message[i]<='Z'){
            message[i] = (message[i] + shift - 'A') % 26 + 'A';
        }
    }
}

// Function to decrypt the message using the same substitution cipher
void decrypt(char message[], int shift){
    int i;
    for(i=0; message[i]!='\0'; i++){
        if(message[i]>='a' && message[i]<='z'){
            message[i] = (message[i] - shift - 'a' + 26) % 26 + 'a'; // Shift each letter back by "shift" position
        }
        else if(message[i]>='A' && message[i]<='Z'){
            message[i] = (message[i] - shift - 'A' + 26) % 26 + 'A';
        }
    }
}

int main(){
    char message[MAX_SIZE], encrypted_message[MAX_SIZE], decrypted_message[MAX_SIZE];
    int shift;
    printf("Enter message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);
    printf("Enter shift value: ");
    scanf("%d", &shift);

    // Encrypt the message and print the encrypted message
    encrypt(message, shift);
    printf("Encrypted message: %s", message);

    // Decrypt the encrypted message and print the decrypted message
    strcpy(encrypted_message, message);
    decrypt(encrypted_message, shift);
    printf("Decrypted message: %s", encrypted_message);

    memset(message, 0, MAX_SIZE); // Clear the message string
    memset(encrypted_message, 0, MAX_SIZE); // Clear the encrypted message string
    memset(decrypted_message, 0, MAX_SIZE); // Clear the decrypted message string

    return 0;
}