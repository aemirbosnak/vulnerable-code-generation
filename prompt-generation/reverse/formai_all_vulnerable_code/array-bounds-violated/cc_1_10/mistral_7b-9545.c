//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS

typedef struct {
    char message[101];
    char encrypted[101];
} encryption_struct;

void encrypt(encryption_struct *message_struct, int key) {
    int i;
    for (i = 0; message_struct->message[i] != '\0'; i++) {
        if (isalpha(message_struct->message[i])) {
            if (isupper(message_struct->message[i])) {
                message_struct->encrypted[i] = ((message_struct->message[i] + key - 65) % 26) + 65;
            }
            else {
                message_struct->encrypted[i] = ((message_struct->message[i] + key - 97) % 26) + 97;
            }
        }
        else {
            message_struct->encrypted[i] = message_struct->message[i];
        }
    }
    message_struct->encrypted[100] = '\0';
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    char plaintext[101], encrypted_text[101];
    encryption_struct message;

    printf("Welcome, oh noble seeker of knowledge and cipher wisdom!\n");
    printf("To initiate the encryption process, you must first provide a message,\n");
    printf("one that holds the secret knowledge you wish to conceal.\n");
    printf("Enter your message below:\n");

    fgets(plaintext, 100, stdin);
    plaintext[strlen(plaintext) - 1] = '\0';

    printf("Behold, I shall now bestow upon you the key to unlock the enigma,\n");
    printf("a key of three, a number most mystifying and puzzling.\n");
    printf("With this key, your message shall be transformed beyond recognition.\n");

    strcpy(message.message, plaintext);
    encrypt(&message, 3);

    printf("\nYour encrypted message is as follows:\n");
    printf("%s\n", message.encrypted);

    return 0;
}