//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 26
#define INPUT_LENGTH 100
#define OUTPUT_LENGTH 100

void generate_key(char key[26]);
void encrypt(char plaintext[INPUT_LENGTH], char key[26], char ciphertext[OUTPUT_LENGTH]);
void print_ciphertext(char ciphertext[OUTPUT_LENGTH]);

int main() {
    char plaintext[INPUT_LENGTH];
    char key[KEY_LENGTH];
    char ciphertext[OUTPUT_LENGTH];

    printf("Enter a key (26 characters): ");
    scanf("%s", key);

    generate_key(key);

    printf("Enter a plaintext (100 characters): ");
    scanf("%s", plaintext);

    encrypt(plaintext, key, ciphertext);
    print_ciphertext(ciphertext);

    return 0;
}

void generate_key(char key[26]) {
    for (int i = 0; i < KEY_LENGTH; i++) {
        if (isalpha(key[i])) {
            if (islower(key[i])) {
                for (int j = i; j < KEY_LENGTH; j++) {
                    if (isalpha(key[j]) && isupper(key[j])) {
                        char temp = key[i];
                        key[i] = key[j];
                        key[j] = temp;
                        break;
                    }
                }
            }
        }
    }
}

void encrypt(char plaintext[INPUT_LENGTH], char key[26], char ciphertext[OUTPUT_LENGTH]) {
    for (int i = 0; i < INPUT_LENGTH; i++) {
        if (isalpha(plaintext[i])) {
            if (islower(plaintext[i])) {
                int index = plaintext[i] - 'a';
                int new_index = (index + (key[index] - 'a')) % KEY_LENGTH;
                ciphertext[i] = key[new_index] + 'a';
            } else {
                ciphertext[i] = plaintext[i];
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
}

void print_ciphertext(char ciphertext[OUTPUT_LENGTH]) {
    printf("Ciphertext: ");
    for (int i = 0; i < OUTPUT_LENGTH; i++) {
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}