//Falcon-180B DATASET v1.0 Category: Password management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char *username;
    char *password;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Password list is full.\n");
        return;
    }

    int length = strlen(username) + strlen(password) + 2;
    char *entry = malloc(length);
    if (entry == NULL) {
        printf("Error: Out of memory.\n");
        return;
    }

    sprintf(entry, "%s:%s", username, password);
    passwords[num_passwords++] = (password_t) {
       .username = strdup(username),
       .password = strdup(entry)
    };

    printf("Password added successfully.\n");
}

void remove_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);

            for (int j = i; j < num_passwords - 1; j++) {
                passwords[j] = passwords[j + 1];
            }

            num_passwords--;

            printf("Password removed successfully.\n");
            return;
        }
    }

    printf("Password not found.\n");
}

void list_passwords() {
    printf("Username\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

void main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. List passwords\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter username: ");
                scanf("%s", username);

                printf("Enter password: ");
                scanf("%s", password);

                add_password(username, password);
                break;
            }

            case 2: {
                printf("Enter username: ");
                scanf("%s", username);

                remove_password(username);
                break;
            }

            case 3: {
                list_passwords();
                break;
            }

            case 4: {
                exit(0);
            }

            default: {
                printf("Invalid choice.\n");
            }
        }
    }
}