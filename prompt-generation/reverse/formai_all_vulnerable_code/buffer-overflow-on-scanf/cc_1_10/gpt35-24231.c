//FormAI DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
int num_passwords = 0;

void menu() {
    printf("Password Manager\n");
    printf("----------------\n");
    printf("1. Add password\n");
    printf("2. View passwords\n");
    printf("3. Delete password\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}

void add_password() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);
    if (num_passwords < MAX_PASSWORDS) {
        strcpy(passwords[num_passwords], password);
        num_passwords++;
        printf("Password added!\n");
    } else {
        printf("Max passwords reached!\n");
    }
}

void view_passwords() {
    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%d. %s\n", i + 1, passwords[i]);
    }
}

void delete_password() {
    int password_num;
    printf("Enter password number to delete: ");
    scanf("%d", &password_num);
    if (password_num >= 1 && password_num <= num_passwords) {
        for (int i = password_num - 1; i < num_passwords - 1; i++) {
            strcpy(passwords[i], passwords[i + 1]);
        }
        num_passwords--;
        printf("Password deleted!\n");
    } else {
        printf("Invalid password number!\n");
    }
}

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_password(); break;
            case 2: view_passwords(); break;
            case 3: delete_password(); break;
            case 4: printf("Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}