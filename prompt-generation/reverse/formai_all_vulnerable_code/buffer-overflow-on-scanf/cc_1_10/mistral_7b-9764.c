//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 26
#define PLAIN_TEXT_SIZE 100
#define CIPHER_TEXT_SIZE 100

char key[KEY_SIZE];
char plain_text[PLAIN_TEXT_SIZE];
char cipher_text[CIPHER_TEXT_SIZE];

void generate_key() {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = (char) ('A' + i);
    }
}

void encrypt() {
    int i;
    for (i = 0; i < strlen(plain_text); i++) {
        if (plain_text[i] >= 'A' && plain_text[i] <= 'Z') {
            cipher_text[i] = (plain_text[i] + key[(plain_text[i] - 'A') % KEY_SIZE]) % 26 + 'A';
        } else {
            cipher_text[i] = plain_text[i];
        }
    }
    cipher_text[i] = '\0';
}

int main() {
    int choice;

    printf("Welcome to the Caesar Cipher Encryption Program!\n");
    printf("1. Generate Key\n");
    printf("2. Encrypt Text\n");
    printf("3. Exit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generate_key();
                printf("Key generated successfully!\n");
                break;
            case 2:
                printf("Enter the plain text:\n");
                scanf("%s", plain_text);
                encrypt();
                printf("The cipher text is: %s\n", cipher_text);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}