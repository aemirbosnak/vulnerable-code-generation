//FormAI DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct password_manager {
    char site_name[MAX];
    char username[MAX];
    char password[MAX];
} passwords[10];

int password_count = 0;

void create_new_password() {
    struct password_manager password;
    printf("\nEnter site name: ");
    fgets(password.site_name, MAX, stdin);
    printf("Enter username: ");
    fgets(password.username, MAX, stdin);
    printf("Enter password: ");
    fgets(password.password, MAX, stdin);

    int len = strlen(password.site_name);
    if (password.site_name[len - 1] == '\n') {
        password.site_name[len - 1] = '\0';
    }
    len = strlen(password.username);
    if (password.username[len - 1] == '\n') {
        password.username[len - 1] = '\0';
    }
    len = strlen(password.password);
    if (password.password[len - 1] == '\n') {
        password.password[len - 1] = '\0';
    }

    passwords[password_count++] = password;
    printf("\nNew password created successfully!\n");
}

void display_passwords() {
    if (password_count == 0) {
        printf("\nNo passwords have been added yet.\n");
    } else {
        printf("\nSite Name\t\tUsername\t\tPassword\n");
        for (int i = 0; i < password_count; ++i) {
            printf("%s\t\t%s\t\t%s\n", passwords[i].site_name, passwords[i].username, passwords[i].password);
        }
    }
}

void search_password() {
    if (password_count == 0) {
        printf("\nNo passwords have been added yet.\n");
    } else {
        char site_name[MAX];
        printf("\nEnter site name to search for: ");
        fgets(site_name, MAX, stdin);

        int len = strlen(site_name);
        if (site_name[len - 1] == '\n') {
            site_name[len - 1] = '\0';
        }

        int found = 0;
        for (int i = 0; i < password_count; ++i) {
            if (strcmp(passwords[i].site_name, site_name) == 0) {
                printf("\nSite Name\t\tUsername\t\tPassword\n");
                printf("%s\t\t%s\t\t%s\n", passwords[i].site_name, passwords[i].username, passwords[i].password);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\nPassword for site '%s' not found.\n", site_name);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Create new password\n");
        printf("2. Display all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Exit\n");
        printf("\nEnter your choice (1, 2, 3, or 4): ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            create_new_password();
            break;
        case 2:
            display_passwords();
            break;
        case 3:
            search_password();
            break;
        case 4:
            printf("\nExiting...\n");
            exit(0);
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}