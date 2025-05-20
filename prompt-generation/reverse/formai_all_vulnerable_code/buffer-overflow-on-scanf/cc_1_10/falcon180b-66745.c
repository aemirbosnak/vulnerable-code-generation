//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// define the key
#define KEY "MySecr3tK3y"
#define KEY_LENGTH 9

// define the encryption function
void encrypt(char *message, int length) {
    char key[KEY_LENGTH];
    strcpy(key, KEY);
    int i, j;
    for (i = 0; i < length; i++) {
        char c = toupper(message[i]);
        if (isalpha(c)) {
            int index = (int)c - 65;
            c = (char)(((index + 13 - key[i % KEY_LENGTH]) % 26) + 65);
        }
        message[i] = c;
    }
}

// define the decryption function
void decrypt(char *message, int length) {
    char key[KEY_LENGTH];
    strcpy(key, KEY);
    int i, j;
    for (i = 0; i < length; i++) {
        char c = toupper(message[i]);
        if (isalpha(c)) {
            int index = (int)c - 65;
            c = (char)(((index - key[i % KEY_LENGTH] - 13) % 26) + 65);
        }
        message[i] = c;
    }
}

// define the main function
int main() {
    char message[1000], encrypted[1000], decrypted[1000];
    int length;

    // get the message from the user
    printf("Enter your message: ");
    scanf("%s", message);
    length = strlen(message);

    // encrypt the message
    encrypt(message, length);
    strcpy(encrypted, message);

    // decrypt the message
    decrypt(encrypted, length);

    // print the results
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}