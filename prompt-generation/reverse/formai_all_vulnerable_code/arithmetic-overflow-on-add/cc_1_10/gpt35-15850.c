//FormAI DATASET v1.0 Category: Modern Encryption ; Style: portable
#include<stdio.h>
#include<string.h>

//Encryption Function
void encrypt(char message[], int key) {
    int i;
    char ch;
    
    for(i=0; message[i]!='\0'; i++) {
        ch = message[i]; //Retrieve individual characters in message
        
        //Encrypt each character using the key
        if(ch >= 'a' && ch <= 'z') {
            ch = (ch + key - 'a') % 26 + 'a';
            message[i] = ch; //Replace with encrypted character
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = (ch + key - 'A') % 26 + 'A';
            message[i] = ch; //Replace with encrypted character
        }
    }
}

//Decryption Function (using key as a parameter)
void decrypt(char message[], int key) {
    encrypt(message, 26 - key); //Decrypt is the inverse of Encrypt, where key is changed to 26-key
}

int main() {
    char message[100], choice;
    int key;
    
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin); //Read in message from user
    
    printf("Enter the key: ");
    scanf("%d", &key); //Read in key from user
    
    //Encrypt or Decrypt based on user's choice
    printf("Do you want to encrypt(e) or decrypt(d)? ");
    scanf(" %c", &choice); //Read in user's choice
    
    if(choice == 'e') {
        encrypt(message, key);
        printf("Encrypted message: %s", message);
    }
    else if(choice == 'd') {
        decrypt(message, key);
        printf("Decrypted message: %s", message);
    }
    else {
        printf("Invalid choice.\n");
    }
    
    return 0;
}