//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 256

void encrypt(char *key, char *text) {
    int i, j, k;
    char *encrypted = (char *) malloc(strlen(text) + 1);
    char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *key_index = (char *) malloc(strlen(key) + 1);

    strcpy(key_index, key);
    for (i = 0; i < strlen(key); i++) {
        key_index[i] = tolower(key_index[i]);
    }

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            j = tolower(text[i]) - 97;
            k = 0;
            while (key_index[k]!= '\0') {
                if (key_index[k] == text[i]) {
                    break;
                }
                k++;
            }
            encrypted[i] = alphabet[j + k];
        } else {
            encrypted[i] = text[i];
        }
    }

    encrypted[strlen(text)] = '\0';

    printf("Encrypted Text: %s\n", encrypted);
}

int main() {
    char key[SIZE];
    char text[SIZE];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the text to be encrypted: ");
    scanf("%s", text);

    encrypt(key, text);

    return 0;
}