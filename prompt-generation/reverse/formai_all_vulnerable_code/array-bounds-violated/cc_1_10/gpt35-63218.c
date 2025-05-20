//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Donald Knuth
/* 
   This is a unique encryption program that demonstrates the Caesar cipher algorithm. 
   Implemented in C language, this program takes a plaintext message and a key as inputs 
   and outputs an encrypted string that can only be read by someone who has the key. 
   
   Developed by: [Your Name]
   Date: [Date Here]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000 //Maximum message length

//Function for encrypting given string using the Caesar cipher algorithm
void encrypt(char *m, int k) {
    int i;
    char c;

    for(i=0; m[i] != '\0'; ++i){
        c = m[i];
        //Encrypt uppercase characters
        if(c >= 'A' && c <= 'Z'){
            c = ((c - 'A') + k) % 26 + 'A';
        }
        //Encrypt lowercase characters
        else if(c >= 'a' && c <= 'z'){
            c = ((c - 'a') + k) % 26 + 'a';
        }
        //Leave any other characters unchanged
        m[i] = c;
    }
}

int main() {
    char message[MAX_LENGTH], result[MAX_LENGTH];
    int key;

    //Get user input for message
    printf("Enter the plaintext message: ");
    fgets(message, MAX_LENGTH, stdin);
    if(message[strlen(message)-1] == '\n'){
        message[strlen(message)-1] = '\0';
    }

    //Get user input for key
    printf("Enter the encryption key (1-25): ");
    scanf("%d", &key);

    //Encrypt the message and print the result
    strcpy(result, message);
    encrypt(result, key);
    printf("Encrypted message: %s\n", result);

    return 0;
}