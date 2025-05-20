//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *plaintext;
    size_t plaintext_length;
    char *ciphertext;
    size_t ciphertext_length;
} Message;

char *encrypt(Message *message, char *key);
char *decrypt(Message *message, char *key);

int main() {
    Message message;
    char *key = "my_secret_key";

    printf("Enter your message of love, my dearest:\n");
    scanf("%s", message.plaintext);

    message.plaintext_length = strlen(message.plaintext);
    message.ciphertext = malloc(message.plaintext_length);

    message.ciphertext = encrypt(&message, key);

    printf("Behold, my encrypted whispers for your eyes only:\n");
    puts(message.ciphertext);

    message.ciphertext_length = strlen(message.ciphertext);
    message.plaintext = malloc(message.ciphertext_length);

    message.plaintext = decrypt(&message, key);

    printf("And now, the unveiled tapestry of our love, decrypted:\n");
    puts(message.plaintext);

    free(message.ciphertext);
    free(message.plaintext);
    return 0;
}

char *encrypt(Message *message, char *key) {
    size_t i;
    for (i = 0; i < message->plaintext_length; i++) {
        message->ciphertext[i] = message->plaintext[i] ^ key[i % strlen(key)];
    }
    return message->ciphertext;
}

char *decrypt(Message *message, char *key) {
    size_t i;
    for (i = 0; i < message->ciphertext_length; i++) {
        message->plaintext[i] = message->ciphertext[i] ^ key[i % strlen(key)];
    }
    return message->plaintext;
}