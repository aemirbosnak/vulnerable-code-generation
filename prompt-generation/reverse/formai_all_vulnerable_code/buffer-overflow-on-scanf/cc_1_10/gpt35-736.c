//FormAI DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretpass" // Change this to your desired key
#define ENCODE_VAL 200 // Change this to your desired encoding value
#define MSG_SIZE 1024 // Change this to your desired message size

void encode(char *msg, char *key);
void decode(char *msg, char *key);

int main() {
    char message[MSG_SIZE];
    char choice;
    printf("Enter your message: ");
    fgets(message, MSG_SIZE, stdin);
    printf("Enter 'E' to encode or 'D' to decode: ");
    scanf("%c", &choice);

    switch (choice) {
        case 'E':
            encode(message, KEY);
            printf("Your encoded message: %s\n", message);
            break;

        case 'D':
            decode(message, KEY);
            printf("Your decoded message: %s\n", message);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

void encode(char *msg, char *key) {
    if (msg == NULL || key == NULL) {
        printf("Error: message or key is NULL!\n");
        exit(EXIT_FAILURE);
    }

    size_t msg_len = strlen(msg);
    size_t key_len = strlen(key);
    int key_index = 0;

    for (size_t i = 0; i < msg_len; i++) {
        if (key_index >= key_len) {
            key_index = 0;
        }

        msg[i] = msg[i] + KEY[key_index] + ENCODE_VAL;
        key_index++;
    }
}

void decode(char *msg, char *key) {
    if (msg == NULL || key == NULL) {
        printf("Error: message or key is NULL!\n");
        exit(EXIT_FAILURE);
    }

    size_t msg_len = strlen(msg);
    size_t key_len = strlen(key);
    int key_index = 0;

    for (size_t i = 0; i < msg_len; i++) {
        if (key_index >= key_len) {
            key_index = 0;
        }

        msg[i] = msg[i] - KEY[key_index] - ENCODE_VAL;
        key_index++;
    }
}