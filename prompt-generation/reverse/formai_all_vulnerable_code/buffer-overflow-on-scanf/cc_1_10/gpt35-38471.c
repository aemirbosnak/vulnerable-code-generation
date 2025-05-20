//FormAI DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <string.h>

// Function to perform encryption
void encrypt(char text[], int key) {
    int i;
    char ch;
    for(i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        // Shift character by the key
        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            text[i] = ch;
        } else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            text[i] = ch;
        }
    }
}

// Function to perform decryption
void decrypt(char text[], int key) {
    // Negative of key for decryption
    key = -key;
    int i;
    char ch;
    for(i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        // Shift character by the key
        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if(ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            text[i] = ch;
        } else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            text[i] = ch;
        }
    }
}

int main() {
    char text[100];
    int key;
    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter a key: ");
    scanf("%d", &key);
    // Encrypt the text
    encrypt(text, key);
    printf("Encrypted text: %s\n", text);
    // Decrypt the text
    decrypt(text, key);
    printf("Decrypted text: %s\n", text);
    return 0;
}