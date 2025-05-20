//FormAI DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

void cipher(char* message, char* key);
void decipher(char* message, char* key);

int main() {
    char message[MAX_STRING_LENGTH];
    char key[MAX_STRING_LENGTH];
    int choice;

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_STRING_LENGTH, stdin);
    strtok(message, "\n"); // remove trailing newline character

    printf("Enter a key for encryption: ");
    fgets(key, MAX_STRING_LENGTH, stdin);
    strtok(key, "\n"); // remove trailing newline character

    printf("Choose an option:\n");
    printf("1. Encrypt message\n");
    printf("2. Decrypt message\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            cipher(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            decipher(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice\n");
            exit(1);
    }

    return 0;
}

// Encrypts the message using the provided key
void cipher(char* message, char* key) {
    srand(time(NULL)); // seed random number generator
    int key_length = strlen(key);
    int rand_num = rand() % key_length;
    char temp;
    int i;

    // Apply substitution cipher algorithm
    for (i = 0; i < strlen(message); i++) {
        temp = message[i];
        message[i] = key[rand_num];
        key[rand_num] = temp;
        rand_num = (rand_num + 1) % key_length;
    }
}

// Decrypts the message using the provided key
void decipher(char* message, char* key) {
    int key_length = strlen(key);
    int rand_num = rand() % key_length;
    char temp;
    int i;

    // Apply reverse substitution cipher algorithm
    for (i = strlen(message) - 1; i >= 0; i--) {
        temp = key[rand_num];
        key[rand_num] = message[i];
        message[i] = temp;
        rand_num = (rand_num + 1) % key_length;
    }
}