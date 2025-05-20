//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// This program implements a Cryptography algorithm that encrypts romantic messages

char* encrypt(char* message, int key) {
    int len = strlen(message);
    char* cipher = (char*) malloc(len + 1);
    for(int i=0; i<len; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            cipher[i] = ((message[i] - 'a') + key) % 26 + 'a';
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            cipher[i] = ((message[i] - 'A') + key) % 26 + 'A'; 
        } else {
            cipher[i] = message[i];
        }
    }
    return cipher;
}

char* decrypt(char* cipher, int key) {
    int len = strlen(cipher);
    char* message = (char*) malloc(len + 1);
    for(int i=0; i<len; i++) {
        if(cipher[i] >= 'a' && cipher[i] <= 'z') {
            message[i] = ((cipher[i] - 'a') - key + 26) % 26 + 'a';
        } else if(cipher[i] >= 'A' && cipher[i] <= 'Z') {
            message[i] = ((cipher[i] - 'A') - key + 26) % 26 + 'A'; 
        } else {
            message[i] = cipher[i];
        }
    }
    return message;
}

int main() {
    char message[100], choice;
    int key;

    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);
    printf("Enter the key: ");
    scanf("%d", &key);

    char* cipher = encrypt(message, key);
    printf("Encrypted Message: %s\n", cipher);

    printf("Decrypt this message? (y/n): ");
    scanf(" %c", &choice);
    if(choice == 'y' || choice == 'Y') {
        char* decrypted_message = decrypt(cipher, key);
        printf("Decrypted Message: %s\n", decrypted_message);
    }
    return 0;
}