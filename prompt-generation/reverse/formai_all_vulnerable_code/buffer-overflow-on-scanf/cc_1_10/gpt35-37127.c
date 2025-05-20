//FormAI DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH_MAX 50
#define ENCRYPT_KEY 13 // Cipher Key

/*
 * Function to encrypt the password using Caesar cipher mechanism
 */
void encrypt_password(char password[]) {
    int i = 0;
    char ch;

    while (password[i] != '\0') {
        ch = password[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch + ENCRYPT_KEY;

            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            password[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + ENCRYPT_KEY;

            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            password[i] = ch;
        }

        i++;
    }
}

/*
 * Function to decrypt the password using Caesar cipher mechanism
 */
void decrypt_password(char password[]) {
    int i = 0;
    char ch;

    while (password[i] != '\0') {
        ch = password[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch - ENCRYPT_KEY;

            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }

            password[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - ENCRYPT_KEY;

            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }

            password[i] = ch;
        }

        i++;
    }
}

int main() {
    char password[PASSWORD_LENGTH_MAX];
    char choice;
    
    printf("Welcome to the Password Manager!\n");
    printf("Enter 'e' to encrypt a password and 'd' to decrypt a password: ");
    scanf("%c", &choice);
    
    if (choice == 'e') {
        printf("Enter the password you want to encrypt: ");
        scanf("%s", password);

        encrypt_password(password);

        printf("The encrypted password is: %s\n", password);
    } else if (choice == 'd') {
        printf("Enter the password you want to decrypt: ");
        scanf("%s", password);

        decrypt_password(password);

        printf("The decrypted password is: %s\n", password);
    } else {
        printf("Invalid choice! Please enter 'e' or 'd'.\n");
    }

    return 0;
}