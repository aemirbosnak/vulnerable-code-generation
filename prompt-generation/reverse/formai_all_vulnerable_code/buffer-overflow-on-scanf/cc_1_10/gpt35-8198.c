//FormAI DATASET v1.0 Category: Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int key);

int main() {
    char message[100];
    int key;
    
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);  // read input from user
    message[strcspn(message, "\n")] = 0;  // remove trailing newline character
    
    printf("Enter a key for encryption (1-25): ");
    scanf("%d", &key);
    
    encrypt(message, key);  // encrypt the message with given key
    
    printf("Encrypted message: %s\n", message);
    
    return 0;
}

void encrypt(char *message, int key) {
    int i;
    char ch;
    
    for (i = 0; message[i] != '\0'; i++) {
        ch = message[i];
        
        // encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            
            message[i] = ch;
        }
        // encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            
            message[i] = ch;
        }
        // ignore non-alphabetic characters
        else {
            continue;
        }
    }
}