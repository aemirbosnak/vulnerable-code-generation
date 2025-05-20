//Falcon-180B DATASET v1.0 Category: Password management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }
    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);
    num_passwords++;
}

void delete_password(char *username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);
            memmove(&passwords[i], &passwords[i+1], (num_passwords - i - 1) * sizeof(Password));
            num_passwords--;
            return;
        }
    }
    printf("Error: Password not found.\n");
}

void change_password(char *username, char *new_password) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].password);
            passwords[i].password = strdup(new_password);
            return;
        }
    }
    printf("Error: Password not found.\n");
}

void print_passwords() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int choice;

    while (1) {
        printf("1. Add password\n2. Delete password\n3. Change password\n4. Print passwords\n5. Exit\n");
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
            delete_password(username);
            break;
        case 3:
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter new password: ");
            scanf("%s", password);
            change_password(username, password);
            break;
        case 4:
            print_passwords();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}