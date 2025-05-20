//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to encrypt message
void encrypt(char *message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] + key;
            if (message[i] > 'z') {
                message[i] = message[i] - 26;
            }
        }
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] + key;
            if (message[i] > 'Z') {
                message[i] = message[i] - 26;
            }
        }
        i++;
    }
}

//Function to decrypt message
void decrypt(char *message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - key;
            if (message[i] < 'a') {
                message[i] = message[i] + 26;
            }
        }
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] - key;
            if (message[i] < 'A') {
                message[i] = message[i] + 26;
            }
        }
        i++;
    }
}

//Function to generate key
int generate_key() {
    time_t t;
    time(&t);
    srand(t);
    return rand() % 26 + 1;
}

int main() {
    char message[100];
    int key;

    //Get message from user
    printf("Enter message to encrypt: ");
    scanf("%[^\n]", message);

    //Generate key
    key = generate_key();

    //Encrypt message
    encrypt(message, key);

    //Print encrypted message
    printf("Encrypted message: %s\n", message);

    //Get encrypted message from user
    printf("Enter encrypted message to decrypt: ");
    scanf("%[^\n]", message);

    //Decrypt message
    decrypt(message, key);

    //Print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}