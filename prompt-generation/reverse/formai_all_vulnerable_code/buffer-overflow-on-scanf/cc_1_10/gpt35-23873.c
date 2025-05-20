//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

void encrypt(char message[], char key[]);
void decrypt(char message[], char key[]);

int main(){
    char message[MAX_SIZE];
    char key[MAX_SIZE];
    int choice;

    printf("Welcome to the Thompson Encryption Program\n");

    printf("Would you like to Encrypt or Decrypt a message?\n");
    printf("Enter 1 for Encryption or 2 for Decryption: ");
    scanf("%d", &choice);

    printf("Enter message: ");
    scanf(" %[^\n]s", message);

    printf("Enter key: ");
    scanf("%s", key);

    if(choice == 1){
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    }
    else if(choice == 2){
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }
    else{
        printf("Invalid choice!\n");
    }

    return 0;
}

void encrypt(char message[], char key[]){
    int message_length = strlen(message);
    int key_length = strlen(key);

    for(int i = 0; i < message_length; i++){
        message[i] = message[i] ^ key[i%key_length];
    }
}

void decrypt(char message[], char key[]){
    int message_length = strlen(message);
    int key_length = strlen(key);

    for(int i = 0; i < message_length; i++){
        message[i] = message[i] ^ key[i%key_length];
    }
}