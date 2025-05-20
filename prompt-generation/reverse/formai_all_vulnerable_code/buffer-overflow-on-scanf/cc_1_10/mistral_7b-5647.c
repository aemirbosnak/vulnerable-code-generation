//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>

#define MAX_LENGTH 100

char* encrypt(char* text, int key) {
    int len = strlen(text);
    char* encrypted = malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i]))
                encrypted[i] = (char) (((int)text[i] + key - 65) % 26 + 65);
            else
                encrypted[i] = (char) (((int)text[i] + key - 97) % 26 + 97);
        } else {
            encrypted[i] = text[i];
        }
    }

    encrypted[len] = '\0';
    return encrypted;
}

void print_menu() {
    printf("\n---Whisper's Secret Garden---\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Exit\n");
}

int main() {
    int choice, key;
    char text[MAX_LENGTH];
    char* encrypted_text = NULL;

    srand(time(NULL));
    key = rand() % 26;

    printf("Welcome to Whisper's Secret Garden! Your secret key is:\n");
    printf("%c\n", 'A' + key);

    print_menu();

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the text to encrypt: ");
                scanf("%s", text);
                encrypted_text = encrypt(text, key);
                printf("Encrypted text: %s\n", encrypted_text);
                free(encrypted_text);
                break;
            case 2:
                printf("Enter the encrypted text to decrypt: ");
                scanf("%s", text);
                encrypted_text = encrypt(text, -key);
                printf("Decrypted text: %s\n", encrypted_text);
                free(encrypted_text);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                print_menu();
        }
    }

    return 0;
}