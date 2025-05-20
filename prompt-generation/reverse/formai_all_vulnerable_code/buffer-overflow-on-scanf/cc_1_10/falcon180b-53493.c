//Falcon-180B DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define KEY "mysecretkey"
#define KEY_LENGTH 9
#define BLOCK_SIZE 8
#define NUM_ROUNDS 10

void encrypt(char *input, char *output) {
    int i, j, k, sum;
    char key[KEY_LENGTH];
    strcpy(key, KEY);
    sum = 0;

    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            input[i] = toupper(input[i]);
            j = input[i] - 'A';
            for (k = 0; k < KEY_LENGTH; k++) {
                sum = sum + (j * key[k]) % 26;
            }
            output[i] = (char) (sum % 26 + 'A');
        } else {
            output[i] = input[i];
        }
    }
}

void decrypt(char *input, char *output) {
    int i, j, k, sum;
    char key[KEY_LENGTH];
    strcpy(key, KEY);
    sum = 0;

    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            j = input[i] - 'A';
            sum = 0;

            for (k = 0; k < KEY_LENGTH; k++) {
                sum = (sum + (26 - key[k])) % 26;
            }

            output[i] = (char) ((26 - sum) % 26 + 'A');
        } else {
            output[i] = input[i];
        }
    }
}

int main() {
    char input[100], output[100];
    printf("Enter the message to be encrypted: ");
    scanf("%s", input);
    encrypt(input, output);
    printf("Encrypted message: %s\n", output);

    printf("Enter the encrypted message: ");
    scanf("%s", input);
    decrypt(input, output);
    printf("Decrypted message: %s\n", output);

    return 0;
}