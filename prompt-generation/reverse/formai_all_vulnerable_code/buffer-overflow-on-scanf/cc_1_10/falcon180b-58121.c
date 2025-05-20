//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEY "mysecretkey"
#define SIZE 26

void encrypt(char* message) {
    int i, j;
    char key[26];
    for(i = 0; i < strlen(KEY); i++) {
        key[i] = tolower(KEY[i]);
    }
    for(i = 0; i < strlen(message); i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = tolower(message[i]);
            }
            j = 0;
            while(key[j]!= message[i]) {
                j++;
            }
            message[i] = key[j];
        }
    }
}

void decrypt(char* message) {
    int i, j;
    char key[26];
    for(i = 0; i < strlen(KEY); i++) {
        key[i] = tolower(KEY[i]);
    }
    for(i = 0; i < strlen(message); i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = tolower(message[i]);
            }
            j = 0;
            while(key[j]!= message[i]) {
                j++;
            }
            message[i] = key[(j - 1) % SIZE];
        }
    }
}

int main() {
    char message[100];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    encrypt(message);
    printf("Encrypted message: %s\n", message);
    decrypt(message);
    printf("Decrypted message: %s\n", message);
    return 0;
}