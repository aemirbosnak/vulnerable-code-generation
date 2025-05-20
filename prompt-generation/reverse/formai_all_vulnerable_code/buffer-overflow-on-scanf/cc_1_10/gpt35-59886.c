//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 100

void generateRandomKey(int *key, int len){
    int i;
    srand(time(NULL));
    for(i=0; i<len; i++){
        key[i] = rand()%26;
    }
}

void encrypt(char *msg, int *key, int len){
    int i, j;
    for(i=0, j=0; i<strlen(msg); i++, j++){
        if(j==len) j=0;
        if(msg[i]>='a' && msg[i]<='z'){
            msg[i] = ((msg[i]-'a')+key[j])%26 + 'a';
        }
        else if(msg[i]>='A' && msg[i]<='Z'){
            msg[i] = ((msg[i]-'A')+key[j])%26 + 'A';
        }
    }
}

void decrypt(char *msg, int *key, int len){
    int i, j;
    for(i=0, j=0; i<strlen(msg); i++, j++){
        if(j==len) j=0;
        if(msg[i]>='a' && msg[i]<='z'){
            msg[i] = ((msg[i]-'a')-key[j]+26)%26 + 'a';
        }
        else if(msg[i]>='A' && msg[i]<='Z'){
            msg[i] = ((msg[i]-'A')-key[j]+26)%26 + 'A';
        }
    }
}

int main(){
    char msg[MAX_SIZE];
    int key[MAX_SIZE], len;
    
    printf("Enter message to encrypt: ");
    fgets(msg, MAX_SIZE, stdin);
    msg[strcspn(msg, "\n")] = 0; // remove newline character
    
    printf("Enter length of key (max %d): ", strlen(msg));
    scanf("%d", &len);
    
    generateRandomKey(key, len);
    printf("Random key generated: ");
    for(int i=0; i<len; i++){
        printf("%d ", key[i]);
    }
    printf("\n");
    
    encrypt(msg, key, len);
    printf("Encrypted message: %s\n", msg);
    
    decrypt(msg, key, len);
    printf("Decrypted message: %s\n", msg);
    
    return 0;
}