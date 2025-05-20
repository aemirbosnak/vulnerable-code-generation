//Falcon-180B DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "mysecretkey"

void encrypt(char* str) {
    int i = 0, j = 0;
    char key[strlen(KEY)];
    strcpy(key, KEY);
    for (i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                str[i] = (str[i] - 65 + j) % 26 + 65;
            } else {
                str[i] = (str[i] - 97 + j) % 26 + 97;
            }
        }
    }
}

void decrypt(char* str) {
    int i = 0, j = 0;
    char key[strlen(KEY)];
    strcpy(key, KEY);
    for (i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                str[i] = (str[i] - 65 - j + 26) % 26 + 65;
            } else {
                str[i] = (str[i] - 97 - j + 26) % 26 + 97;
            }
        }
    }
}

int main() {
    char str[100], choice;
    printf("Enter a string to encrypt/decrypt: ");
    scanf("%s", str);
    printf("Enter 'e' to encrypt or 'd' to decrypt: ");
    scanf("%c", &choice);

    if (choice == 'e' || choice == 'E') {
        encrypt(str);
        printf("Encrypted string: %s\n", str);
    } else if (choice == 'd' || choice == 'D') {
        decrypt(str);
        printf("Decrypted string: %s\n", str);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}