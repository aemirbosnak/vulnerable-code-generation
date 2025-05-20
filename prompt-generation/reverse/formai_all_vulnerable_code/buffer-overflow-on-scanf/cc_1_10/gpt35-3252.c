//FormAI DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, char key);
void decrypt(char *message, char key);

int main(){
    char message[100], key;
    int choice;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the key: ");
    scanf("%c", &key);
    while(getchar() != '\n');

    printf("Select an option: \n");
    printf("1. Encrypt message\n");
    printf("2. Decrypt message\n");
    printf("Choice: ");
    scanf("%d", &choice);
    while(getchar() != '\n');

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
            printf("Invalid option selected.\n");
            return 1;
    }
    return 0;
}

void encrypt(char *message, char key){
    int i;
    for(i=0; i<strlen(message); i++){
        message[i] = message[i] ^ key; //XOR operation with key
    }
}

void decrypt(char *message, char key){
    int i;
    for(i=0; i<strlen(message); i++){
        message[i] = message[i] ^ key; //XOR operation with key
    }
}