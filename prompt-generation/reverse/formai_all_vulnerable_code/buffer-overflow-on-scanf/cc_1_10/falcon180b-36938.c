//Falcon-180B DATASET v1.0 Category: Encryption ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 16
#define MAX_PLAIN_TEXT_LENGTH 1000

// Function to generate a random key
void generate_key(char *key) {
    srand(time(NULL));
    int i;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_LENGTH] = '\0';
}

// Function to encrypt the plain text using the key
void encrypt(char *plain_text, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(plain_text); i++) {
        if (isalpha(plain_text[i])) {
            plain_text[i] = tolower(plain_text[i]);
            plain_text[i] = plain_text[i] + 'a' - 'a' + j % 26;
            j++;
        }
    }
}

// Function to decrypt the cipher text using the key
void decrypt(char *cipher_text, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(cipher_text); i++) {
        if (isalpha(cipher_text[i])) {
            cipher_text[i] = tolower(cipher_text[i]);
            cipher_text[i] = cipher_text[i] - 'a' - j % 26 + 'a';
            j++;
        }
    }
}

// Function to display the menu
void display_menu() {
    printf("\n");
    printf("------------------------\n");
    printf("| Post-Apocalyptic Cipher |\n");
    printf("------------------------\n");
    printf("\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Exit\n");
    printf("\n");
}

// Function to get the choice from the user
int get_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to get the plain text from the user
void get_plain_text(char *plain_text) {
    printf("Enter the plain text: ");
    scanf("%s", plain_text);
}

// Function to get the cipher text from the user
void get_cipher_text(char *cipher_text) {
    printf("Enter the cipher text: ");
    scanf("%s", cipher_text);
}

// Function to get the key from the user
void get_key(char *key) {
    printf("Enter the key: ");
    scanf("%s", key);
}

// Main function
int main() {
    char plain_text[MAX_PLAIN_TEXT_LENGTH];
    char cipher_text[MAX_PLAIN_TEXT_LENGTH];
    char key[MAX_KEY_LENGTH];

    int choice;
    do {
        display_menu();
        choice = get_choice();

        switch (choice) {
            case 1: // Encrypt
                get_plain_text(plain_text);
                generate_key(key);
                encrypt(plain_text, key);
                printf("Encrypted text: %s\n", plain_text);
                break;

            case 2: // Decrypt
                get_cipher_text(cipher_text);
                get_key(key);
                decrypt(cipher_text, key);
                printf("Decrypted text: %s\n", cipher_text);
                break;

            case 3: // Exit
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}