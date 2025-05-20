//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct PasswordRecord {
    char site[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    struct PasswordRecord* next;
} PasswordRecord;

PasswordRecord* head = NULL;

void add_password(const char* site, const char* username, const char* password) {
    PasswordRecord* new_record = (PasswordRecord*)malloc(sizeof(PasswordRecord));
    if (!new_record) {
        perror("Failed to allocate memory");
        return;
    }

    strncpy(new_record->site, site, MAX_LENGTH);
    strncpy(new_record->username, username, MAX_LENGTH);
    strncpy(new_record->password, password, MAX_LENGTH);
    new_record->next = head;
    head = new_record;
    printf("Password added successfully!\n");
}

void view_passwords() {
    if (head == NULL) {
        printf("No passwords stored.\n");
        return;
    }

    PasswordRecord* current = head;
    printf("Stored Passwords:\n");
    while (current != NULL) {
        printf("Site: %s, Username: %s, Password: %s\n", current->site, current->username, current->password);
        current = current->next;
    }
}

void delete_password(const char* site) {
    PasswordRecord** current = &head;
    while (*current) {
        if (strcmp((*current)->site, site) == 0) {
            PasswordRecord* to_delete = *current;
            *current = (*current)->next;
            free(to_delete);
            printf("Password for site '%s' deleted successfully.\n", site);
            return;
        }
        current = &(*current)->next;
    }
    printf("Password for site '%s' not found.\n", site);
}

void clear_passwords() {
    PasswordRecord* current = head;
    PasswordRecord* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("All passwords cleared.\n");
}

void display_menu() {
    printf("\nPassword Manager:\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Clear All Passwords\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char site[MAX_LENGTH], username[MAX_LENGTH], password[MAX_LENGTH];

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline

        switch (choice) {
            case 1:
                printf("Enter site: ");
                fgets(site, MAX_LENGTH, stdin);
                strtok(site, "\n"); // remove newline
                printf("Enter username: ");
                fgets(username, MAX_LENGTH, stdin);
                strtok(username, "\n"); // remove newline
                printf("Enter password: ");
                fgets(password, MAX_LENGTH, stdin);
                strtok(password, "\n"); // remove newline
                add_password(site, username, password);
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                printf("Enter the site to delete: ");
                fgets(site, MAX_LENGTH, stdin);
                strtok(site, "\n"); // remove newline
                delete_password(site);
                break;
            case 4:
                clear_passwords();
                break;
            case 5:
                clear_passwords(); // Clear before exiting
                printf("Exiting Password Manager. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}