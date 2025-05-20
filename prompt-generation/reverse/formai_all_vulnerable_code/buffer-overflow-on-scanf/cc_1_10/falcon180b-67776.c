//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LEN 16
#define KEY "mysecretkey"

void encrypt(char* message, char* key, int key_len){
    int i, j, k;
    for(i = 0, j = 0; i < strlen(message); i++){
        message[i] = toupper(message[i]);
        k = (int)message[i];
        if(k >= 65 && k <= 90){
            k = (k - 65 + key_len) % 26 + 65;
        }
        else if(k >= 97 && k <= 122){
            k = (k - 97 + key_len) % 26 + 97;
        }
        message[i] = (char)k;
    }
}

void decrypt(char* message, char* key, int key_len){
    int i, j, k;
    for(i = 0, j = 0; i < strlen(message); i++){
        k = (int)message[i];
        if(k >= 65 && k <= 90){
            k = (k - 65 - key_len + 26) % 26 + 65;
        }
        else if(k >= 97 && k <= 122){
            k = (k - 97 - key_len + 26) % 26 + 97;
        }
        message[i] = (char)k;
    }
}

int main(){
    char message[LEN];
    char key[LEN];
    int key_len;
    srand(time(NULL));
    for(int i = 0; i < LEN; i++){
        key[i] = (char)rand() % 26 + 65; // generate random key
    }
    printf("Key: %s\n", key);
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    encrypt(message, key, strlen(key));
    printf("Encrypted message: %s\n", message);
    decrypt(message, key, strlen(key));
    printf("Decrypted message: %s\n", message);
    return 0;
}