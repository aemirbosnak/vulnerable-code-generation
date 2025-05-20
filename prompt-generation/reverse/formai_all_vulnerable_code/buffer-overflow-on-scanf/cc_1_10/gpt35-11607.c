//FormAI DATASET v1.0 Category: Password management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50

struct Password {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

struct Password passwords[MAX_PASSWORDS];

int num_passwords = 0;

void add_password() {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    struct Password new_password;

    printf("Enter website: ");
    fgets(new_password.website, MAX_LENGTH, stdin);
    printf("Enter username: ");
    fgets(new_password.username, MAX_LENGTH, stdin);
    printf("Enter password: ");
    fgets(new_password.password, MAX_LENGTH, stdin);

    passwords[num_passwords++] = new_password;

    printf("Password added successfully!\n");
}

void list_passwords() {
    if (num_passwords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("Website\t\tUsername\t\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t\t%s\t\t%s", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

void search_password() {
    char website[MAX_LENGTH];
    printf("Enter website: ");
    fgets(website, MAX_LENGTH, stdin);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            printf("Website: %s\n", passwords[i].website);
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }

    printf("No password found for website %s.\n", website);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add password\n");
        printf("2. List passwords\n");
        printf("3. Search password\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                list_passwords();
                break;
            case 3:
                search_password();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}