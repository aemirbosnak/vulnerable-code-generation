//Falcon-180B DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

// Define structure for password
typedef struct {
    char username[20];
    char password[20];
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

void remove_password() {
    printf("Enter username to remove: ");
    char username[20];
    scanf("%s", username);

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            break;
        }
    }

    if (i == num_passwords) {
        printf("Username not found.\n");
    } else {
        num_passwords--;
        i = 0;
        while (i < num_passwords) {
            passwords[i] = passwords[i+1];
            i++;
        }
    }
}

void search_password() {
    printf("Enter username to search: ");
    char username[20];
    scanf("%s", username);

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            printf("Password: %s\n", passwords[i].password);
            break;
        }
    }

    if (i == num_passwords) {
        printf("Username not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Search password\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                remove_password();
                break;
            case 3:
                search_password();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}