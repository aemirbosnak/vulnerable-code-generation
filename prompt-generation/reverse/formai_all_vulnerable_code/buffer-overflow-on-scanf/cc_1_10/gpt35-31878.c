//FormAI DATASET v1.0 Category: modern Encryption ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generateKey(char *key, char *message){
    int messageLen = strlen(message), i, j;
    char k[messageLen];
    
    for(i=0, j=0; i<messageLen; ++i, ++j){
        if(j == strlen(key))
            j=0;
        k[i] = key[j];
    }
    k[i] = '\0';
    strcpy(key, k);
}

void encrypt(char *message, char *key){
    int messageLen = strlen(message), i;
    char m[messageLen];
    
    for(i=0; i<messageLen; ++i)
        m[i] = ((message[i] + key[i]) % 26) + 'A';
    
    m[i] = '\0';
    strcpy(message, m);
}

void decrypt(char *message, char *key){
    int messageLen = strlen(message), i;
    char m[messageLen];
    
    for(i=0; i<messageLen; ++i)
        m[i] = (((message[i] - key[i]) + 26) % 26) + 'A';
    
    m[i] = '\0';
    strcpy(message, m);
}

int main(){
    char message[100], key[100] = "SURPRISED", choice;
    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]", message);
    getchar();
    
    generateKey(key, message);
    
    printf("\nDo you want to encrypt or decrypt the message? (E/D): ");
    scanf("%c", &choice);
    getchar();
    
    if(choice == 'E' || choice == 'e'){
        encrypt(message, key);
        printf("\nThe encrypted message is: %s\n", message);
    }
    else if(choice == 'D' || choice == 'd'){
        decrypt(message, key);
        printf("\nThe decrypted message is: %s\n", message);
    }
    else
        printf("\nInvalid option selected.\n");
    
    return 0;
}