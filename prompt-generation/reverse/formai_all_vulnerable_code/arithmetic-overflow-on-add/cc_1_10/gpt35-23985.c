//FormAI DATASET v1.0 Category: modern Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encrypt the message
void encrypt(char *msg, int key) {
    int i;
    char ch;
    
    for(i = 0; msg[i] != '\0'; ++i) {
        ch = msg[i];

        // Encrypting lowercase characters
        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            msg[i] = ch;
        }

        // Encrypting uppercase characters
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
        }
    }
}

int main() {
    char message[100];
    int key;

    printf("Welcome to the cheerful Encryption program!\n");
    printf("Enter a message to encrypt (maximum 100 characters): ");
    
    // Taking user's message as input
    fgets(message, sizeof(message), stdin);

    printf("Enter the key to encrypt the message: ");
    
    // Taking user's key as input
    scanf("%d", &key);

    // Calling encrypt function to perform the encryption
    encrypt(message, key);

    printf("\nEncrypted message: %s\n", message);

    return 0;
}