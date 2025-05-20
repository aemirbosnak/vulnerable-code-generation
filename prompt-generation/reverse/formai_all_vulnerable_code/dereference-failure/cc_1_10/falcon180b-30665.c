//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_SIZE 1000
#define MAX_STRING_LENGTH 1000

void generate_key(char *key, int key_size) {
    int i;
    for (i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt(char *string, char *key, int key_size) {
    int i, j;
    for (i = 0, j = 0; string[i]; i++) {
        if (isalpha(string[i])) {
            string[i] = (string[i] - 'a' + key[j] - 'a') % 26 + 'a';
            j++;
            if (j == key_size) {
                j = 0;
            }
        }
    }
}

void decrypt(char *string, char *key, int key_size) {
    int i, j;
    for (i = 0, j = 0; string[i]; i++) {
        if (isalpha(string[i])) {
            string[i] = (string[i] - 'a' - key[j] + 26) % 26 + 'a';
            j++;
            if (j == key_size) {
                j = 0;
            }
        }
    }
}

int main() {
    char string[MAX_STRING_LENGTH], key[MAX_KEY_SIZE];
    int string_size, key_size;

    srand(time(NULL));
    printf("Enter a string to encrypt: ");
    scanf("%s", string);
    string_size = strlen(string);

    printf("Enter the key size (between 1 and %d): ", MAX_KEY_SIZE - 1);
    scanf("%d", &key_size);

    generate_key(key, key_size);
    encrypt(string, key, key_size);
    printf("Encrypted string: %s\n", string);

    decrypt(string, key, key_size);
    printf("Decrypted string: %s\n", string);

    return 0;
}