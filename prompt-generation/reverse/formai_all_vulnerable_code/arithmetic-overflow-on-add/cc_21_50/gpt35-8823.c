//FormAI DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include<stdio.h>

int main(){
    
    printf("Hello encryption enthusiasts!\n");
    printf("Today, we will be encoding our messages using a unique encryption algorithm.\n");
    printf("To begin, please enter the message you want to encrypt: \n");
    
    char message[100]; // array to store user input message
    fgets(message, 100, stdin); // accepting user input
    
    int i; // loop variable
    printf("Enter a key value (1-26) to encrypt the message: \n");
    int key;
    scanf("%d", &key); // accepting encryption key
    
    // encryption begins
    for(i=0; message[i] != '\0'; i++){
        if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] = message[i] + key; // shift the character to its corresponding key value
            if(message[i] > 'z'){
                message[i] = message[i] - 'z' + 'a' - 1; // wrap around
            }
        }
        else if(message[i] >= 'A' && message[i] <= 'Z'){
            message[i] = message[i] + key; // shift the character to its corresponding key value
            if(message[i] > 'Z'){
                message[i] = message[i] - 'Z' + 'A' - 1; // wrap around
            }
        }
    }
    
    // printing the encoded message
    printf("\nEncoded message: ");
    for(i=0; message[i] != '\0'; i++){
        printf("%c", message[i]);
    }
    
    // decryption begins
    printf("\n\nDo you want to decode the message? (y/n)\n");
    char option;
    scanf(" %c",&option);
    
    if(option == 'n' || option == 'N'){ // if user chooses not to decode the message
        printf("\nThank you for using our encryption service!\n");
    }
    else if(option == 'y' || option == 'Y'){ // if user chooses to decode the message
        for(i=0; message[i] != '\0'; i++){
            if(message[i] >= 'a' && message[i] <= 'z'){
                message[i] = message[i] - key; // shift the character back to its original value
                if(message[i] < 'a'){
                    message[i] = message[i] + 'z' - 'a' + 1; // wrap around
                }
            }
            else if(message[i] >= 'A' && message[i] <= 'Z'){
                message[i] = message[i] - key; // shift the character back to its original value
                if(message[i] < 'A'){
                    message[i] = message[i] + 'Z' - 'A' + 1; // wrap around
                }
            }
        }
        // printing the decoded message
        printf("\nDecoded message: ");
        for(i=0; message[i] != '\0'; i++){
            printf("%c", message[i]);
        }
        printf("\nThank you for using our encryption service!\n");
    }
    else{ // if user inputs an invalid option
        printf("\nInvalid option!\n");
    }
    return 0;
}