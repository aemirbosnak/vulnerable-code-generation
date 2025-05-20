//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: brave
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//Function to perform encryption
void encrypt(char message[], int key){
    int i;
    for(i=0;i<strlen(message);i++){
        message[i] = ((message[i]-97) + key) % 26 + 97; //Shifts the characters by key positions
    }
}

//Function to perform decryption
void decrypt(char message[], int key){
    int i;
    for(i=0;i<strlen(message);i++){
        message[i] = ((message[i]-97) - key + 26) % 26 + 97; //Restores the original characters by shifting back by key positions
    }
}

int main(){
    char message[1000];
    int key, choice;
    srand(time(0)); //Using current time as seed for RNG
    
    printf("Enter the message you want to encrypt: ");
    fgets(message, 1000, stdin); //Reading message from standard input
    
    key = rand() % 26; //Generating a random key between 0 to 25
    
    printf("\nGenerated key: %d", key);
    
    printf("\nChoose an option:\n1. Encrypt message\n2. Decrypt message\nEnter choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1: //Encryption option
            encrypt(message, key);
            printf("\nEncrypted message: %s", message);
            break;
        
        case 2: //Decryption option
            decrypt(message, key);
            printf("\nDecrypted message: %s", message);
            break;
         
        default:
            printf("\nInvalid choice!");
    }
    
    return 0;
}