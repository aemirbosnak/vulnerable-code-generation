//Falcon-180B DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);

    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;
}

void view_passwords() {
    printf("Username\t\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t\t%s\n", passwords[i].username, passwords[i].password);
    }
}

void delete_password() {
    printf("Enter username to delete: ");
    char username[MAX_PASSWORD_LENGTH];
    scanf("%s", username);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            for (int j = i; j < num_passwords - 1; j++) {
                strcpy(passwords[j].username, passwords[j + 1].username);
                strcpy(passwords[j].password, passwords[j + 1].password);
            }
            num_passwords--;
            break;
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add password\n2. View passwords\n3. Delete password\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            view_passwords();
            break;
        case 3:
            delete_password();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}