//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 16
#define MAX_INPUT_LENGTH 1000
#define MAX_OUTPUT_LENGTH (MAX_INPUT_LENGTH + 1)

typedef struct {
    char key[MAX_KEY_LENGTH + 1];
    int key_length;
} CaesarCipher;

void generate_random_key(char key[], int key_length) {
    srand(time(NULL));
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'A'; // generate a random uppercase letter
    }
    key[key_length] = '\0';
}

int main() {
    CaesarCipher cipher;
    char input_string[MAX_INPUT_LENGTH + 1];
    char output_string[MAX_OUTPUT_LENGTH + 1];
    int key_length;

    printf("Enter the key length (1-16): ");
    scanf("%d", &key_length);

    if (key_length < 1 || key_length > MAX_KEY_LENGTH) {
        printf("Invalid key length.\n");
        return 1;
    }

    generate_random_key(cipher.key, key_length);

    printf("Enter the input string to encrypt/decrypt: ");
    fgets(input_string, MAX_INPUT_LENGTH, stdin);
    input_string[strcspn(input_string, "\n")] = '\0'; // remove newline character

    // encrypt the input string
    for (int i = 0; i < strlen(input_string); i++) {
        if (isalpha(input_string[i])) {
            if (isupper(input_string[i])) {
                output_string[i] = (char) (((int) input_string[i] - 65 + cipher.key[0] - 65) % 26 + 65);
            } else {
                output_string[i] = (char) (((int) input_string[i] - 97 + cipher.key[0] - 97) % 26 + 97);
            }
        } else {
            output_string[i] = input_string[i];
        }
    }

    printf("Encrypted/Decrypted string: %s\n", output_string);

    return 0;
}