//FormAI DATASET v1.0 Category: Modern Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The key used for encryption and decryption
char *key="secretkey";

// Function to encrypt the plain text
void encrypt(char *plaintext, char *ciphertext){
    int i,j;
    int lenkey=strlen(key);
    int lenpt=strlen(plaintext);

    for(i=0,j=0;i<lenpt;i++,j++){
        // Wrap around the key if it is shorter than the plaintext
        if(j==lenkey) j=0;
        ciphertext[i]=((plaintext[i]+key[j])%256);
    }
    ciphertext[i]='\0';
}

// Function to decrypt the cipher text
void decrypt(char *ciphertext, char *plaintext){
    int i,j;
    int lenkey=strlen(key);
    int lenct=strlen(ciphertext);

    for(i=0,j=0;i<lenct;i++,j++){
        // Wrap around the key if it is shorter than the ciphertext
        if(j==lenkey) j=0;
        plaintext[i]=((ciphertext[i]-key[j]+256)%256);
    }
    plaintext[i]='\0';
}

int main(){
    char plaintext[30];
    char ciphertext[30];
    char decryptedtext[30];

    printf("Please enter some plaintext: ");
    scanf("%s", plaintext);

    encrypt(plaintext, ciphertext);
    printf("Encrypted Text: %s\n", ciphertext);

    decrypt(ciphertext, decryptedtext);
    printf("Decrypted Text: %s\n", decryptedtext);

    return 0;
}