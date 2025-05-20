//Falcon-180B DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERS];
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int num_passwords;
} User;

void create_user(User *user) {
    printf("Enter username: ");
    scanf("%s", user->username);
    user->num_passwords = 0;
}

void add_password(User *user) {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);
    strcpy(user->passwords[user->num_passwords], password);
    user->num_passwords++;
}

void delete_password(User *user) {
    int i;
    printf("Enter password number to delete: ");
    scanf("%d", &i);
    if (i >= 0 && i < user->num_passwords) {
        user->num_passwords--;
        for (int j = i; j < user->num_passwords; j++) {
            strcpy(user->passwords[j], user->passwords[j+1]);
        }
    }
}

void change_password(User *user) {
    int i;
    printf("Enter password number to change: ");
    scanf("%d", &i);
    if (i >= 0 && i < user->num_passwords) {
        printf("Enter new password: ");
        scanf("%s", user->passwords[i]);
    }
}

void display_passwords(User *user) {
    printf("Passwords for %s:\n", user->username);
    for (int i = 0; i < user->num_passwords; i++) {
        printf("%d. %s\n", i+1, user->passwords[i]);
    }
}

int main() {
    User user;
    create_user(&user);

    while (1) {
        printf("\n1. Add password\n2. Delete password\n3. Change password\n4. Display passwords\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password(&user);
                break;
            case 2:
                delete_password(&user);
                break;
            case 3:
                change_password(&user);
                break;
            case 4:
                display_passwords(&user);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}