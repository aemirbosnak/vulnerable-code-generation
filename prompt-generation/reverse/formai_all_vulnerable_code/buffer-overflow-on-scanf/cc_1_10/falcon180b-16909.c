//Falcon-180B DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

int find_password(char* username) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }

    return -1;
}

void display_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("%s - %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        if (strcmp(username, "exit") == 0) {
            break;
        }

        printf("Enter password: ");
        scanf("%s", password);

        add_password(username, password);
    }

    int choice;

    while (1) {
        printf("\n1. Display passwords\n2. Search for password\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            display_passwords();
            break;
        case 2:
            printf("Enter username: ");
            scanf("%s", username);

            int index = find_password(username);

            if (index == -1) {
                printf("Password not found.\n");
            } else {
                printf("Password: %s\n", passwords[index].password);
            }

            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}