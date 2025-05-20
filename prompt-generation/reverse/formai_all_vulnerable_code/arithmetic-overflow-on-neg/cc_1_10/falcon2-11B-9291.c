//Falcon2-11B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cryptic
#include <stdio.h>
#include <string.h>

// Function to encrypt a word using a Caesar cipher
void encrypt(char* word, int key) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        char c = word[i];
        if (c >= 'a' && c <= 'z') {
            c += key;
            if (c > 'z') {
                c -= 26;
            }
        }
        else if (c >= 'A' && c <= 'Z') {
            c += key;
            if (c > 'Z') {
                c -= 26;
            }
        }
        word[i] = c;
    }
}

// Function to decrypt a word using a Caesar cipher
void decrypt(char* word, int key) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        char c = word[i];
        if (c >= 'a' && c <= 'z') {
            c -= key;
            if (c < 'a') {
                c += 26;
            }
        }
        else if (c >= 'A' && c <= 'Z') {
            c -= key;
            if (c < 'A') {
                c += 26;
            }
        }
        word[i] = c;
    }
}

int main() {
    char word[100];
    printf("Enter a word to encrypt: ");
    fgets(word, sizeof(word), stdin);
    int key;
    printf("Enter the encryption key (1-25): ");
    scanf("%d", &key);

    encrypt(word, key);
    printf("Encrypted word: %s\n", word);

    key = -key;
    decrypt(word, key);
    printf("Decrypted word: %s\n", word);

    return 0;
}