//Falcon-180B DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 16
#define MAX_PLAIN_TEXT_SIZE 100
#define MAX_CIPHER_TEXT_SIZE (MAX_PLAIN_TEXT_SIZE + 1)

void encrypt(char* key, char* plain_text, char* cipher_text) {
    int i, j, n;
    char temp;

    n = strlen(plain_text);

    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(plain_text[i])) {
            temp = plain_text[i];
            if (isupper(temp)) {
                temp = tolower(temp);
            }

            if (isalpha(key[j])) {
                temp = (temp - 'a' + key[j] - 'a') % 26 + 'a';
            } else {
                temp = (temp - 'a' + key[j] - 'A') % 26 + 'a';
            }

            cipher_text[i] = temp;
            j++;
            if (j == strlen(key)) {
                j = 0;
            }
        } else {
            cipher_text[i] = plain_text[i];
        }
    }

    cipher_text[n] = '\0';
}

int main() {
    char plain_text[MAX_PLAIN_TEXT_SIZE];
    char key[MAX_KEY_SIZE];
    char cipher_text[MAX_CIPHER_TEXT_SIZE];

    printf("Enter a message to encrypt: ");
    scanf("%s", plain_text);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    encrypt(key, plain_text, cipher_text);

    printf("Encrypted message: %s\n", cipher_text);

    return 0;
}