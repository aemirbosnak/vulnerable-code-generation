//Falcon-180B DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void delete_password() {
    int index;

    printf("Enter index of password to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_passwords) {
        num_passwords--;

        for (int i = index; i < num_passwords; i++) {
            strcpy(passwords[i].username, passwords[i+1].username);
            strcpy(passwords[i].password, passwords[i+1].password);
        }
    } else {
        printf("Invalid index.\n");
    }
}

void change_password() {
    char username[MAX_PASSWORD_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];
    int index;

    printf("Enter username: ");
    scanf("%s", username);

    index = -1;

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            index = i;
            break;
        }
    }

    if (index >= 0) {
        printf("Enter new password: ");
        scanf("%s", new_password);

        strcpy(passwords[index].password, new_password);
    } else {
        printf("Password not found.\n");
    }
}

void view_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s : %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Change password\n");
        printf("4. View passwords\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                delete_password();
                break;
            case 3:
                change_password();
                break;
            case 4:
                view_passwords();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}