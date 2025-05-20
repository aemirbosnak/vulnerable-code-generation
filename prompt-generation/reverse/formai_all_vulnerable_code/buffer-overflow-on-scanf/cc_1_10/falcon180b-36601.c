//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_TEXT_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH + 1];
    int key_length;
    char text[MAX_TEXT_LENGTH + 1];
    int text_length;
} Message;

void generate_key(char* key, int key_length) {
    int i;
    for (i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

void encrypt(Message* message) {
    int i, j;
    char temp;
    for (i = 0, j = 0; i < message->text_length; i++) {
        if (isalpha(message->text[i])) {
            if (isupper(message->text[i])) {
                message->text[i] = 'A' + (message->text[i] - 'A' + message->key[j] - 'a') % 26;
            } else {
                message->text[i] = 'a' + (message->text[i] - 'a' + message->key[j] - 'a') % 26;
            }
            j = (j + 1) % message->key_length;
        } else {
            message->text[i] = message->text[i];
        }
    }
}

void decrypt(Message* message) {
    int i, j;
    char temp;
    for (i = 0, j = 0; i < message->text_length; i++) {
        if (isalpha(message->text[i])) {
            if (isupper(message->text[i])) {
                message->text[i] = 'A' + (message->text[i] - 'A' - message->key[j] + 26) % 26;
            } else {
                message->text[i] = 'a' + (message->text[i] - 'a' - message->key[j] + 26) % 26;
            }
            j = (j + 1) % message->key_length;
        } else {
            message->text[i] = message->text[i];
        }
    }
}

int main() {
    Message message;
    char key[MAX_KEY_LENGTH + 1];
    int key_length;
    char text[MAX_TEXT_LENGTH + 1];
    int text_length;

    printf("Enter the text to be encrypted/decrypted: ");
    scanf("%s", text);
    text_length = strlen(text);

    printf("Enter the key: ");
    scanf("%s", key);
    key_length = strlen(key);

    if (key_length > MAX_KEY_LENGTH) {
        printf("Error: Key length cannot exceed %d\n", MAX_KEY_LENGTH);
        return 1;
    }

    strcpy(message.key, key);
    message.key_length = key_length;
    strcpy(message.text, text);
    message.text_length = text_length;

    printf("Original text: %s\n", message.text);

    encrypt(&message);
    printf("Encrypted text: %s\n", message.text);

    decrypt(&message);
    printf("Decrypted text: %s\n", message.text);

    return 0;
}