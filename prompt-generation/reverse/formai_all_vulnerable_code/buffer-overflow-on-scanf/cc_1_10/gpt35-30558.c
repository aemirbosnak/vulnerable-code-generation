//FormAI DATASET v1.0 Category: Encryption ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* encrypt(char* message, int key){
    int length = strlen(message);
    char* encrypted = (char*)malloc(sizeof(char)*(length+1));

    for(int i=0; i<length; i++){
        if(message[i] == ' '){
            encrypted[i] = ' ';
            continue;
        }
        encrypted[i] = ((message[i]-'a'+key)%26) + 'a';
    }
    encrypted[length] = '\0';
    return encrypted;
}

char* decrypt(char* message, int key){
    int length = strlen(message);
    char* decrypted = (char*)malloc(sizeof(char)*(length+1));

    for(int i=0; i<length; i++){
        if(message[i] == ' '){
            decrypted[i] = ' ';
            continue;
        }
        decrypted[i] = ((message[i]-'a'-key+26)%26) + 'a';
    }
    decrypted[length] = '\0';
    return decrypted;
}

int main(){
    int key;
    char message[1000];
    printf("Enter message to encrypt: ");
    fgets(message, 1000, stdin);
    message[strlen(message)-1] = '\0';
    printf("Enter key: ");
    scanf("%d", &key);

    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);
    return 0;
}