//FormAI DATASET v1.0 Category: Modern Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void encrypt(char *msg, int key){
    int len = strlen(msg);
    char *encrypted = (char*)malloc(sizeof(char)*len);
    int i;

    for(i = 0; i < len; i++){
        if(msg[i] >= 'a' && msg[i] <= 'z'){
            encrypted[i] = (((msg[i] - 'a') + key) % 26) + 'a';
        }
        else if(msg[i] >= 'A' && msg[i] <= 'Z'){
            encrypted[i] = (((msg[i] - 'A') + key) % 26) + 'A';
        }
        else{
            encrypted[i] = msg[i];
        }
    }
    printf("The encrypted text is: %s\n", encrypted);
}

void decrypt(char *msg, int key){
    int len = strlen(msg);
    char *decrypted = (char*)malloc(sizeof(char)*len);
    int i;

    for(i = 0; i < len; i++){
        if(msg[i] >= 'a' && msg[i] <= 'z'){
            decrypted[i] = (((msg[i] - 'a') - key + 26) % 26) + 'a';
        }
        else if(msg[i] >= 'A' && msg[i] <= 'Z'){
            decrypted[i] = (((msg[i] - 'A') - key + 26) % 26) + 'A';
        }
        else{
            decrypted[i] = msg[i];
        }
    }
    printf("The decrypted text is: %s\n", decrypted);
}

int main(){
    char msg[MAX];
    int key;

    printf("Enter the message to encrypt: ");
    fgets(msg, MAX, stdin);
    msg[strcspn(msg, "\n")] = 0;

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(msg, key);
    decrypt(msg, key);

    return 0;
}