//FormAI DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

// struct to hold a password and its associated user
typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

// function declarations
void add_password(Password *passwords, int *num_passwords);
void update_password(Password *passwords, int num_passwords);
void delete_password(Password *passwords, int *num_passwords);
void print_passwords(Password *passwords, int num_passwords);

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    int choice;
    
    do {
        printf("\nChoose an option:\n");
        printf("1. Add a new password\n");
        printf("2. Update a password\n");
        printf("3. Delete a password\n");
        printf("4. Print all passwords\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password(passwords, &num_passwords);
                break;
            case 2:
                update_password(passwords, num_passwords);
                break;
            case 3: 
                delete_password(passwords, &num_passwords);
                break;
            case 4:
                print_passwords(passwords, num_passwords);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void add_password(Password *passwords, int *num_passwords) {
    if (*num_passwords >= MAX_PASSWORDS) {
        printf("No more passwords can be added.\n");
        return;
    }

    printf("\nEnter the username: ");
    scanf("%s", passwords[*num_passwords].username);

    printf("Enter the password: ");
    scanf("%s", passwords[*num_passwords].password);

    printf("Password added.\n");
    (*num_passwords)++;
}

void update_password(Password *passwords, int num_passwords) {
    char username[MAX_PASSWORD_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];
    int found = 0;

    printf("\nEnter the username of the password to update: ");
    scanf("%s", username);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Enter the new password: ");
            scanf("%s", new_password);

            strcpy(passwords[i].password, new_password);
            printf("Password updated.\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Password not found.\n");
    }
}

void delete_password(Password *passwords, int *num_passwords) {
    char username[MAX_PASSWORD_LENGTH];
    int found = 0;

    printf("\nEnter the username of the password to delete: ");
    scanf("%s", username);

    for (int i = 0; i < *num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            for (int j = i; j < *num_passwords - 1; j++) {
                strcpy(passwords[j].username, passwords[j + 1].username);
                strcpy(passwords[j].password, passwords[j + 1].password);
            }

            (*num_passwords)--;
            printf("Password deleted.\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Password not found.\n");
    }
}

void print_passwords(Password *passwords, int num_passwords) {
    printf("\nPasswords:\n");

    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}