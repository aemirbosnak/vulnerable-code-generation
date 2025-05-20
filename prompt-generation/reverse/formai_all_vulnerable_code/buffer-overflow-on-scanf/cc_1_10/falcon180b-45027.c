//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: accurate
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 10000

void generateKey(char* key){
    int i,j;
    for(i=0;i<strlen(key);i++){
        if(key[i] >= 'A' && key[i] <= 'Z'){
            key[i] += 13;
        }else if(key[i] >= 'a' && key[i] <= 'z'){
            key[i] += 13;
        }else{
            key[i] = key[i];
        }
    }
}

void encrypt(char* message, char* key){
    int i,j;
    for(i=0;i<strlen(message);i++){
        if(message[i] >= 'A' && message[i] <= 'Z'){
            message[i] += 13;
        }else if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] += 13;
        }else{
            message[i] = message[i];
        }
    }
}

void decrypt(char* message, char* key){
    int i,j;
    for(i=0;i<strlen(message);i++){
        if(message[i] >= 'A' && message[i] <= 'Z'){
            message[i] -= 13;
        }else if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] -= 13;
        }else{
            message[i] = message[i];
        }
    }
}

int main(){
    char message[MAX_SIZE], key[MAX_SIZE];
    printf("Enter the message: ");
    scanf("%s", message);
    printf("Enter the key: ");
    scanf("%s", key);
    generateKey(key);
    printf("Encrypted message: %s\n", message);
    encrypt(message, key);
    printf("Decrypted message: %s\n", message);
    decrypt(message, key);
    return 0;
}