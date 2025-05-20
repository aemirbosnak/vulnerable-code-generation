//GEMINI-pro DATASET v1.0 Category: Password management ; Style: calm
// **Zenith Password Manager**

// Calmly securing your digital realm.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

// Serenity of data structures.
typedef struct Password {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

// Tranquility of functions.
void add_password(char* website, char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Tranquil warning: Password limit reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].website, website);
    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

void show_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("Website: %s\n", passwords[i].website);
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
        printf("\n");
    }
}

void search_password(char* query) {
    for (int i = 0; i < num_passwords; i++) {
        if (strstr(passwords[i].website, query) || strstr(passwords[i].username, query)) {
            printf("Website: %s\n", passwords[i].website);
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", passwords[i].password);
            printf("\n");
        }
    }
}

void delete_password(char* website) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            for (int j = i; j < num_passwords - 1; j++) {
                passwords[j] = passwords[j + 1];
            }
            num_passwords--;
            break;
        }
    }
}

int main() {
    // Serenity in action.
    printf("Welcome to the Zenith Password Manager.\n");
    printf("May your data be eternally calm.\n");

    int choice;
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char query[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("\nSerenity Menu:\n");
        printf("1. Add Password\n");
        printf("2. Show Passwords\n");
        printf("3. Search Password\n");
        printf("4. Delete Password\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter website: ");
            scanf(" %s", website);
            printf("Enter username: ");
            scanf(" %s", username);
            printf("Enter password: ");
            scanf(" %s", password);
            add_password(website, username, password);
            printf("Password added.\n");
            break;
        case 2:
            show_passwords();
            break;
        case 3:
            printf("Enter search query: ");
            scanf(" %s", query);
            search_password(query);
            break;
        case 4:
            printf("Enter website to delete: ");
            scanf(" %s", website);
            delete_password(website);
            printf("Password deleted.\n");
            break;
        case 5:
            printf("Thank you for using the Zenith Password Manager.\n");
            printf("May your digital tranquility be ever so.\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}