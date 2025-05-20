//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 256
#define FILE_NAME "passwords.txt"

typedef struct {
    int id;
    char name[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

void add_password();
void view_passwords();
void delete_password();
void display_menu();
int load_passwords(PasswordEntry passwords[]);
void save_passwords(PasswordEntry passwords[], int count);

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                printf("Exiting Password Manager. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}

void display_menu() {
    printf("\n=== Password Manager ===\n");
    printf("1. Add a Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete a Password\n");
    printf("4. Exit\n");
}

void add_password() {
    PasswordEntry entry;
    FILE *file;
    int count = load_passwords(NULL);
    
    entry.id = count + 1;
    printf("Enter the name of the account: ");
    scanf("%s", entry.name);
    printf("Enter the password: ");
    scanf("%s", entry.password);

    file = fopen(FILE_NAME, "a");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d %s %s\n", entry.id, entry.name, entry.password);
    fclose(file);
    printf("Password added successfully!\n");
}

void view_passwords() {
    PasswordEntry passwords[MAX_PASSWORDS];
    FILE *file;
    int count, i;

    count = load_passwords(passwords);
    
    if (count == 0) {
        printf("No passwords stored yet!\n");
        return;
    }

    printf("Stored Passwords:\n");
    for (i = 0; i < count; i++) {
        printf("ID: %d | Account: %s | Password: %s\n", passwords[i].id, passwords[i].name, passwords[i].password);
    }
}

void delete_password() {
    PasswordEntry passwords[MAX_PASSWORDS];
    FILE *file;
    int count, id, i, found = 0;

    count = load_passwords(passwords);
    if (count == 0) {
        printf("No passwords to delete!\n");
        return;
    }

    printf("Enter the ID of the password to delete: ");
    scanf("%d", &id);

    file = fopen(FILE_NAME, "w");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < count; i++) {
        if (passwords[i].id != id) {
            fprintf(file, "%d %s %s\n", passwords[i].id, passwords[i].name, passwords[i].password);
        } else {
            found = 1;
        }
    }

    fclose(file);
    if (found) {
        printf("Password with ID %d has been deleted.\n", id);
    } else {
        printf("No password found with ID %d.\n", id);
    }
}

int load_passwords(PasswordEntry passwords[]) {
    FILE *file;
    int count = 0;

    file = fopen(FILE_NAME, "r");
    if (!file) {
        return 0; // File doesn't exist yet
    }

    while (fscanf(file, "%d %s %s", &passwords[count].id, passwords[count].name, passwords[count].password) != EOF) {
        count++;
        if (count >= MAX_PASSWORDS) {
            break;
        }
    }

    fclose(file);
    return count;
}