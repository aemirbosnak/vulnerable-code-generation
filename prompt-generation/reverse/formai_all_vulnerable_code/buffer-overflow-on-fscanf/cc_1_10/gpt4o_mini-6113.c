//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 50
#define FILE_NAME "passwords.txt"

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

void display_menu() {
    printf("\n--- Password Manager ---\n");
    printf("1. Add New Password Entry\n");
    printf("2. Display All Passwords\n");
    printf("3. Search Password\n");
    printf("4. Delete Password\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void encrypt(char *input, char *output) {
    while (*input) {
        *output = *input + 4; // Simple Caesar cipher
        input++;
        output++;
    }
    *output = '\0';
}

void decrypt(char *input, char *output) {
    while (*input) {
        *output = *input - 4; // Simple Caesar cipher
        input++;
        output++;
    }
    *output = '\0';
}

void add_password() {
    PasswordEntry entry;
    FILE *file = fopen(FILE_NAME, "a");

    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    printf("Enter website: ");
    scanf(" %[^\n]", entry.website);
    printf("Enter username: ");
    scanf(" %[^\n]", entry.username);
    printf("Enter password: ");
    scanf(" %[^\n]", entry.password);

    char encrypted_password[MAX_LENGTH];
    encrypt(entry.password, encrypted_password);

    fprintf(file, "%s;%s;%s\n", entry.website, entry.username, encrypted_password);
    fclose(file);

    printf("Password entry added successfully!\n");
}

void display_passwords() {
    PasswordEntry entry;
    FILE *file = fopen(FILE_NAME, "r");

    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    printf("\n--- Stored Passwords ---\n");
    while (fscanf(file, " %[^;];%[^;];%[^\n]\n", entry.website, entry.username, entry.password) != EOF) {
        char decrypted_password[MAX_LENGTH];
        decrypt(entry.password, decrypted_password);
        printf("Website: %s, Username: %s, Password: %s\n", entry.website, entry.username, decrypted_password);
    }
    fclose(file);
}

void search_password() {
    char website[MAX_LENGTH];
    PasswordEntry entry;
    int found = 0;

    printf("Enter the website to search for: ");
    scanf(" %[^\n]", website);

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    while (fscanf(file, " %[^;];%[^;];%[^\n]\n", entry.website, entry.username, entry.password) != EOF) {
        if (strcmp(entry.website, website) == 0) {
            char decrypted_password[MAX_LENGTH];
            decrypt(entry.password, decrypted_password);
            printf("Website: %s, Username: %s, Password: %s\n", entry.website, entry.username, decrypted_password);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No entry found for the website: %s\n", website);
    }
    fclose(file);
}

void delete_password() {
    char website[MAX_LENGTH];
    PasswordEntry entry;
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp_file = fopen("temp.txt", "w");

    if (file == NULL || temp_file == NULL) {
        perror("Could not open file");
        return;
    }

    printf("Enter the website to delete: ");
    scanf(" %[^\n]", website);

    int found = 0;
    while (fscanf(file, " %[^;];%[^;];%[^\n]\n", entry.website, entry.username, entry.password) != EOF) {
        if (strcmp(entry.website, website) == 0) {
            found = 1;
            printf("Deleting entry for website: %s\n", entry.website);
            continue; // skip the entry
        }
        fprintf(temp_file, "%s;%s;%s\n", entry.website, entry.username, entry.password);
    }
    if (!found) {
        printf("No entry found for the website: %s\n", website);
    }
    
    fclose(file);
    fclose(temp_file);
    
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                display_passwords();
                break;
            case 3:
                search_password();
                break;
            case 4:
                delete_password();
                break;
            case 5:
                printf("Exiting the Password Manager. Stay safe!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}