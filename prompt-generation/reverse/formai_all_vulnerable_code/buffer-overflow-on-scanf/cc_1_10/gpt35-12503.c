//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

// Caesar Cipher Implementation
void caesar_cipher(char *message, int shift) {
    for(int i = 0; message[i] != '\0'; i++) {
        char current_char = message[i];

        if(current_char >= 'a' && current_char <= 'z') {
            current_char = ((current_char - 'a') + shift) % 26 + 'a';
        } else if(current_char >= 'A' && current_char <= 'Z') {
            current_char = ((current_char - 'A') + shift) % 26 + 'A';
        }

        message[i] = current_char;
    }
}

// Vigenere Cipher Implementation
void vigenere_cipher(char *message, char *key) {
    int key_length = strlen(key);

    for(int i = 0, j = 0; message[i] != '\0'; i++, j++) {
        char current_char = message[i];

        if(current_char >= 'a' && current_char <= 'z') {
            current_char = ((current_char - 'a') + (key[j % key_length] - 'a')) % 26 + 'a';
        } else if(current_char >= 'A' && current_char <= 'Z') {
            current_char = ((current_char - 'A') + (key[j % key_length] - 'A')) % 26 + 'A';
        }

        message[i] = current_char;
    }
}

int main() {
    char message[100];
    char key[100];
    int shift;

    printf("Enter message: ");
    fgets(message, 100, stdin);
    printf("Enter shift for Caesar Cipher: ");
    scanf("%d", &shift);

    caesar_cipher(message, shift);
    printf("Caesar Cipher Output: %s", message);

    printf("Enter key for Vigenere Cipher: ");
    scanf("%s", key);

    vigenere_cipher(message, key);
    printf("Vigenere Cipher Output: %s", message);

    return 0;
}