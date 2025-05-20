//FormAI DATASET v1.0 Category: Encryption ; Style: sophisticated
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Function to encrypt the message
void encrypt(char* message, int key) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + key) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + key) % 26 + 'A';
        }
    }
}

//Function to decrypt the message
void decrypt(char* message, int key) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
        }
    }
}

int main() {
    char message[100];
    int key, choice;
    printf("Enter the message: ");
    fgets(message, 100, stdin);
    printf("Enter the key (1-25): ");
    scanf("%d", &key);
    do {
        printf("\n1. Encrypt\n2. Decrypt\n3. Exit\nEnter your choice: ");
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
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 3);
    return 0;
}