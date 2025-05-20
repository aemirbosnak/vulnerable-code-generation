//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: retro
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 100

//Function to swap two numbers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to encrypt the message
void encrypt(char message[SIZE], int key) {
    int i = 0, j = 0;

    while(message[i]!= '\0') {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = message[i] + key;
                if(message[i] > 'Z') {
                    message[i] = message[i] - 26;
                }
            } else {
                message[i] = message[i] + key;
                if(message[i] > 'z') {
                    message[i] = message[i] - 26;
                }
            }
        }
        i++;
    }
}

//Function to decrypt the message
void decrypt(char message[SIZE], int key) {
    int i = 0, j = 0;

    while(message[i]!= '\0') {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = message[i] - key;
                if(message[i] < 'A') {
                    message[i] = message[i] + 26;
                }
            } else {
                message[i] = message[i] - key;
                if(message[i] < 'a') {
                    message[i] = message[i] + 26;
                }
            }
        }
        i++;
    }
}

//Main function
int main() {
    char message[SIZE];
    int key, choice;

    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]", message);

    printf("Enter the key: ");
    scanf("%d", &key);

    printf("Enter your choice:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s", message);
            break;
        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s", message);
            break;
        default:
            printf("Invalid choice");
            break;
    }

    return 0;
}