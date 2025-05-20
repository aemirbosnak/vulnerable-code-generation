//FormAI DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// define global variables
char key[1000];
int keyLength;
int keySum;

// function to get the key and calculate its length and sum
void getKey() {
    printf("Enter the key: ");
    scanf("%s", key);
    keyLength = strlen(key);
    for (int i = 0; i < keyLength; i++) {
        keySum += (int) key[i];
    }
}

// function to implement the Shannon cipher
void shannonCipher(char * message) {
    int messageLen = strlen(message);
    char cipherText[1000];
    int counter = 0;
    for (int i = 0; i < messageLen; i++) {
        int shift = (int) pow(-1, i+1) * (keySum % (i+1));
        cipherText[i] = (char) ((int) message[i] + shift);
        counter += 1;
        if (counter == keyLength) {
            counter = 0;
            keySum += (int) cipherText[i];
        }
    }
    cipherText[messageLen] = '\0'; // add null terminator
    printf("Encrypted message: %s\n", cipherText);
}

// function to implement the Shannon Decipher
void shannonDecipher(char * cipherText) {
    int cipherLen = strlen(cipherText);
    char message[1000];
    int counter = 0;
    for (int i = 0; i < cipherLen; i++) {
        int shift = (int) pow(-1, i+1) * (keySum % (i+1));
        message[i] = (char) ((int) cipherText[i] - shift);
        counter += 1;
        if (counter == keyLength) {
            counter = 0;
            keySum += (int) cipherText[i];
        }
    }
    message[cipherLen] = '\0'; // add null terminator
    printf("Decrypted message: %s\n", message);
}

// main function
int main() {
    char message[1000];
    // get the key
    getKey();
    // get the message
    printf("Enter the message: ");
    scanf("%s", message);
    // encrypt the message using Shannon cipher
    shannonCipher(message);
    // decrypt the message using Shannon cipher
    shannonDecipher("u\\nx!J7J.fj6qwsg1-s} ");
    return 0;
}