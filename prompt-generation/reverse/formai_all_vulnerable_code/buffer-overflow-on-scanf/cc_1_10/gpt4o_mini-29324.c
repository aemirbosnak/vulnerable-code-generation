//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_TITLE_LENGTH 50
#define FILENAME "passwords.dat"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

void add_password();
void view_passwords();
void search_password();
void delete_password();
void display_menu();

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                search_password();
                break;
            case 4:
                delete_password();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\n--- Password Manager ---\n");
    printf("1. Add Password\n");
    printf("2. View All Passwords\n");
    printf("3. Search for a Password\n");
    printf("4. Delete a Password\n");
    printf("5. Exit\n");
}

void add_password() {
    PasswordEntry entry;
    FILE *file = fopen(FILENAME, "ab");

    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    printf("Enter title of the password: ");
    fgets(entry.title, MAX_TITLE_LENGTH, stdin);
    entry.title[strcspn(entry.title, "\n")] = 0; // Remove newline character

    printf("Enter username: ");
    fgets(entry.username, MAX_PASSWORD_LENGTH, stdin);
    entry.username[strcspn(entry.username, "\n")] = 0;

    printf("Enter password: ");
    fgets(entry.password, MAX_PASSWORD_LENGTH, stdin);
    entry.password[strcspn(entry.password, "\n")] = 0;

    fwrite(&entry, sizeof(PasswordEntry), 1, file);
    fclose(file);
    printf("Password added successfully.\n");
}

void view_passwords() {
    PasswordEntry entry;
    FILE *file = fopen(FILENAME, "rb");

    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    printf("\n--- Stored Passwords ---\n");
    while (fread(&entry, sizeof(PasswordEntry), 1, file)) {
        printf("Title: %s\nUsername: %s\nPassword: %s\n", 
               entry.title, entry.username, entry.password);
    }
    fclose(file);
}

void search_password() {
    PasswordEntry entry;
    char search_title[MAX_TITLE_LENGTH];
    FILE *file = fopen(FILENAME, "rb");
    int found = 0;

    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    printf("Enter the title to search for: ");
    fgets(search_title, MAX_TITLE_LENGTH, stdin);
    search_title[strcspn(search_title, "\n")] = 0;

    while (fread(&entry, sizeof(PasswordEntry), 1, file)) {
        if (strcmp(entry.title, search_title) == 0) {
            found = 1;
            printf("Found Password!\n");
            printf("Title: %s\nUsername: %s\nPassword: %s\n", 
                   entry.title, entry.username, entry.password);
            break;
        }
    }

    if (!found) {
        printf("No password found with the title '%s'.\n", search_title);
    }
    fclose(file);
}

void delete_password() {
    PasswordEntry entry;
    FILE *file = fopen(FILENAME, "rb");
    FILE *temp_file = fopen("temp.dat", "wb");
    char delete_title[MAX_TITLE_LENGTH];
    int found = 0;

    if (file == NULL || temp_file == NULL) {
        perror("Could not open file");
        return;
    }

    printf("Enter the title of the password to delete: ");
    fgets(delete_title, MAX_TITLE_LENGTH, stdin);
    delete_title[strcspn(delete_title, "\n")] = 0;

    while (fread(&entry, sizeof(PasswordEntry), 1, file)) {
        if (strcmp(entry.title, delete_title) != 0) {
            fwrite(&entry, sizeof(PasswordEntry), 1, temp_file);
        } else {
            found = 1;
            printf("Deleted password titled '%s'.\n", delete_title);
        }
    }

    if (!found) {
        printf("No password found with the title '%s' to delete.\n", delete_title);
    }

    fclose(file);
    fclose(temp_file);
    
    remove(FILENAME);
    rename("temp.dat", FILENAME);
}