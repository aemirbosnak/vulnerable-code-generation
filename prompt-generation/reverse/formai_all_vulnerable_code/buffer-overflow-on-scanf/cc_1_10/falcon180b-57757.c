//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_MSG_LEN 1000

void encrypt(char *key, char *msg) {
    int key_len = strlen(key);
    int msg_len = strlen(msg);
    char *result = malloc(msg_len + 1);
    int j = 0;

    for (int i = 0; i < msg_len; i++) {
        if (isalpha(msg[i])) {
            if (isupper(msg[i])) {
                result[j] = ((msg[i] - 65 + key_len) % 26) + 65;
            } else {
                result[j] = ((msg[i] - 97 + key_len) % 26) + 97;
            }
        } else {
            result[j] = msg[i];
        }
        j++;
    }

    result[j] = '\0';

    printf("Encrypted message: %s\n", result);
}

void decrypt(char *key, char *msg) {
    int key_len = strlen(key);
    int msg_len = strlen(msg);
    char *result = malloc(msg_len + 1);
    int j = 0;

    for (int i = 0; i < msg_len; i++) {
        if (isalpha(msg[i])) {
            if (isupper(msg[i])) {
                result[j] = ((msg[i] - 65 - key_len + 26) % 26) + 65;
            } else {
                result[j] = ((msg[i] - 97 - key_len + 26) % 26) + 97;
            }
        } else {
            result[j] = msg[i];
        }
        j++;
    }

    result[j] = '\0';

    printf("Decrypted message: %s\n", result);
}

int main() {
    char key[MAX_KEY_LEN];
    char msg[MAX_MSG_LEN];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the message: ");
    scanf("%s", msg);

    printf("Enter 'e' to encrypt or 'd' to decrypt: ");
    char choice;
    scanf("%c", &choice);

    if (choice == 'e' || choice == 'E') {
        encrypt(key, msg);
    } else if (choice == 'd' || choice == 'D') {
        decrypt(key, msg);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}