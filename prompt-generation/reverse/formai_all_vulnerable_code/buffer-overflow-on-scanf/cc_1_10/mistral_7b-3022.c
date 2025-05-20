//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define KEY_SIZE 3
#define MAX_CHAR 256

bool is_alpha(char c) {
    return (isalpha(c) || (islower(c) && c >= 'a' - KEY_SIZE) || (isupper(c) && c >= 'A' - KEY_SIZE));
}

void encrypt(char *input, int key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        if (is_alpha(input[i])) {
            if (isalpha(input[i]) && islower(input[i])) {
                input[i] = ((input[i] + key - 'a') % 26) + 'a';
            } else if (isalpha(input[i]) && isupper(input[i])) {
                input[i] = ((input[i] + key - 'A') % 26) + 'A';
            }
        }
    }
}

void print_menu() {
    printf("*****************************************************************\n");
    printf("*                                                               *\n");
    printf("*             Cheerful Caesar Cipher Encryption Program          *\n");
    printf("*                                                               *\n");
    printf("*****************************************************************\n");
    printf("* Press 1 to Encrypt a String                                    *\n");
    printf("* Press 2 to Exit                                               *\n");
    printf("*****************************************************************\n");
}

int main() {
    char input[MAX_CHAR];
    int key = 0;
    int choice = 0;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the string to encrypt: ");
                scanf("%s", input);

                printf("Enter the encryption key: ");
                scanf("%d", &key);

                encrypt(input, key);
                printf("Encrypted String: %s\n", input);
                break;
            case 2:
                printf("Goodbye and have a cheerful day!\n");
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Invalid choice! Please choose 1 or 2.\n");
        }
    } while (choice != 2);

    return EXIT_SUCCESS;
}