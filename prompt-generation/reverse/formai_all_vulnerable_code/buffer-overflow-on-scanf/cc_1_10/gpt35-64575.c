//FormAI DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20 // Maximum length of password
#define MAX_TRIES 5 // Maximum number of tries

struct Password { // Password structure
    char name[MAX_LENGTH];
    char code[MAX_LENGTH];
};

void encrypt(char *str) { // Encryption function
    for (int i = 0; i < strlen(str); i++) {
        str[i] += 3; // Shift each character by 3 places to the right
    }
}

void decrypt(char *str) { // Decryption function
    for (int i = 0; i < strlen(str); i++) {
        str[i] -= 3; // Shift each character by 3 places to the left
    }
}

int main() {
    int option;
    int tries = 0;
    int passwordCount = 0;
    struct Password passwords[10];

    printf("Welcome to the futuristic password manager!\n");

    do {
        printf("\n");
        printf("1. Add a new password\n");
        printf("2. View all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Quit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (passwordCount < 10) {
                    struct Password newPassword;
                    printf("\nEnter the name of the site: ");
                    scanf("%s", newPassword.name);
                    printf("Enter a password: ");
                    scanf("%s", newPassword.code);
                    encrypt(newPassword.code); // Encrypt password before storing
                    passwords[passwordCount++] = newPassword;
                    printf("\nPassword added successfully!\n");
                } else {
                    printf("\nYou can only store up to 10 passwords!\n");
                }
                break;
            case 2:
                if (passwordCount > 0) {
                    printf("\n");
                    for (int i = 0; i < passwordCount; i++) {
                        printf("%d. %s: ", i + 1, passwords[i].name);
                        decrypt(passwords[i].code); // Decrypt password before showing
                        printf("%s\n", passwords[i].code);
                        encrypt(passwords[i].code); // Encrypt password after showing
                    }
                } else {
                    printf("\nNo passwords have been added yet!\n");
                }
                break;
            case 3:
                if (passwordCount > 0) {
                    char searchName[MAX_LENGTH];
                    printf("\nEnter the name of the site: ");
                    scanf("%s", searchName);
                    printf("\n");
                    for (int i = 0; i < passwordCount; i++) {
                        if (strcmp(passwords[i].name, searchName) == 0) {
                            printf("Password for %s: ", passwords[i].name);
                            decrypt(passwords[i].code); // Decrypt password before showing
                            printf("%s\n", passwords[i].code);
                            encrypt(passwords[i].code); // Encrypt password after showing
                            break;
                        }
                        if (i == passwordCount - 1) {
                            printf("\nNo password found for %s!\n", searchName);
                        }
                    }
                } else {
                    printf("\nNo passwords have been added yet!\n");
                }
                break;
            case 4:
                printf("\nThank you for using the futuristic password manager!\n");
                break;
            default:
                printf("\nInvalid option! Please try again.\n");
                break;
        }

        if (tries++ >= MAX_TRIES) { // Quit if maximum number of tries exceeded
            printf("\nMaximum number of tries exceeded! Program terminated!\n");
            exit(0);
        }
    } while (option != 4);

    return 0; // End of program
}