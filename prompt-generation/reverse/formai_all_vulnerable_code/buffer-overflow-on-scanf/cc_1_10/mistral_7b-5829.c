//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_CHARS 256

typedef struct {
    char text[MAX_CHARS];
    char key;
} EncryptableText;

void print_menu() {
    printf("\n--- MENU ---\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Exit\n");
}

void encrypt(EncryptableText* text) {
    for (int i = 0; text->text[i] != '\0'; i++) {
        if (isalpha(text->text[i])) {
            if (isupper(text->text[i])) {
                text->text[i] = (char) ((int)text->text[i] + text->key - 65);
            } else {
                text->text[i] = (char) ((int)text->text[i] + text->key);
            }
        }
    }
}

void decrypt(EncryptableText* text) {
    for (int i = 0; text->text[i] != '\0'; i++) {
        if (isalpha(text->text[i])) {
            if (isupper(text->text[i])) {
                text->text[i] = (char) ((int)text->text[i] - text->key + 65);
            } else {
                text->text[i] = (char) ((int)text->text[i] - text->key);
            }
        }
    }
}

void read_input(EncryptableText* text) {
    fgets(text->text, MAX_CHARS, stdin);
    text->text[strcspn(text->text, "\n")] = '\0';
}

void set_key(EncryptableText* text) {
    char input;
    printf("Enter key: ");
    scanf("%c", &input);
    text->key = input;
}

void print_result(EncryptableText text) {
    printf("\n--- RESULT ---\n");
    printf("%s\n", text.text);
}

int main() {
    EncryptableText data;
    int choice;

    while (true) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                read_input(&data);
                set_key(&data);
                encrypt(&data);
                print_result(data);
                break;
            case 2:
                read_input(&data);
                set_key(&data);
                decrypt(&data);
                print_result(data);
                break;
            case 3:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}