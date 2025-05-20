//FormAI DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

// Define a struct for storing passwords
typedef struct {
    char domain[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

// Define a struct for storing multiple passwords
typedef struct {
    Password passwords[MAX_PASSWORDS];
    int count;
} PasswordList;

// Function prototypes
void print_menu();
void add_password(PasswordList *list);
void delete_password(PasswordList *list);
void search_password(PasswordList list);
bool check_duplicate(PasswordList list, char *domain);

int main() {
    PasswordList password_list = { .count = 0 };

    while (true) {
        print_menu();

        char choice;
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': 
                add_password(&password_list);
                break;
            case '2':
                delete_password(&password_list);
                break;
            case '3':
                search_password(password_list);
                break;
            case '4':
                printf("Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("\n-- Password Manager --\n\n");
    printf("1. Add new password\n");
    printf("2. Delete password\n");
    printf("3. Search for password\n");
    printf("4. Quit\n");
}

void add_password(PasswordList *list) {
    if (list->count == MAX_PASSWORDS) {
        printf("Sorry, the password list is full!\n");
        return;
    }

    printf("Enter domain: ");
    scanf("%s", list->passwords[list->count].domain);

    if (check_duplicate(*list, list->passwords[list->count].domain)) {
        printf("A password for this domain already exists!\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", list->passwords[list->count].username);

    printf("Enter password: ");
    scanf("%s", list->passwords[list->count].password);

    printf("Password added successfully!\n");
    list->count++;
}

void delete_password(PasswordList *list) {
    char domain[MAX_PASSWORD_LENGTH];
    printf("Enter domain to delete: ");
    scanf("%s", domain);

    int i;
    for (i = 0; i < list->count; i++) {
        if (strcmp(list->passwords[i].domain, domain) == 0) {
            // Shift all following passwords back by one position
            int j;
            for (j = i; j < list->count - 1; j++) {
                list->passwords[j] = list->passwords[j + 1];
            }

            list->count--;
            printf("Password deleted successfully!\n");
            return;
        }
    }

    printf("No password found for domain %s!\n", domain);
}

void search_password(PasswordList list) {
    char domain[MAX_PASSWORD_LENGTH];
    printf("Enter domain to search: ");
    scanf("%s", domain);

    int i;
    for (i = 0; i < list.count; i++) {
        if (strcmp(list.passwords[i].domain, domain) == 0) {
            printf("Domain: %s\n", list.passwords[i].domain);
            printf("Username: %s\n", list.passwords[i].username);
            printf("Password: %s\n", list.passwords[i].password);
            return;
        }
    }

    printf("No password found for domain %s!\n", domain);
}

bool check_duplicate(PasswordList list, char *domain) {
    int i;
    for (i = 0; i < list.count; i++) {
        if (strcmp(list.passwords[i].domain, domain) == 0) {
            return true;
        }
    }

    return false;
}