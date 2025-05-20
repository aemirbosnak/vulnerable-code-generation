//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the given string using Caesar cipher
void encrypt(char *str) {
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                str[i] = (str[i] + 3) % 26 + 'A';
            }
            else {
                str[i] = (str[i] + 3) % 26 + 'a';
            }
        }
    }
}

// Function to decrypt the given string using Caesar cipher
void decrypt(char *str) {
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                str[i] = (str[i] - 3 + 26) % 26 + 'A';
            }
            else {
                str[i] = (str[i] - 3 + 26) % 26 + 'a';
            }
        }
    }
}

int main() {
    char input[100], choice;
    do {
        printf("Enter a string to encrypt/decrypt: ");
        scanf("%[^\n]", input);
        fflush(stdin);
        printf("Enter 'e' to encrypt or 'd' to decrypt: ");
        scanf(" %c", &choice);
        fflush(stdin);

        if (choice == 'e' || choice == 'E') {
            encrypt(input);
            printf("Encrypted string: %s\n", input);
        }
        else if (choice == 'd' || choice == 'D') {
            decrypt(input);
            printf("Decrypted string: %s\n", input);
        }
        else {
            printf("Invalid choice! Please try again.\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);
        fflush(stdin);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}