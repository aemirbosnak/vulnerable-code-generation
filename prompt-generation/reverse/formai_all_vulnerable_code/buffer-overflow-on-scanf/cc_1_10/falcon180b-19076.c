//Falcon-180B DATASET v1.0 Category: Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

char *encrypt(char *input, int key);

int main() {
    char input[MAX_LENGTH];
    int key;

    printf("Enter a string to encrypt: ");
    fgets(input, MAX_LENGTH, stdin);

    printf("Enter a key (an integer between 1 and 25): ");
    scanf("%d", &key);

    char *encrypted = encrypt(input, key);

    printf("Encrypted string: %s\n", encrypted);

    return 0;
}

char *encrypt(char *input, int key) {
    int length = strlen(input);
    char *encrypted = malloc(length + 1);

    if (length == 0) {
        strcpy(encrypted, "");
        return encrypted;
    }

    char first_letter = input[0];
    int index = (first_letter - 'a') + key;

    if (index > 25) {
        index -= 26;
    }

    encrypted[0] = index + 'a';

    if (length == 1) {
        strcpy(encrypted + 1, "");
        return encrypted;
    }

    char *rest = encrypt(input + 1, key);

    strcat(encrypted, rest);

    return encrypted;
}