//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50

typedef struct {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_PASSWORDS];
int passwordCount = 0;

void add_password();
void list_passwords();
void find_password();
void delete_password();
void clear_screen();
void save_passwords();
void load_passwords();

int main() {
    int choice;
    load_passwords();

    while (1) {
        clear_screen();
        printf("Password Manager\n");
        printf("=================\n");
        printf("1. Add Password\n");
        printf("2. List Passwords\n");
        printf("3. Find Password\n");
        printf("4. Delete Password\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                list_passwords();
                break;
            case 3:
                find_password();
                break;
            case 4:
                delete_password();
                break;
            case 5:
                save_passwords();
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
        printf("Press any key to continue...\n");
        getchar(); // Wait for user input
    }

    return 0;
}

void add_password() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password list is full!\n");
        return;
    }

    printf("Enter service name: ");
    fgets(passwordList[passwordCount].service, MAX_LENGTH, stdin);
    passwordList[passwordCount].service[strcspn(passwordList[passwordCount].service, "\n")] = '\0';

    printf("Enter username: ");
    fgets(passwordList[passwordCount].username, MAX_LENGTH, stdin);
    passwordList[passwordCount].username[strcspn(passwordList[passwordCount].username, "\n")] = '\0';

    printf("Enter password: ");
    fgets(passwordList[passwordCount].password, MAX_LENGTH, stdin);
    passwordList[passwordCount].password[strcspn(passwordList[passwordCount].password, "\n")] = '\0';

    passwordCount++;
    printf("Password added successfully!\n");
}

void list_passwords() {
    printf("Listing All Passwords:\n");
    printf("======================\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("Service: %s\n", passwordList[i].service);
        printf("Username: %s\n", passwordList[i].username);
        printf("Password: %s\n", passwordList[i].password);
        printf("----------------------\n");
    }
}

void find_password() {
    char service[MAX_LENGTH];
    printf("Enter service name to find: ");
    fgets(service, MAX_LENGTH, stdin);
    service[strcspn(service, "\n")] = '\0';

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordList[i].service, service) == 0) {
            printf("Found Password for %s:\n", service);
            printf("Username: %s\n", passwordList[i].username);
            printf("Password: %s\n", passwordList[i].password);
            return;
        }
    }
    printf("No entry found for %s.\n", service);
}

void delete_password() {
    char service[MAX_LENGTH];
    printf("Enter service name to delete: ");
    fgets(service, MAX_LENGTH, stdin);
    service[strcspn(service, "\n")] = '\0';

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordList[i].service, service) == 0) {
            for (int j = i; j < passwordCount - 1; j++) {
                passwordList[j] = passwordList[j + 1];
            }
            passwordCount--;
            printf("Password entry for %s deleted successfully!\n", service);
            return;
        }
    }
    printf("No entry found for %s.\n", service);
}

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the console
}

void save_passwords() {
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < passwordCount; i++) {
        fprintf(file, "%s\n%s\n%s\n", passwordList[i].service, passwordList[i].username, passwordList[i].password);
    }
    fclose(file);
    printf("Passwords saved to passwords.txt!\n");
}

void load_passwords() {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        return; // No file to load, just return
    }
    while (fscanf(file, "%49[^\n]\n%49[^\n]\n%49[^\n]\n", 
         passwordList[passwordCount].service, 
         passwordList[passwordCount].username, 
         passwordList[passwordCount].password) == 3) {
        passwordCount++;
    }
    fclose(file);
}