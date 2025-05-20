//FormAI DATASET v1.0 Category: Modern Encryption ; Style: energetic
// Hey there! Welcome to our Modern Encryption program!
// This program takes in a message from the user and encrypts it using our state-of-the-art encryption algorithm.
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random key for our encryption algorithm
char* generate_key(int length) {
    char* key = malloc(length * sizeof(char));
    int i;
    for (i = 0; i < length; i++) {
        int val = rand() % 26;
        key[i] = 'a' + val;
    }
    key[length] = '\0';
    return key;
}

// Function to encrypt a message using our key
char* encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char* encrypted_message = malloc((message_length + 1) * sizeof(char));
    int i;
    for (i = 0; i < message_length; i++) {
        char c = message[i];
        char k = key[i % key_length];
        char encrypted_c = (c + k) % 26 + 'a';
        encrypted_message[i] = encrypted_c;
    }
    encrypted_message[message_length] = '\0';
    return encrypted_message;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    printf("Welcome to our Modern Encryption program!\n");
    printf("Please enter the message you want to encrypt: ");
    char message[100];
    scanf("%[^\n]", message);
    getchar(); // Consume the newline character left by scanf

    int key_length = rand() % 11 + 5; // Generate a random key length between 5 and 15

    char* key = generate_key(key_length);

    printf("Your key is: %s\n", key);

    char* encrypted_message = encrypt(message, key);
    printf("Your encrypted message is: %s\n", encrypted_message);

    free(key); // Free our dynamically allocated memory
    free(encrypted_message);

    return 0;
}