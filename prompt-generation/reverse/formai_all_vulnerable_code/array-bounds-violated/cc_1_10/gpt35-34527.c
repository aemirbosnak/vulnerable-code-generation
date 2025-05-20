//FormAI DATASET v1.0 Category: Modern Encryption ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void encoder(char *message, int length) {
    int key = 0;
    srand(time(NULL));
    key = rand() % 20 + 5;

    for(int i = 0; i < length; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        } else if(message[i] >= '0' && message[i] <= '9') {
            message[i] = ((message[i] - '0') + key) % 10 + '0';
        }
    }

    printf("Encoded message: %s\n", message);
}

void decoder(char *message, int length, int key) {
    for(int i = 0; i < length; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') - key + 26) % 26 + 'a';
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') - key + 26) % 26 + 'A';
        } else if(message[i] >= '0' && message[i] <= '9') {
            message[i] = ((message[i] - '0') - key + 10) % 10 + '0';
        }
    }

    printf("Decoded message: %s\n", message);
}

int main() {
    char message[100];
    int length, key;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    length = strlen(message);
    message[length - 1] = '\0';
    length--;

    printf("Original message: %s\n", message);
    
    encoder(message, length);

    key = rand() % 20 + 5; // The key is randomly generated again for extra security

    decoder(message, length, key);

    return 0;
}