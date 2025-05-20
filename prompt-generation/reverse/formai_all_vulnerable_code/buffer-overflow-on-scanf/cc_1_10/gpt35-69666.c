//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

struct Password {
    char website[MAX_LEN];
    char username[MAX_LEN];
    char password[MAX_LEN];
    struct Password* next;
};

struct Password* password_list = NULL;

void add_password(struct Password* password) {
    if (password_list == NULL) {
        password_list = password;
        return;
    }

    struct Password* current_password = password_list;
    while (current_password->next != NULL) {
        current_password = current_password->next;
    }

    current_password->next = password;
}

void print_passwords() {
    struct Password* current_password = password_list;

    if (current_password == NULL) {
        printf("No passwords stored yet!\n");
        return;
    }

    while (current_password != NULL) {
        printf("Website: %s\n", current_password->website);
        printf("Username: %s\n", current_password->username);
        printf("Password: %s\n", current_password->password);
        printf("\n");
        current_password = current_password->next; 
    }

}

void delete_password(char* website) {
    struct Password* current_password = password_list;
    struct Password* previous_password = NULL;

    while (current_password != NULL) {
        if (strcmp(current_password->website, website) == 0) {
            if (previous_password == NULL) {
                password_list = current_password->next;
            } else {
                previous_password->next = current_password->next;
            }
            free(current_password);
            return;
        }

        previous_password = current_password;
        current_password = current_password->next;
    }

    printf("Password for %s not found!\n", website);
}
 
void clear_passwords() {
    struct Password* current_password = password_list;
    struct Password* next_password = NULL;

    while (current_password != NULL) {
        next_password = current_password->next;
        free(current_password);
        current_password = next_password;
    }

    password_list = NULL;
}

void get_password(char* website) {
    struct Password* current_password = password_list;
    while (current_password != NULL) {
        if (strcmp(current_password->website, website) == 0) {
            printf("Website: %s\n", current_password->website);
            printf("Username: %s\n", current_password->username);
            printf("Password: %s\n", current_password->password);
            printf("\n");
            return;
        }
        current_password = current_password->next;
    }

    printf("Password for %s not found!\n", website);
}

int main() {
    int choice;
    char website[MAX_LEN];
    char username[MAX_LEN];
    char password[MAX_LEN];
    struct Password* password_entry;

    printf("Welcome to the password management system!\n");
    while (1) {
        printf("Please choose an option:\n");
        printf("1. Add a password\n");
        printf("2. Get a password\n");
        printf("3. Delete a password\n");
        printf("4. Clear all passwords\n");
        printf("5. Print all passwords\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                password_entry = (struct Password*) malloc(sizeof(struct Password));
                printf("Enter website: ");
                scanf("%s", password_entry->website);
                printf("Enter username: ");
                scanf("%s", password_entry->username);
                printf("Enter password: ");
                scanf("%s", password_entry->password);
                add_password(password_entry);
                printf("\nPassword added successfully!\n\n");
                break;

            case 2:
                printf("Enter website: ");
                scanf("%s", website);
                get_password(website);
                break;

            case 3:
                printf("Enter website: ");
                scanf("%s", website);
                delete_password(website);
                break;

            case 4:
                clear_passwords();
                printf("All passwords cleared!\n");
                break;

            case 5:
                printf("Stored passwords:\n");
                print_passwords();
                break;

            case 6:
                clear_passwords();
                printf("Thank you for using the password management system!\n");
                exit(0);

            default:
                printf("Invalid option entered!\n");
                break;
        }
    }

    return 0;
}