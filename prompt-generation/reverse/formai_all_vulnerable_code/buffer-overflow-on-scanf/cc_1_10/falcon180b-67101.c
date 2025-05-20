//Falcon-180B DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LEN 20

typedef struct {
    char password[MAX_PASSWORD_LEN];
    int used;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void generatePassword(Password *pw) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+=[]{}\\|;:'\",.<>/?";
    int charsetLen = strlen(charset);
    int i = 0;

    while (i < MAX_PASSWORD_LEN) {
        int randIndex = rand() % charsetLen;
        pw->password[i++] = charset[randIndex];
    }

    pw->password[i] = '\0';
    pw->used = 1;
}

int addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return 1;
    }

    Password pw;
    generatePassword(&pw);
    strcpy(passwords[numPasswords].password, pw.password);
    numPasswords++;

    printf("Password added successfully.\n");
    return 0;
}

int deletePassword(char *password) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].password, password) == 0) {
            passwords[i].used = 0;
            printf("Password deleted successfully.\n");
            return 0;
        }
    }

    printf("Password not found.\n");
    return 1;
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            printf("Enter password to delete: ");
            char password[MAX_PASSWORD_LEN];
            scanf("%s", password);
            deletePassword(password);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}