//Falcon-180B DATASET v1.0 Category: Password management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

struct Password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void addPassword(struct Password passwords[], int numPasswords, char* name, char* password) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("Error: Password already exists.\n");
            return;
        }
    }
    strcpy(passwords[numPasswords].name, name);
    strcpy(passwords[numPasswords].password, password);
    numPasswords++;
}

void deletePassword(struct Password passwords[], int numPasswords, char* name) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            for (int j = i; j < numPasswords - 1; j++) {
                strcpy(passwords[j].name, passwords[j + 1].name);
                strcpy(passwords[j].password, passwords[j + 1].password);
            }
            numPasswords--;
            break;
        }
    }
}

void changePassword(struct Password passwords[], int numPasswords, char* name, char* newPassword) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            strcpy(passwords[i].password, newPassword);
            break;
        }
    }
}

void printPasswords(struct Password passwords[], int numPasswords) {
    for (int i = 0; i < numPasswords; i++) {
        printf("Name: %s, Password: %s\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    struct Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    while (1) {
        printf("1. Add Password\n2. Delete Password\n3. Change Password\n4. Print Passwords\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_PASSWORD_LENGTH], password[MAX_PASSWORD_LENGTH];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter password: ");
                scanf("%s", password);
                addPassword(passwords, numPasswords, name, password);
                break;
            }
            case 2: {
                char name[MAX_PASSWORD_LENGTH];
                printf("Enter name: ");
                scanf("%s", name);
                deletePassword(passwords, numPasswords, name);
                break;
            }
            case 3: {
                char name[MAX_PASSWORD_LENGTH], newPassword[MAX_PASSWORD_LENGTH];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter new password: ");
                scanf("%s", newPassword);
                changePassword(passwords, numPasswords, name, newPassword);
                break;
            }
            case 4: {
                printPasswords(passwords, numPasswords);
                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}