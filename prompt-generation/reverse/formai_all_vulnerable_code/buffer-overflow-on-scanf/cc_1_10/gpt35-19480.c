//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: grateful
/*
Welcome to my Cryptography Implementation program in C!
 
In this program, I will be demonstrating the Caesar Cipher algorithm,
which is one of the simplest and most widely used encryption techniques.
The Caesar Cipher works by shifting the letters in a message by a certain
number of places down the alphabet.
 
I have written this program in a modular style, with each function handling 
a specific task in the encryption process.
 
I hope you enjoy using this program and learning about the Caesar Cipher!
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
 
char *encrypt(char *message, int shift) {
    int length = strlen(message);
    char *encrypted_message = malloc(length + 1);
    int i;
    for(i = 0; i < length; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i]))
                *(encrypted_message + i) = ((message[i] + shift - 'A') % 26) + 'A';
            else
                *(encrypted_message + i) = ((message[i] + shift - 'a') % 26) + 
                'a';
        } else {
            *(encrypted_message + i) = message[i];
        }
    }
    *(encrypted_message + i) = '\0';
    return encrypted_message;
}
 
char *decrypt(char *message, int shift) {
    return encrypt(message, 26 - shift); // since shifting by 26 - x will undo a shift of x
}
 
int main() {
    char message[1000];
    char *encrypted_message;
    char *decrypted_message;
    int shift;
 
    // get user input
    printf("Welcome to the Caesar Cipher Encryption Program!\n\n");
    printf("Please enter the message you would like to encrypt: ");
    fgets(message, 1000, stdin);
    printf("Please enter the number of places to shift the message (0-25): ");
    scanf("%d", &shift);
 
    // encrypt and print out results
    encrypted_message = encrypt(message, shift);
    printf("\n The Encrypted Message is : "); 
    printf("%s\n", encrypted_message);
 
    // decrypt and print out results
    decrypted_message = decrypt(encrypted_message, shift);
    printf("\n The Decrypted Message is : "); 
    printf("%s\n", decrypted_message);
 
    // free memory and exit
    free(encrypted_message);
    free(decrypted_message);
    return 0;
}