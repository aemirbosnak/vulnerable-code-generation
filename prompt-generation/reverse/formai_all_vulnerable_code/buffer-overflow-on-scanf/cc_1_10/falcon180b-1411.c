//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 100

// encryption function
void encrypt(char* message) {
    int length = strlen(message);
    int i, j, key = 5;
    char temp[MAX_LENGTH];

    // copy message to temporary string
    strcpy(temp, message);

    // encrypt message
    for (i = 0; i < length; i++) {
        if (isalpha(temp[i])) {
            if (isupper(temp[i])) {
                temp[i] = toupper(temp[i] + key);
            } else {
                temp[i] = tolower(temp[i] + key);
            }
        }
    }

    // print encrypted message
    printf("Encrypted message: %s\n", temp);
}

// decryption function
void decrypt(char* message) {
    int length = strlen(message);
    int i, j, key = 5;
    char temp[MAX_LENGTH];

    // copy message to temporary string
    strcpy(temp, message);

    // decrypt message
    for (i = 0; i < length; i++) {
        if (isalpha(temp[i])) {
            if (isupper(temp[i])) {
                temp[i] = toupper(temp[i] - key);
            } else {
                temp[i] = tolower(temp[i] - key);
            }
        }
    }

    // print decrypted message
    printf("Decrypted message: %s\n", temp);
}

int main() {
    char message[MAX_LENGTH];

    // get message from user
    printf("Enter a message: ");
    scanf("%s", message);

    // encrypt message
    encrypt(message);

    // decrypt message
    decrypt(message);

    return 0;
}