//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8
#define INPUT_SIZE 1024

char* generate_key(void) {
    char* key = (char*)malloc(KEY_SIZE + 1);
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
    return key;
}

char* encrypt(char* message, char* key) {
    char* result = (char*)malloc(INPUT_SIZE + 1);
    int j = 0;
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            int k = tolower(message[i]) - 'a';
            k = (k + tolower(key[j % KEY_SIZE]) - 'a') % 26 + 'a';
            result[i] = k;
            j++;
        } else {
            result[i] = message[i];
        }
    }
    return result;
}

char* decrypt(char* cipher, char* key) {
    char* result = (char*)malloc(INPUT_SIZE + 1);
    int j = 0;
    for (int i = 0; i < strlen(cipher); i++) {
        if (isalpha(cipher[i])) {
            int k = tolower(cipher[i]) - 'a';
            k = (k - tolower(key[j % KEY_SIZE]) + 26) % 26 + 'a';
            result[i] = k;
            j++;
        } else {
            result[i] = cipher[i];
        }
    }
    return result;
}

int main(int argc, char** argv) {
    srand(time(NULL));
    char* message = (char*)malloc(INPUT_SIZE + 1);
    char* key = generate_key();
    printf("Enter a message to encrypt:\n");
    fgets(message, INPUT_SIZE, stdin);
    message[strlen(message) - 1] = '\0';
    char* cipher = encrypt(message, key);
    printf("Encrypted message: %s\n", cipher);
    char* decrypted = decrypt(cipher, key);
    printf("Decrypted message: %s\n", decrypted);
    free(message);
    free(cipher);
    free(decrypted);
    free(key);
    return 0;
}