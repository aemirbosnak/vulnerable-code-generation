//Falcon-180B DATASET v1.0 Category: Encryption ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY "mysecretkey"

// Function to encrypt a string
void encrypt(char* str) {
    int len = strlen(str);
    char* key = KEY;
    int key_len = strlen(key);

    char result[len];
    int j = 0;

    for(int i = 0; i < len; i++) {
        result[i] = str[i] ^ key[j];
        j++;
        if(j == key_len) {
            j = 0;
        }
    }

    strcpy(str, result);
}

// Function to decrypt a string
void decrypt(char* str) {
    int len = strlen(str);
    char* key = KEY;
    int key_len = strlen(key);

    char result[len];
    int j = 0;

    for(int i = 0; i < len; i++) {
        result[i] = str[i] ^ key[j];
        j++;
        if(j == key_len) {
            j = 0;
        }
    }

    strcpy(str, result);
}

int main() {
    char message[100];
    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);

    int choice;
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    if(choice == 1) {
        encrypt(message);
        printf("Encrypted message: %s\n", message);
    } else if(choice == 2) {
        decrypt(message);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}