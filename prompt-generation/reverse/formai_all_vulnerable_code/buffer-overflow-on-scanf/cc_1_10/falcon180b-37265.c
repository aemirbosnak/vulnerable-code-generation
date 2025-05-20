//Falcon-180B DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

//Password struct
typedef struct {
    char username[50];
    char password[50];
} Password;

//Password manager struct
typedef struct {
    Password passwords[MAX_PASSWORDS];
    int num_passwords;
} PasswordManager;

//Function to initialize password manager
void init_password_manager(PasswordManager* manager) {
    manager->num_passwords = 0;
}

//Function to add a password to the manager
void add_password(PasswordManager* manager, char* username, char* password) {
    if (manager->num_passwords >= MAX_PASSWORDS) {
        printf("Error: Password manager is full.\n");
        return;
    }

    strcpy(manager->passwords[manager->num_passwords].username, username);
    strcpy(manager->passwords[manager->num_passwords].password, password);

    manager->num_passwords++;
}

//Function to remove a password from the manager
void remove_password(PasswordManager* manager, char* username) {
    int i;

    for (i = 0; i < manager->num_passwords; i++) {
        if (strcmp(manager->passwords[i].username, username) == 0) {
            memmove(&manager->passwords[i], &manager->passwords[i+1], sizeof(Password) * (manager->num_passwords - i - 1));
            manager->num_passwords--;
            break;
        }
    }
}

//Function to retrieve a password from the manager
Password* get_password(PasswordManager* manager, char* username) {
    int i;

    for (i = 0; i < manager->num_passwords; i++) {
        if (strcmp(manager->passwords[i].username, username) == 0) {
            return &manager->passwords[i];
        }
    }

    return NULL;
}

//Function to print all passwords in the manager
void print_passwords(PasswordManager* manager) {
    int i;

    for (i = 0; i < manager->num_passwords; i++) {
        printf("Username: %s\nPassword: %s\n\n", manager->passwords[i].username, manager->passwords[i].password);
    }
}

int main() {
    PasswordManager manager;
    char username[50];
    char password[50];

    init_password_manager(&manager);

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        add_password(&manager, username, password);
    }

    return 0;
}