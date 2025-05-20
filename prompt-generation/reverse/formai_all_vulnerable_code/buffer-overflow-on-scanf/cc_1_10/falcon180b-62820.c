//Falcon-180B DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    printf("Enter username: ");
    char *username = malloc(100 * sizeof(char));
    scanf("%s", username);

    printf("Enter password: ");
    char *password = malloc(100 * sizeof(char));
    scanf("%s", password);

    passwords[num_passwords].username = username;
    passwords[num_passwords].password = password;

    num_passwords++;
}

void remove_password() {
    printf("Enter username to remove: ");
    char *username = malloc(100 * sizeof(char));
    scanf("%s", username);

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);
            num_passwords--;
            return;
        }
    }

    printf("Username not found.\n");
}

void view_passwords() {
    printf("Username\tPassword\n");
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    printf("Password Manager\n");

    while (1) {
        printf("\n1. Add password\n2. Remove password\n3. View passwords\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                remove_password();
                break;
            case 3:
                view_passwords();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}