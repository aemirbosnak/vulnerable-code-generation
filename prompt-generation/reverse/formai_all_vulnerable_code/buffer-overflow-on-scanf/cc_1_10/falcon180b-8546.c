//Falcon-180B DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26

char *encrypt(char *key, char *message) {
    int i, j, k, n;
    char *result = malloc(strlen(message) + 1);
    char *alpha = "abcdefghijklmnopqrstuvwxyz";
    char *alpha_reverse = "zyxwvutsrqponmlkjihgfedcba";

    if (result == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                n = tolower(message[i]) - 'a';
            } else {
                n = tolower(message[i]) - 'a';
            }

            j = 0;
            while (key[j]!= '\0') {
                k = tolower(key[j]) - 'a';
                if (k == n) {
                    result[i] = alpha[j];
                    break;
                }
                j++;
            }

            if (key[j] == '\0') {
                result[i] = alpha_reverse[n];
            }
        } else {
            result[i] = message[i];
        }
    }

    return result;
}

int main() {
    char *key, *message, *result;
    int choice;

    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    printf("Enter the key for encryption: ");
    scanf("%s", key);

    result = encrypt(key, message);

    printf("\nEncrypted message: %s\n", result);

    return 0;
}