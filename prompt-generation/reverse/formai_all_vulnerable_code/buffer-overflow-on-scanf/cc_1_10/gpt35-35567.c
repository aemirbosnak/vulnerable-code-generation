//FormAI DATASET v1.0 Category: Modern Encryption ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to encrypt the string using Caesar Cipher.
void caesar(char *str, int shift){
    char ch;
    int len = strlen(str);
    
    for(int i=0; i<len; i++){
        ch = str[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + shift;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            str[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + shift;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            str[i] = ch;
        }
        else{
            continue;
        }
    }
}

//Function to encrypt the string using Rail Fence Cipher.
void rail_fence(char *str, int key){
    int len = strlen(str), i=0, j=0, k=0;
    char rail[len][key];
    for(i=0; i<len; i++){
        for(j=0; j<key; j++){
            rail[i][j] = '\n';
        }
    }
    i = 0;
    j = 0;
    for(k=0; k<len; k++){
        if(j == 0){
            rail[i][j] = str[k];
            j++;
        }
        else if(j == key){
            i++;
            j = 0;
            rail[i][j] = str[k];
            j++;
        }
        else{
            i++;
            rail[i][j] = str[k];
            j++;
        }
    }
    int dir_down = 0, flag = 0;
    i = 0;
    j = 0;
    for(int m=0; m<len; m++){
        if(i == 0){
            dir_down = 1;
        }
        else if(i == key-1){
            dir_down = 0;
        }
        if(rail[i][j] != '\n'){
            printf("%c", rail[i][j]);
        }
        if(dir_down){
            i++;
        }
        else{
            i--;
        }
        j++;
    }
}

int main(){
    char str[200];
    int choice, shift, key;
    printf("Enter the string to be encrypted: ");
    fgets(str, sizeof(str), stdin);
    printf("Choose the encryption technique:\n");
    printf("1. Caesar Cipher\n");
    printf("2. Rail Fence Cipher\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter the shift amount: ");
            scanf("%d", &shift);
            caesar(str, shift);
            printf("Encrypted string: %s", str);
            break;
        case 2:
            printf("Enter the key: ");
            scanf("%d", &key);
            rail_fence(str, key);
            break;
        default:
            printf("Invalid Choice!");
            break;
    }
    return 0;
}