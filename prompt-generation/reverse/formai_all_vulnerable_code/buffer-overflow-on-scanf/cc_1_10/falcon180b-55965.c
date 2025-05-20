//Falcon-180B DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_SIZE 20
#define MAX_MESSAGE_SIZE 1000

void generate_key(char *key) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
    key[MAX_KEY_SIZE - 1] = '\0';
}

void encrypt_message(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == MAX_KEY_SIZE) {
            j = 0;
        }
        message[i] = message[i] + key[j];
    }
}

void decrypt_message(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == MAX_KEY_SIZE) {
            j = 0;
        }
        message[i] = message[i] - key[j];
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    char choice;
    int i;

    printf("Welcome to the Funny Encryption Program!\n");
    printf("Enter your message (up to %d characters): ", MAX_MESSAGE_SIZE - 1);
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter the encryption key (up to %d characters): ", MAX_KEY_SIZE - 1);
    scanf("%s", key);

    if (strlen(key) > MAX_KEY_SIZE) {
        printf("Error: Key is too long.\n");
        return 1;
    }

    printf("Encrypted message: ");
    encrypt_message(message, key);
    printf("%s\n", message);

    printf("Decrypted message: ");
    decrypt_message(message, key);
    printf("%s\n", message);

    printf("Do you want to save the key? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y') {
        FILE *fp;
        fp = fopen("key.txt", "w");
        if (fp == NULL) {
            printf("Error: Unable to create key file.\n");
            return 1;
        }
        fprintf(fp, "%s", key);
        fclose(fp);
        printf("Key saved to key.txt.\n");
    }

    return 0;
}