//Falcon-180B DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 16

typedef struct {
    char username[32];
    char password[PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;

    printf("Password added successfully.\n");
}

int find_password(char *username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void print_passwords() {
    printf("Username\tPassword\n");
    printf("-------------------------------------------------\n");
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char username[32];
    char password[PASSWORD_LENGTH];
    int choice;
    int i;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. Find Password\n");
        printf("3. Print Passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
            i = find_password(username);
            if (i == -1) {
                printf("Password not found.\n");
            } else {
                printf("Password: %s\n", passwords[i].password);
            }
            break;
        case 3:
            print_passwords();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}