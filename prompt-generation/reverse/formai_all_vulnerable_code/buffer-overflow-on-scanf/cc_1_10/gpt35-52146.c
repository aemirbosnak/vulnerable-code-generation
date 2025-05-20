//FormAI DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int key, int length);

int main() {
    char message[100];
    int key, length;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter a key (1-26): ");
    scanf("%d", &key);

    length = strlen(message);

    encrypt(message, key, length);

    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int key, int length) {
    int i;
    char ch;

    for(i = 0; i < length; i++) {
        ch = message[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;

            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;

            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}