//FormAI DATASET v1.0 Category: Encryption ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Function to perform encryption*/
void encrypt(char *message, int key){
    int i;
    for(i = 0; message[i] != '\0'; ++i){
        //Ignore special characters
        if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z'){
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        }
    }
}

/*Function to perform decryption*/
void decrypt(char *message, int key){
    int i;
    for(i = 0; message[i] != '\0'; ++i){
        //Ignore special characters
        if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] = ((message[i] - 'a') - key + 26) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z'){
            message[i] = ((message[i] - 'A') - key + 26) % 26 + 'A';
        }
    }
}

int main(){
    char message[100];
    int key;
    int choice;
    printf("Enter a message: ");
    fgets(message, 100, stdin);
    printf("Enter a key: ");
    scanf("%d", &key);
    printf("Choose an option:\n");
    printf("1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s", message);
            break;
        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s", message);
            break;
        default:
            printf("Invalid choice!");
            break;
    }
    return 0;
}