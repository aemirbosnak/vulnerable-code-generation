//FormAI DATASET v1.0 Category: Encryption ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char[], int);
void decrypt(char[], int);

int main() {
    char message[100];
    int key;
    int choice;
    
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter a key between 1-26: ");
    scanf("%d", &key);

    do {
        printf("Enter your choice:\n1. Encrypt\n2. Decrypt\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                encrypt(message, key);
                printf("Encrypted message: %s\n", message);
                break;
            case 2:
                decrypt(message, key);
                printf("Decrypted message: %s\n", message);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}

void encrypt(char message[], int key) {
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; i++) {
        ch = message[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;

            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;

            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}

void decrypt(char message[], int key) {
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; i++) {
        ch = message[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = ch - key;

            if(ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key;

            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }
}