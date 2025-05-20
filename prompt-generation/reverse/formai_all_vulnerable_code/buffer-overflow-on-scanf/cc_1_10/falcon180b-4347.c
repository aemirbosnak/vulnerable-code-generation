//Falcon-180B DATASET v1.0 Category: Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void encrypt(char* input, char* key, char* output) {
    int i, j;
    char temp;
    int key_length = strlen(key);

    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            temp = tolower(input[i]);
            for (j = 0; j < key_length; j++) {
                if (isalpha(key[j])) {
                    if (temp == tolower(key[j])) {
                        temp = key[j];
                        break;
                    }
                }
            }
            output[i] = temp;
        } else {
            output[i] = input[i];
        }
    }
    output[strlen(input)] = '\0';
}

void decrypt(char* input, char* key, char* output) {
    int i, j;
    char temp;
    int key_length = strlen(key);

    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            temp = toupper(input[i]);
            for (j = 0; j < key_length; j++) {
                if (isalpha(key[j])) {
                    if (temp == toupper(key[j])) {
                        temp = 'A';
                        break;
                    }
                }
            }
            output[i] = temp;
        } else {
            output[i] = input[i];
        }
    }
    output[strlen(input)] = '\0';
}

int main() {
    char input[MAX_LENGTH];
    char key[MAX_LENGTH];
    char output[MAX_LENGTH];

    printf("Enter the input string: ");
    scanf("%s", input);

    printf("Enter the key: ");
    scanf("%s", key);

    encrypt(input, key, output);

    printf("Encrypted string: %s\n", output);

    decrypt(output, key, input);

    printf("Decrypted string: %s\n", input);

    return 0;
}