//FormAI DATASET v1.0 Category: modern Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to encrypt the message
void encrypt(char *message, int key){
    int i;
    for(i=0; message[i] != '\0'; i++){
        message[i] = message[i] + key;
    }
}

//Function to decrypt the message
void decrypt(char *message, int key){
    int i;
    for(i=0; message[i] != '\0'; i++){
        message[i] = message[i] - key;
    }
}

//Main function
int main(){
    char message[100], choice;
    int key;
    
    //Prompting user for message and encryption key
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter key for encryption: ");
    scanf("%d", &key);
    
    //Removing trailing newline character from the message input
    message[strcspn(message, "\n")] = 0;
    
    //Prompting user for choice of operation
    printf("Do you want to encrypt(e) or decrypt(d) the message: ");
    scanf(" %c", &choice);
    
    //Performing encryption or decryption based on user's choice
    switch(choice){
        case 'e':
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 'd':
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice.\n");
            exit(0);
    }
    
    return 0;
}