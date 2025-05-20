//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1024
#define KEY_SIZE 8

void encrypt(char* message, char* key) {
    int i, j, k;
    char temp;
    for(i=0; i<strlen(message); i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = message[i] + key[j] - 65;
            }
            else {
                message[i] = message[i] + key[j] - 97;
            }
            j = (j+1) % KEY_SIZE;
        }
    }
}

void decrypt(char* message, char* key) {
    int i, j, k;
    char temp;
    for(i=0; i<strlen(message); i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = message[i] - key[j] - 65;
            }
            else {
                message[i] = message[i] - key[j] - 97;
            }
            j = (j+1) % KEY_SIZE;
        }
    }
}

int main() {
    FILE* file;
    char message[SIZE], key[KEY_SIZE];
    int i, j;

    printf("Enter the message to encrypt: ");
    fgets(message, SIZE, stdin);

    printf("Enter the key: ");
    scanf("%s", key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}