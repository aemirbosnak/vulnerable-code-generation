//FormAI DATASET v1.0 Category: Encryption ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char plainTxt[], int key){
    int len = strlen(plainTxt);
    char cipherTxt[len];
    for(int i=0; i<len; i++){
        if(isalpha(plainTxt[i])){
            cipherTxt[i] = (((tolower(plainTxt[i]) - 97) + key) % 26) + 97;
        }
        else{
            cipherTxt[i] = plainTxt[i];
        }
    }
    printf("Encrypted Text: %s\n", cipherTxt);
}

void decrypt(char cipherTxt[], int key){
    int len = strlen(cipherTxt);
    char plainTxt[len];
    for(int i=0; i<len; i++){
        if(isalpha(cipherTxt[i])){
            plainTxt[i] = (((tolower(cipherTxt[i]) - 97) - key + 26) % 26) + 97;
        }
        else{
            plainTxt[i] = cipherTxt[i];
        }
    }
    printf("Decrypted Text: %s\n", plainTxt);
}

int main(){
    char plainTxt[100], cipherTxt[100];
    int key;
    printf("Enter the plain text: ");
    scanf("%[^\n]%*c", plainTxt);
    printf("Enter the rotation key (0-25): ");
    scanf("%d", &key);
    
    encrypt(plainTxt, key);

    printf("Enter the cipher text: ");
    scanf("%[^\n]%*c", cipherTxt);
    printf("Enter the rotation key (0-25): ");
    scanf("%d", &key);

    decrypt(cipherTxt, key);

    return 0;
}