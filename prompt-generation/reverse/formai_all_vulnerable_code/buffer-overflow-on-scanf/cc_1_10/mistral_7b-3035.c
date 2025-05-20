//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MESSAGE_LENGTH 100
#define KEY_LENGTH 1

void print_menu() {
    printf("Welcome to The Enchanted Quill Encryption Program!\n");
    printf("-----------------------------------------------\n");
    printf("Enter 'E' to Encrypt a message or 'D' to Decrypt:\n");
    printf("-----------------------------------------------\n");
}

void encrypt_message(char *message, char key) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = (char)(((int)message[i] + (int)key - 97) % 26 + 97);
        }
    }
}

void decrypt_message(char *message, char key) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = (char)(((int)message[i] - (int)key + 26) % 26 + 97);
        }
    }
}

int main() {
    char message[MESSAGE_LENGTH];
    char key;
    int choice;

    print_menu();
    scanf("%c", &choice);

    if (choice != 'E' && choice != 'e' && choice != 'D' && choice != 'd') {
        printf("Invalid choice! Please try again.\n");
        main();
    }

    printf("Enter your message: ");
    scanf("%s", message);

    if (choice == 'E' || choice == 'e') {
        printf("Enter your encryption key: ");
        scanf("%c", &key);
        encrypt_message(message, key);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 'D' || choice == 'd') {
        printf("Enter your decryption key: ");
        scanf("%c", &key);
        decrypt_message(message, key);
        printf("Decrypted message: %s\n", message);
    }

    return 0;
}