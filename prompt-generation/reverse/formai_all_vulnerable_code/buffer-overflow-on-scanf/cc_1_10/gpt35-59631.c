//FormAI DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void encrypt(char *message, int key) {
    char result[MAX_LENGTH];
    int len = strlen(message);

    for(int i=0; i<len; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            result[i] = (message[i] - 'a' + key) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            result[i] = (message[i] - 'A' + key) % 26 + 'A';
        }
        else {
            result[i] = message[i];
        }
    }

    printf("Encrypted Message: %s\n", result);
}

void decrypt(char *message, int key) {
    char result[MAX_LENGTH];
    int len = strlen(message);

    for(int i=0; i<len; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            result[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            result[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
        }
        else {
            result[i] = message[i];
        }   
    }

    printf("Decrypted Message: %s\n", result);
}

int main() {
    char message[MAX_LENGTH];
    int key, choice;

    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_LENGTH, stdin);

    do {
        printf("\nEnter the key: ");
        scanf("%d", &key);

        printf("\nEnter 1 to encrypt the message\nEnter 2 to decrypt the message\nEnter 0 to exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                encrypt(message, key);
                break;
            case 2:
                decrypt(message, key);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid Choice! Try Again.\n");
        }
    } while(1);

    return 0;
}