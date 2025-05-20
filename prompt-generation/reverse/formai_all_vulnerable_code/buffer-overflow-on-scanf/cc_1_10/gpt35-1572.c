//FormAI DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char description[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

int menu() {
    int choice;
    printf("\n1. Add password\n");
    printf("2. Display password\n");
    printf("3. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice); getchar();
    return choice;
}

void add_password(password_t passwords[], int *num_passwords) {
    if (*num_passwords == MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached!\n");
        return;
    }
    printf("\nEnter password description: ");
    fgets(passwords[*num_passwords].description, MAX_PASSWORD_LENGTH, stdin);
    passwords[*num_passwords].description[strcspn(passwords[*num_passwords].description, "\n")] = '\0'; // Remove trailing newline character
    printf("Enter password: ");
    fgets(passwords[*num_passwords].password, MAX_PASSWORD_LENGTH, stdin);
    passwords[*num_passwords].password[strcspn(passwords[*num_passwords].password, "\n")] = '\0'; // Remove trailing newline character
    printf("Password added successfully!\n");
    (*num_passwords)++;
}

void display_passwords(password_t passwords[], int num_passwords) {
    if (num_passwords == 0) {
        printf("No passwords to display!\n");
        return;
    }
    printf("\nList of passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%d. Description: %s    Password: %s\n", i+1, passwords[i].description, passwords[i].password);
    }
}

int main() {
    printf("Welcome to the Password Manager!\n\n");

    password_t passwords[MAX_PASSWORDS]; // Array to store passwords
    int num_passwords = 0; // Number of passwords stored in the array

    int choice;
    do {
        choice = menu();
        switch(choice) {
            case 1: // Add password
                add_password(passwords, &num_passwords);
                break;
            case 2: // Display passwords
                display_passwords(passwords, num_passwords);
                break;
            case 3: // Exit
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}