//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

void encryption(char* message, int key) {
    int i, j;
    char temp;
    for(i = 0; i < strlen(message); i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char)((int)message[i] + key - 97);
            if(message[i] > 'z') {
                message[i] = (char)((int)message[i] - 26);
            }
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char)((int)message[i] + key - 65);
            if(message[i] > 'Z') {
                message[i] = (char)((int)message[i] - 26);
            }
        }
        else {
            message[i] = message[i];
        }
    }
}

void decryption(char* message, int key) {
    int i, j;
    char temp;
    for(i = 0; i < strlen(message); i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char)((int)message[i] - key - 97);
            if(message[i] < 'a') {
                message[i] = (char)((int)message[i] + 26);
            }
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char)((int)message[i] - key - 65);
            if(message[i] < 'A') {
                message[i] = (char)((int)message[i] + 26);
            }
        }
        else {
            message[i] = message[i];
        }
    }
}

int main() {
    char message[SIZE];
    int key;
    printf("Enter message: ");
    scanf("%s", message);
    printf("Enter key: ");
    scanf("%d", &key);
    encryption(message, key);
    printf("Encrypted message: %s\n", message);
    decryption(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}