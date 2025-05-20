//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50
#define DATA_FILE "passwords.txt"

typedef struct {
    char name[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwords[MAX_PASSWORDS];
int password_count = 0;

void load_passwords() {
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL) {
        perror("Failed to open data file");
        return;
    }

    while (fscanf(file, "%49s %49s", passwords[password_count].name, passwords[password_count].password) == 2) {
        password_count++;
    }

    fclose(file);
}

void save_passwords() {
    FILE *file = fopen(DATA_FILE, "w");
    if (file == NULL) {
        perror("Failed to open data file");
        return;
    }

    for (int i = 0; i < password_count; i++) {
        fprintf(file, "%s %s\n", passwords[i].name, passwords[i].password);
    }

    fclose(file);
}

void add_password() {
    if (password_count >= MAX_PASSWORDS) {
        printf("Password storage is full!\n");
        return;
    }

    char name[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Enter name for the password entry: ");
    scanf("%49s", name);
    printf("Enter password: ");
    scanf("%49s", password);

    strcpy(passwords[password_count].name, name);
    strcpy(passwords[password_count].password, password);
    password_count++;

    save_passwords();
    printf("Password added successfully!\n");
}

void retrieve_password() {
    char name[MAX_LENGTH];
    printf("Enter name of the password to retrieve: ");
    scanf("%49s", name);

    for (int i = 0; i < password_count; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("Password for %s: %s\n", name, passwords[i].password);
            return;
        }
    }

    printf("No password found for %s.\n", name);
}

void delete_password() {
    char name[MAX_LENGTH];
    printf("Enter name of the password to delete: ");
    scanf("%49s", name);

    for (int i = 0; i < password_count; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            for (int j = i; j < password_count - 1; j++) {
                passwords[j] = passwords[j + 1];
            }
            password_count--;
            save_passwords();
            printf("Password for %s deleted successfully!\n", name);
            return;
        }
    }

    printf("No password found for %s.\n", name);
}

void display_passwords() {
    if (password_count == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("Stored Passwords:\n");
    for (int i = 0; i < password_count; i++) {
        printf("%d. %s\n", i + 1, passwords[i].name);
    }
}

int main() {
    load_passwords();
    int choice;

    do {
        printf("\nPassword Management System\n");
        printf("1. Add Password\n");
        printf("2. Retrieve Password\n");
        printf("3. Delete Password\n");
        printf("4. Display All Passwords\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                retrieve_password();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                display_passwords();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}