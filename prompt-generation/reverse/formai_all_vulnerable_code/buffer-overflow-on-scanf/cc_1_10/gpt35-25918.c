//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//The Brave Encryption Algorithm
void braveEncrypt(char* message, char* key) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);

    int i, j;
    for (i = 0, j = 0; i < messageLength; ++i, ++j) {
        if (j == keyLength) {
            j = 0; //start from the beginning of the key if end is reached
        }

        message[i] += (key[j] - 'A'); //add the value of each key character to the corresponding message character
    }
}

//The Brave Decryption Algorithm
void braveDecrypt(char* message, char* key) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);

    int i, j;
    for (i = 0, j = 0; i < messageLength; ++i, ++j) {
        if (j == keyLength) {
            j = 0; //start from the beginning of the key if end is reached
        }

        message[i] -= (key[j] - 'A'); //subtract the value of each key character from the corresponding message character
    }
}

int main() {
    char message[100];
    char key[100];

    printf("Enter the message: ");
    scanf("%[^\n]s", message);

    printf("Enter the key: ");
    scanf("%s", key);

    //Encrypting the message
    braveEncrypt(message, key);
    printf("\nEncrypted Message: %s", message);

    //Decrypting the message
    braveDecrypt(message, key);
    printf("\nDecrypted Message: %s\n", message);

    return 0;
}