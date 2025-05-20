//Falcon-180B DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH + 1];
    char username[MAX_PASSWORD_LENGTH + 1];
} password_t;

int num_passwords = 0;
password_t passwords[MAX_PASSWORDS];

void add_password(char *password, char *username) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].password, password);
    strcpy(passwords[num_passwords].username, username);
    num_passwords++;
}

void list_passwords() {
    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%d. %s (%s)\n", i + 1, passwords[i].password, passwords[i].username);
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    char username[MAX_PASSWORD_LENGTH + 1];

    while (1) {
        printf("Enter an action (add, list, exit): ");
        scanf("%s", password);

        if (strcmp(password, "add") == 0) {
            printf("Enter password: ");
            scanf("%s", password);

            printf("Enter username: ");
            scanf("%s", username);

            add_password(password, username);
        } else if (strcmp(password, "list") == 0) {
            list_passwords();
        } else if (strcmp(password, "exit") == 0) {
            break;
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}