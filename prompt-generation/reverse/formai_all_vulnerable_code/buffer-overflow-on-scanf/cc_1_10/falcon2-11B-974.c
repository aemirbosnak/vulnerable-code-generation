//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 64
#define MAX_MESSAGE_LENGTH 128

void generate_cipher(char* message, int length, char* key) {
    for(int i=0; i<length; i++) {
        message[i] = message[i] ^ key[i % MAX_KEY_LENGTH];
    }
}

void generate_key(char* message, int length) {
    int i;
    char* key = (char*)malloc(MAX_KEY_LENGTH * sizeof(char));
    for(i=0; i<MAX_KEY_LENGTH; i++) {
        key[i] = 'a' + rand() % 26;
    }

    generate_cipher(message, length, key);
}

void print_cipher(char* message, int length) {
    printf("Cipher message: ");
    for(int i=0; i<length; i++) {
        printf("%c", message[i]);
    }
    printf("\n");
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int message_length;
    char key[MAX_KEY_LENGTH];
    int key_length;

    // Read the message and key from the user
    printf("Enter the message: ");
    scanf("%s", message);
    message_length = strlen(message);
    printf("Enter the key: ");
    scanf("%s", key);
    key_length = strlen(key);

    if(message_length > MAX_MESSAGE_LENGTH || key_length > MAX_KEY_LENGTH) {
        printf("Message or key is too long. Maximum length allowed is %d.\n", MAX_MESSAGE_LENGTH);
        return 1;
    }

    // Generate the cipher using the message and key
    generate_cipher(message, message_length, key);

    // Print the cipher message
    printf("Cipher message: ");
    print_cipher(message, message_length);

    return 0;
}