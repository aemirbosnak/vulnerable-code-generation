//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000

int main() {
    char text[SIZE];
    char key[SIZE];
    int i, j, k, n, len;

    printf("Enter the text to be encrypted: ");
    fgets(text, SIZE, stdin);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    // remove any leading/trailing whitespace from key
    len = strlen(key);
    for (i = 0; i < len; i++) {
        if (isspace(key[i])) {
            key[i] = '\0';
        }
    }

    // pad key with X's to match text length
    n = strlen(text);
    for (i = strlen(key); i < n; i++) {
        key[i] = 'X';
    }

    // encrypt text using Vigenere cipher
    for (i = 0; i < n; i++) {
        text[i] = toupper(text[i]);
        key[i % strlen(key)] = toupper(key[i % strlen(key)]);
    }

    for (i = 0; i < n; i++) {
        if (isalpha(text[i])) {
            k = (int)text[i] - 65;
            j = (int)key[i % strlen(key)] - 65;
            text[i] = (char)((k + j) % 26 + 65);
        }
    }

    printf("Encrypted text: %s\n", text);

    return 0;
}