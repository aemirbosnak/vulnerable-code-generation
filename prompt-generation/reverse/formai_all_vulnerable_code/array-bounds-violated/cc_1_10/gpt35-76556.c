//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LEN 100

int main(){
    char plaintext[MAX_LEN];
    char key[MAX_LEN];
    char ciphertext[MAX_LEN];
    int i, j, k, len, key_len;

    //User Input
    printf("Enter the plaintext you'd like to encrypt: ");
    fgets(plaintext, MAX_LEN, stdin);
    printf("Enter the key: ");
    fgets(key, MAX_LEN, stdin);

    //String Length Calculation
    len = strlen(plaintext);
    key_len = strlen(key);

    //Removing newline characters
    plaintext[len-1] = '\0';
    key[key_len-1] = '\0';
    len = strlen(plaintext);
    key_len = strlen(key);

    //Encryption with Vigenere Cipher
    for(i=0, j=0; i<len; i++, j++){
        if(j == key_len){
            j = 0;
        }
        k = tolower(key[j]) - 'a';
        if(islower(plaintext[i])){
            ciphertext[i] = ((plaintext[i] - 'a' + k) % 26) + 'a';
        }
        else if(isupper(plaintext[i])){
            ciphertext[i] = ((plaintext[i] - 'A' + k) % 26) + 'A';
        }
        else{
            ciphertext[i] = plaintext[i];
            j--;
        }
    }
    ciphertext[len] = '\0';

    //Output
    printf("\nPlaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}