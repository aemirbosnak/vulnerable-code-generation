//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 256

char* encrypt(char* text, char* key) {
    int i, j, k, len_text, len_key;
    char* encrypted_text;

    len_text = strlen(text);
    len_key = strlen(key);
    encrypted_text = (char*) malloc((len_text + 1) * sizeof(char));

    for(i = 0, j = 0; i < len_text; i++) {
        k = (text[i] + key[j]) % 256;
        encrypted_text[i] = k;
        j = (j + 1) % len_key;
    }

    encrypted_text[len_text] = '\0';
    return encrypted_text;
}

char* decrypt(char* text, char* key) {
    int i, j, k, len_text, len_key;
    char* decrypted_text;

    len_text = strlen(text);
    len_key = strlen(key);
    decrypted_text = (char*) malloc((len_text + 1) * sizeof(char));

    for(i = 0, j = 0; i < len_text; i++) {
        k = (text[i] - key[j] + 256) % 256;
        decrypted_text[i] = k;
        j = (j + 1) % len_key;
    }

    decrypted_text[len_text] = '\0';
    return decrypted_text;
}

int main() {
    char text[MAX_KEY_SIZE];
    char key[MAX_KEY_SIZE];
    char* encrypted_text;
    char* decrypted_text;

    srand(time(NULL));
    printf("Enter the text to encrypt: ");
    scanf("%[^\n]s", text);

    for(int i = 0; i < strlen(text); i++) {
        key[i] = rand() % 256;
    }

    key[strlen(text)] = '\0';
    printf("Generated key: %s\n", key);

    encrypted_text = encrypt(text, key);
    printf("Encrypted text: %s\n", encrypted_text);

    decrypted_text = decrypt(encrypted_text, key);
    printf("Decrypted text: %s\n", decrypted_text);

    free(encrypted_text);
    free(decrypted_text);

    return 0;
}