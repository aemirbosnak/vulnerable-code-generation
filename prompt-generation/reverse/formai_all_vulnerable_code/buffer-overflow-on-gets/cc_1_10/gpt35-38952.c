//FormAI DATASET v1.0 Category: Encryption ; Style: imaginative
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

#define KEY_LENGTH 10

void generateKey(char *key) {
    int i;

    for(i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }

    key[i] = '\0';
}

void encrypt(char *key, char *message, char *ciphertext) {
    int i, j;

    j = 0;

    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            ciphertext[j++] = key[message[i]-'A'];
        } else {
            ciphertext[j++] = message[i];
        }
    }

    ciphertext[j] = '\0';
}

void decrypt(char *key, char *ciphertext, char *message) {
    int i, j;

    j = 0;

    for(i = 0; ciphertext[i] != '\0'; i++) {
        if(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            message[j++] = 'A' + (strchr(key, ciphertext[i]) - key);
        } else {
            message[j++] = ciphertext[i];
        }
    }

    message[j] = '\0';
}

int main() {
    char key[KEY_LENGTH+1];
    char message[100];
    char ciphertext[100];

    srand(time(NULL));

    printf("Enter message: ");
    gets(message);

    generateKey(key);

    printf("Message: %s\n", message);
    printf("Encryption key: %s\n", key);

    encrypt(key, message, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(key, ciphertext, message);

    printf("Decrypted message: %s\n", message);

    return 0;
}