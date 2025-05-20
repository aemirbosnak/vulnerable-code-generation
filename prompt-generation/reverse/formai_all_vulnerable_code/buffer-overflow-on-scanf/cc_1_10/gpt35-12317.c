//FormAI DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

struct password {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int num_passwords = 0;
struct password passwords[MAX_PASSWORDS];

void add_password() {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Unable to add password, maximum number of passwords has been reached.\n");
        return;
    }

    printf("\n=== Adding New Password ===\n");

    printf("Website: ");
    scanf("%s", passwords[num_passwords].website);

    printf("Username: ");
    scanf("%s", passwords[num_passwords].username);

    printf("Password: ");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;
}

void remove_password() {
    if (num_passwords <= 0) {
        printf("Error: Unable to remove password, there are no passwords stored.\n");
        return;
    }

    printf("\n=== Removing Password ===\n");

    printf("Enter website: ");
    char website[MAX_PASSWORD_LENGTH];
    scanf("%s", website);

    int index_to_remove = -1;

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            index_to_remove = i;
            break;
        }
    }

    if (index_to_remove == -1) {
        printf("Error: Unable to find password for website: %s\n", website);
    } else {
        for (int i = index_to_remove; i < num_passwords - 1; i++) {
            passwords[i] = passwords[i + 1];
        }
        num_passwords--;
        printf("Password removed for website: %s\n", website);
    }
}

void list_passwords() {
    printf("\n=== Stored Passwords ===\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("Website: %s\n", passwords[i].website);
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
        printf("---\n");
    }
}

int main() {
    int option = -1;

    printf("Welcome to the Password Manager!\n");
    printf("Please choose an option from the menu below:\n");

    while (option != 0) {
        printf("\n");
        printf("   1) Add Password\n");
        printf("   2) Remove Password\n");
        printf("   3) List Passwords\n");
        printf("   0) Exit\n");
        printf("Option: ");

        scanf("%d", &option);

        switch (option) {
            case 1:
                add_password();
                break;
            case 2:
                remove_password();
                break;
            case 3:
                list_passwords();
                break;
            case 0:
                printf("Thank you for using Password Manager.\n");
                break;
            default:
                printf("Error: Invalid option.\n");
                break;
        }
    }

    return 0;
}