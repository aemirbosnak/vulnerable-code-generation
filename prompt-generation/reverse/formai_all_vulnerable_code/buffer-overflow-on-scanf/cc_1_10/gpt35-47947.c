//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int key = 0;

int generate_random_key(){
    srand(time(NULL));
    key = rand() % 100 + 1;
    return key;
}

void encrypt(char* message){
    int i = 0;
    while (message[i] != '\0'){
        message[i] = message[i] + key;
        i++;
    }
}

void decrypt(char* message){
    int i = 0;
    while (message[i] != '\0'){
        message[i] = message[i] - key;
        i++;
    }
}

int main(){
    char message[100];
    int option;
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Select an option: \n");
    printf("1. Encrypt\n2. Decrypt\n");
    scanf("%d", &option);
    switch(option){
        case 1:
            generate_random_key();
            encrypt(message);
            printf("Encrypted message: %s\n", message);
            printf("Encryption key: %d\n", key);
            break;
        case 2:
            printf("Enter the key to decrypt: ");
            scanf("%d", &key);
            decrypt(message);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
    return 0;
}