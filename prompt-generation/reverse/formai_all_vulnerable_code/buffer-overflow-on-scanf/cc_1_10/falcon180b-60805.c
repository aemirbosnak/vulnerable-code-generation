//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define SIZE 8
#define ALPHABET_SIZE 26

void generate_key(char key[SIZE]) {
    int i;
    for(i=0; i<SIZE; i++) {
        key[i] = 'A' + rand()%26;
    }
}

void encrypt(char message[100], char key[SIZE]) {
    int i, j;
    for(i=0, j=0; message[i]!='\0'; i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + (message[i] - 'A' + key[j] - 'A')%26;
            j = (j+1)%SIZE;
        }
        else if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = 'a' + (message[i] - 'a' + key[j] - 'A')%26;
            j = (j+1)%SIZE;
        }
        else {
            message[i] = message[i];
        }
    }
}

void decrypt(char message[100], char key[SIZE]) {
    int i, j;
    for(i=0, j=0; message[i]!='\0'; i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + (message[i] - 'A' - key[j] + 26)%26;
            j = (j+1)%SIZE;
        }
        else if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = 'a' + (message[i] - 'a' - key[j] + 26)%26;
            j = (j+1)%SIZE;
        }
        else {
            message[i] = message[i];
        }
    }
}

int main() {
    char message[100], key[SIZE];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    generate_key(key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}