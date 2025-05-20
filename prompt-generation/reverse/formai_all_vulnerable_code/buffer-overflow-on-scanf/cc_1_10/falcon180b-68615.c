//Falcon-180B DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 64
#define MAX_USERNAME_LENGTH 64
#define MAX_USER_LENGTH 64

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_entry;

password_entry passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Password list is full.\n");
        return;
    }
    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

void remove_password(char* username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            strcpy(passwords[i].username, "");
            strcpy(passwords[i].password, "");
            num_passwords--;
            printf("Password removed.\n");
            return;
        }
    }
    printf("Error: Password not found.\n");
}

void list_passwords() {
    int i;
    if (num_passwords == 0) {
        printf("No passwords found.\n");
        return;
    }
    printf("Passwords:\n");
    for (i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

void main() {
    char choice;
    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n2. Remove Password\n3. List Passwords\n4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter username: ");
                scanf("%s", passwords[num_passwords].username);
                printf("Enter password: ");
                scanf("%s", passwords[num_passwords].password);
                num_passwords++;
                break;
            case '2':
                printf("Enter username: ");
                scanf("%s", passwords[num_passwords-1].username);
                remove_password(passwords[num_passwords-1].username);
                break;
            case '3':
                list_passwords();
                break;
            case '4':
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }
}