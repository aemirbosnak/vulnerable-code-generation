//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int count = 0;

void display_menu() {
    printf("\nPassword Manager\n");
    printf("------------------\n");
    printf("1. Add Password\n");
    printf("2. Delete Password\n");
    printf("3. Search Password\n");
    printf("4. Display All Passwords\n");
    printf("5. Quit\n");
}

void add_password(char *username, char *password) {
    if (count >= MAX_PASSWORDS) {
        printf("Password Manager is full.\n");
        return;
    }
    strcpy(passwords[count].username, username);
    strcpy(passwords[count].password, password);
    count++;
}

void delete_password(char *username) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            for (int j = i; j < count - 1; j++) {
                strcpy(passwords[j].username, passwords[j + 1].username);
                strcpy(passwords[j].password, passwords[j + 1].password);
            }
            count--;
            printf("Password deleted successfully.\n");
            return;
        }
    }
    printf("Username not found.\n");
}

void search_password(char *username) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }
    printf("Username not found.\n");
}

void display_all_passwords() {
    int i;
    printf("Usernames and Passwords:\n");
    for (i = 0; i < count; i++) {
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
    }
}

int main() {
    char choice, username[MAX_PASSWORD_LENGTH], password[MAX_PASSWORD_LENGTH];

    while (1) {
        display_menu();
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                add_password(username, password);
                break;
            case '2':
                printf("Enter username to delete: ");
                scanf("%s", username);
                delete_password(username);
                break;
            case '3':
                printf("Enter username to search: ");
                scanf("%s", username);
                search_password(username);
                break;
            case '4':
                display_all_passwords();
                break;
            case '5':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}