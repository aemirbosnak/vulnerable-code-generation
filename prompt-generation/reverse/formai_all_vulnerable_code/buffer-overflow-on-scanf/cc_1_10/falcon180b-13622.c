//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// define encryption key
#define KEY "AdaLovelace"

// encrypt function
void encrypt(char* message) {
    int i, j;
    for(i = 0; message[i]!= '\0'; i++) {
        // convert to uppercase
        message[i] = toupper(message[i]);
        // encrypt letter
        if(isalpha(message[i])) {
            message[i] = message[i] + 'A' - 'a';
            message[i] = message[i] % 26 + 'A';
        }
    }
}

// decrypt function
void decrypt(char* message) {
    int i, j;
    for(i = 0; message[i]!= '\0'; i++) {
        // convert to uppercase
        message[i] = toupper(message[i]);
        // decrypt letter
        if(isalpha(message[i])) {
            message[i] = message[i] - 'A' + 'a';
            message[i] = (message[i] - 'A' + 26) % 26 + 'A';
        }
    }
}

// main function
int main() {
    char message[100];

    // get message from user
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    // encrypt message
    encrypt(message);

    // print encrypted message
    printf("Encrypted message: %s\n", message);

    // decrypt message
    decrypt(message);

    // print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}