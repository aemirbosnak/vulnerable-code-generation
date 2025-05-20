//FormAI DATASET v1.0 Category: Modern Encryption ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the message
char* encrypt(char* message, int key) {
    int length = strlen(message);
    char *encrypted_msg = (char*)malloc(length+1);
        // Iterate through each character of the message and encrypt it
    for(int i=0; i<length; ++i) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            encrypted_msg[i] = (message[i] + key) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            encrypted_msg[i] = (message[i] + key) % 26 + 'A';
        }
        else {
            encrypted_msg[i] = message[i];
        }
    }
    encrypted_msg[length] = '\0';
    return encrypted_msg;
}

// Function to decrypt the message
char* decrypt(char* message, int key) {
    int length = strlen(message);
    char *decrypted_msg = (char*)malloc(length+1);
        // Iterate through each character of the message and decrypt it
    for(int i=0; i<length; ++i) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            decrypted_msg[i] = (message[i] - key + 26) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            decrypted_msg[i] = (message[i] - key + 26) % 26 + 'A';
        }
        else {
            decrypted_msg[i] = message[i];
        }
    }
    decrypted_msg[length] = '\0';
    return decrypted_msg;
}

// Main function
int main() {
    char message[100];
    int key;
    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]", message);
    printf("Enter the key: ");
    scanf("%d", &key);
        // Encrypt the message
    char* encrypted_msg = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_msg);
        // Decrypt the message
    char* decrypted_msg = decrypt(encrypted_msg, key);
    printf("Decrypted message: %s\n", decrypted_msg);
    free(encrypted_msg);
    free(decrypted_msg);
    return 0;
}