//Falcon-180B DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100
#define MAX_USERNAME_LENGTH 100

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_entry;

password_entry passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Too many passwords!\n");
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
            memset(passwords[i].username, 0, MAX_USERNAME_LENGTH);
            memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);
            num_passwords--;
            return;
        }
    }
    printf("Error: Password not found!\n");
}

void change_password(char* username, char* new_password) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            strcpy(passwords[i].password, new_password);
            printf("Password changed successfully!\n");
            return;
        }
    }
    printf("Error: Password not found!\n");
}

void print_passwords() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];

    do {
        printf("1. Add password\n2. Remove password\n3. Change password\n4. Print passwords\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                add_password(username, password);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                remove_password(username);
                break;
            case 3:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter new password: ");
                scanf("%s", new_password);
                change_password(username, new_password);
                break;
            case 4:
                print_passwords();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}