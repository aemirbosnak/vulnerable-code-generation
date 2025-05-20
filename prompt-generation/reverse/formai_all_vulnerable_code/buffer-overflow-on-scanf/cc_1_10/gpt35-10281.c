//FormAI DATASET v1.0 Category: Password management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

struct PasswordManager {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

void encrypt(char *str) {
    // A simple encryption function that shifts the ASCII value of each character by 1
    for (int i = 0; i < strlen(str); i++) {
        str[i]++;
    }
}

void decrypt(char *str) {
    // The inverse function of the encryption function, shifts the ASCII value of each character by -1
    for (int i = 0; i < strlen(str); i++) {
        str[i]--;
    }
}

void savePassword(struct PasswordManager *passwords, int count) {
    printf("Enter website: ");
    scanf("%s", passwords[count].website);

    printf("Enter username: ");
    scanf("%s", passwords[count].username);

    printf("Enter password: ");
    scanf("%s", passwords[count].password);

    encrypt(passwords[count].password);
    printf("Password encrypted successfully.\n");

    printf("Password saved successfully!\n");
}

void viewPasswords(struct PasswordManager *passwords, int count) {
    for (int i = 0; i < count; i++) {
        printf("Website: %s\n", passwords[i].website);
        printf("Username: %s\n", passwords[i].username);
        decrypt(passwords[i].password);
        printf("Password: %s\n", passwords[i].password);
        encrypt(passwords[i].password);
        printf("\n");
    }
}

int main() {
    struct PasswordManager passwords[MAX_LENGTH];
    int count = 0;

    while (1) {
        printf("\n1. Save password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");

        int choice;
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                savePassword(passwords, count);
                count++;
                break;
            case 2:
                viewPasswords(passwords, count);
                break;
            case 3:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}