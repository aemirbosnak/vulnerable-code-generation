//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000

typedef struct {
    char input[SIZE];
    int key;
} message;

void encrypt(message *msg) {
    int i;
    for (i = 0; i < strlen(msg->input); i++) {
        if (isalpha(msg->input[i])) {
            if (isupper(msg->input[i])) {
                msg->input[i] = 'A' + ((msg->input[i] - 'A' + msg->key) % 26);
            } else {
                msg->input[i] = 'a' + ((msg->input[i] - 'a' + msg->key) % 26);
            }
        }
    }
}

void decrypt(message *msg) {
    int i;
    for (i = 0; i < strlen(msg->input); i++) {
        if (isalpha(msg->input[i])) {
            if (isupper(msg->input[i])) {
                msg->input[i] = 'A' + ((msg->input[i] - 'A' - msg->key + 26) % 26);
            } else {
                msg->input[i] = 'a' + ((msg->input[i] - 'a' - msg->key + 26) % 26);
            }
        }
    }
}

int main() {
    message msg;
    printf("Enter message to encrypt: ");
    scanf("%[^\n]", msg.input);
    printf("Enter key: ");
    scanf("%d", &msg.key);
    encrypt(&msg);
    printf("Encrypted message: %s\n", msg.input);
    decrypt(&msg);
    printf("Decrypted message: %s\n", msg.input);
    return 0;
}