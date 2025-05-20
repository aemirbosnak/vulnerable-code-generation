//FormAI DATASET v1.0 Category: Encryption ; Style: Ada Lovelace
// Ada Lovelace inspired Unique C Encryption Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform encryption
void encrypt(char *string, int key){
    int i;
    for(i=0;i<strlen(string);i++){
        if(string[i]>='a'&&string[i]<='z'){
            string[i] = (string[i]-'a'+key)%26 + 'a';
        }
        else if(string[i]>='A'&&string[i]<='Z'){
            string[i] = (string[i]-'A'+key)%26 + 'A';
        }
    }
}

// Function to perform decryption
void decrypt(char *string, int key){
    int i;
    for(i=0;i<strlen(string);i++){
        if(string[i]>='a'&&string[i]<='z'){
            string[i] = (string[i]-'a'-key+26)%26 + 'a';
        }
        else if(string[i]>='A'&&string[i]<='Z'){
            string[i] = (string[i]-'A'-key+26)%26 + 'A';
        }
    }
}

// Main function to run the program
int main(){
    char string[100];
    int key;
    printf("Enter a string to encrypt: ");
    scanf("%s", string);
    printf("Enter a key to encrypt the string: ");
    scanf("%d", &key);

    // Encrypt the string
    encrypt(string, key);

    printf("Encrypted string: %s\n", string);

    // Decrypt the string
    decrypt(string, key);

    printf("Decrypted string: %s\n", string);

    return 0;
}