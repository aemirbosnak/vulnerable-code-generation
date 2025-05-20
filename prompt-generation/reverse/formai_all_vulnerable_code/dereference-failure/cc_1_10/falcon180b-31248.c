//Falcon-180B DATASET v1.0 Category: Encryption ; Style: cheerful
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define KEY "mysecretkey"
#define KEY_LENGTH 12

#define ENCRYPT 1
#define DECRYPT 2

char *encrypt(char *message, int mode) {
    char *ciphertext = (char*)malloc(strlen(message) + 1);
    char *key = (char*)malloc(KEY_LENGTH + 1);
    strcpy(key, KEY);
    int i, j, k;

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                ciphertext[i] = ((int)message[i] + (int)key[j]) % 26 + 65;
            } else {
                ciphertext[i] = ((int)message[i] + (int)key[j]) % 26 + 97;
            }
        } else {
            ciphertext[i] = message[i];
        }
        j++;
        if (j == KEY_LENGTH) {
            j = 0;
        }
    }
    if (mode == ENCRYPT) {
        printf("Encrypted message: %s\n", ciphertext);
    } else {
        printf("Decrypted message: %s\n", ciphertext);
    }
    free(key);
    return ciphertext;
}

int main() {
    char message[100];
    printf("Enter a message to encrypt/decrypt:\n");
    scanf("%s", message);
    int choice;
    printf("Enter 1 to encrypt or 2 to decrypt:\n");
    scanf("%d", &choice);

    char *ciphertext = encrypt(message, choice);

    free(ciphertext);
    return 0;
}