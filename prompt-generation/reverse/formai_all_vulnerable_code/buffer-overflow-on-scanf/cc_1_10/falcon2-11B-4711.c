//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: surprised
// Cryptography Implementation Example

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random key
void generate_key() {
    int key[26];
    srand(time(NULL));
    for (int i = 0; i < 26; i++) {
        key[i] = rand() % 26;
    }
    printf("Generated Key: ");
    for (int i = 0; i < 26; i++) {
        printf("%d ", key[i]);
    }
    printf("\n");
}

// Function to encrypt a string using the key
char* encrypt(char* str, int* key) {
    int len = strlen(str);
    char* encrypted = (char*)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        int index = (str[i] - 'a') * key[i % 26];
        if (index > 25) {
            index = index % 26;
        }
        encrypted[i] = 'a' + index;
    }
    return encrypted;
}

// Function to decrypt a string using the key
char* decrypt(char* str, int* key) {
    int len = strlen(str);
    char* decrypted = (char*)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        int index = (str[i] - 'a') * key[i % 26];
        if (index > 25) {
            index = index % 26;
        }
        decrypted[i] = index + 'a';
    }
    return decrypted;
}

int main() {
    int key[26];
    generate_key();

    char str[100];
    printf("Enter a string to encrypt: ");
    scanf("%s", str);

    char* encrypted = encrypt(str, key);
    printf("Encrypted string: %s\n", encrypted);

    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted string: %s\n", decrypted);

    free(encrypted);
    free(decrypted);
    return 0;
}