#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 50
#define MAX_PLAINTEXT_LEN 1000
#define MAX_CIPHERTEXT_LEN 1050

void myEncrypt(char *key, char *plainText, char *cipherText) {
    int i, j, k;

    for (i = 0; i < strlen(plainText); i++) {
        for (j = 0; j < strlen(key); j++) {
            cipherText[i] = (char)(plainText[i] + key[j] - 97 + 10);
            if (cipherText[i] > 122)
                cipherText[i] -= 26;
            if (i + j < MAX_CIPHERTEXT_LEN) {
                cipherText[i + j] = plainText[i + j];
            }
        }
    }
}

int main() {
    char key[MAX_KEY_LEN];
    char plainText[MAX_PLAINTEXT_LEN];
    char cipherText[MAX_CIPHERTEXT_LEN];

    printf("Enter encryption key (up to %d characters): ", MAX_KEY_LEN);
    scanf("%s", key);

    printf("Enter plain text (up to %d characters): ", MAX_PLAINTEXT_LEN);
    scanf("%s", plainText);

    myEncrypt(key, plainText, cipherText);

    printf("Encrypted Text:\n");
    for (int i = 0; i < strlen(cipherText); i++) {
        printf("%c", cipherText[i]);
    }

    printf("\nKey:\n%s\n", key);
    printf("Plain Text:\n%s\n", plainText);

    return 0;
}
