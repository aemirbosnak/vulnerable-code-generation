//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 1024
#define MAX_INPUT_SIZE 1024
#define MAX_OUTPUT_SIZE 1024

typedef struct {
    char *key;
    int key_size;
} Key;

Key generate_key(int size) {
    char *key = (char *) malloc(size);
    if (key == NULL) {
        printf("Error: Failed to generate key.\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    Key k = {key, size};
    return k;
}

void encrypt(Key key, char *input, char *output) {
    int i = 0, j = 0;
    while (i < strlen(input)) {
        if (isalpha(input[i])) {
            char c = input[i] + key.key[j % key.key_size];
            if (isupper(c)) {
                c = tolower(c);
            } else if (islower(c)) {
                c = toupper(c);
            }
            output[j] = c;
            j++;
        } else {
            output[j] = input[i];
            j++;
        }
        i++;
    }
    output[j] = '\0';
}

void decrypt(Key key, char *input, char *output) {
    int i = 0, j = 0;
    while (i < strlen(input)) {
        if (isalpha(input[i])) {
            char c = input[i] - key.key[j % key.key_size];
            if (isupper(c)) {
                c = tolower(c);
            } else if (islower(c)) {
                c = toupper(c);
            }
            output[j] = c;
            j++;
        } else {
            output[j] = input[i];
            j++;
        }
        i++;
    }
    output[j] = '\0';
}

int main() {
    int size = 0;
    printf("Enter the size of the key: ");
    scanf("%d", &size);
    Key k = generate_key(size);

    char input[MAX_INPUT_SIZE];
    printf("Enter the message to encrypt: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';

    char output[MAX_OUTPUT_SIZE];
    encrypt(k, input, output);
    printf("Encrypted message: %s\n", output);

    decrypt(k, output, input);
    printf("Decrypted message: %s\n", input);

    return 0;
}