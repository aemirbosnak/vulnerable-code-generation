//Falcon-180B DATASET v1.0 Category: Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, char *key) {
    int i, j, len = strlen(text);
    char result[len + 1];
    for (i = 0, j = 0; i < len; i++, j++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                result[j] = (text[i] + key[j % strlen(key)] - 65) % 26 + 65;
            } else {
                result[j] = (text[i] + key[j % strlen(key)] - 97) % 26 + 97;
            }
        } else {
            result[j] = text[i];
        }
    }
    result[len] = '\0';
    printf("%s\n", result);
}

void decrypt(char *text, char *key) {
    int i, j, len = strlen(text);
    char result[len + 1];
    for (i = 0, j = 0; i < len; i++, j++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                result[j] = (text[i] - key[j % strlen(key)] - 65 + 26) % 26 + 65;
            } else {
                result[j] = (text[i] - key[j % strlen(key)] - 97 + 26) % 26 + 97;
            }
        } else {
            result[j] = text[i];
        }
    }
    result[len] = '\0';
    printf("%s\n", result);
}

int main() {
    char text[100] = "Hello, world!";
    char key[100] = "secret";
    char choice;
    printf("Enter 'e' to encrypt or 'd' to decrypt: ");
    scanf("%c", &choice);
    if (choice == 'e' || choice == 'E') {
        encrypt(text, key);
    } else if (choice == 'd' || choice == 'D') {
        decrypt(text, key);
    } else {
        printf("Invalid choice!\n");
    }
    return 0;
}