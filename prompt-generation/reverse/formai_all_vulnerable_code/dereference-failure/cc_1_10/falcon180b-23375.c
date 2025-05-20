//Falcon-180B DATASET v1.0 Category: Encryption ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 1024
#define MAX_ENCRYPTION_SIZE 1024

char *encrypt(char *input, char *key);

int main() {
    char input[MAX_ENCRYPTION_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter the input text to be encrypted: ");
    fgets(input, MAX_ENCRYPTION_SIZE, stdin);

    printf("Enter the encryption key: ");
    fgets(key, MAX_KEY_SIZE, stdin);

    char *encrypted_text = encrypt(input, key);

    printf("Encrypted text: %s\n", encrypted_text);

    return 0;
}

char *encrypt(char *input, char *key) {
    int input_length = strlen(input);
    int key_length = strlen(key);

    char *encrypted_text = malloc(input_length + 1);

    int i, j;
    for (i = 0, j = 0; i < input_length; i++) {
        char c = tolower(input[i]);

        if (isalpha(c)) {
            int k = (int)key[j % key_length] % 26;

            if (isupper(c)) {
                c = (c - 'A' + k) % 26 + 'A';
            } else {
                c = (c - 'a' + k) % 26 + 'a';
            }

            encrypted_text[i] = c;
            j++;
        } else {
            encrypted_text[i] = input[i];
        }
    }

    encrypted_text[input_length] = '\0';

    return encrypted_text;
}