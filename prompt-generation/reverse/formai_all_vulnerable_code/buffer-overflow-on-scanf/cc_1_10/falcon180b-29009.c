//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define SIZE 16
#define KEY "cipher"

void encrypt(char* message, char* key, char* encrypted);
void decrypt(char* encrypted, char* key, char* decrypted);

int main(){
    char message[100];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    char encrypted[100];
    encrypt(message, KEY, encrypted);
    printf("Encrypted message: %s\n", encrypted);
    char decrypted[100];
    decrypt(encrypted, KEY, decrypted);
    printf("Decrypted message: %s\n", decrypted);
    return 0;
}

void encrypt(char* message, char* key, char* encrypted){
    int i, j, k;
    for(i=0, j=0; message[i]; i++){
        encrypted[j] = message[i];
        j++;
        if(j%2 == 0){
            encrypted[j] = encrypted[j] ^ key[k];
            k++;
            if(k == strlen(key)) k = 0;
        }
    }
    encrypted[j] = '\0';
}

void decrypt(char* encrypted, char* key, char* decrypted){
    int i, j, k;
    for(i=0, j=0; encrypted[i]; i++){
        decrypted[j] = encrypted[i];
        j++;
        if(j%2 == 0){
            decrypted[j] = decrypted[j] ^ key[k];
            k++;
            if(k == strlen(key)) k = 0;
        }
    }
    decrypted[j] = '\0';
}