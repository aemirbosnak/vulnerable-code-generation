//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_LEN 100
#define FILENAME "passwords.txt"

typedef struct {
    char service[MAX_LEN];
    char username[MAX_LEN];
    char password[MAX_LEN];
} PasswordEntry;

PasswordEntry passwords[MAX_ITEMS];
int count = 0;

void loadPasswords() {
    FILE *file = fopen(FILENAME, "r");
    if (file != NULL) {
        while (fscanf(file, "%s %s %s", passwords[count].service, passwords[count].username, passwords[count].password) != EOF) {
            count++;
        }
        fclose(file);
    }
}

void savePasswords() {
    FILE *file = fopen(FILENAME, "w");
    if (file != NULL) {
        for (int i = 0; i < count; i++) {
            fprintf(file, "%s %s %s\n", passwords[i].service, passwords[i].username, passwords[i].password);
        }
        fclose(file);
    }
}

void addPassword() {
    if (count >= MAX_ITEMS) {
        printf("Password list is full!\n");
        return;
    }
    printf("Enter service name: ");
    scanf("%s", passwords[count].service);
    printf("Enter username: ");
    scanf("%s", passwords[count].username);
    printf("Enter password: ");
    scanf("%s", passwords[count].password);
    count++;
    savePasswords();
    printf("Password added successfully.\n");
}

void viewPasswords() {
    if (count == 0) {
        printf("No passwords stored.\n");
        return;
    }
    printf("Stored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: Service: %s, Username: %s, Password: %s\n", i + 1, passwords[i].service, passwords[i].username, passwords[i].password);
    }
}

void deletePassword() {
    int index;
    printf("Enter the number of the password to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > count) {
        printf("Invalid index.\n");
        return;
    }
    
    for (int i = index - 1; i < count - 1; i++) {
        passwords[i] = passwords[i + 1];
    }
    count--;
    savePasswords();
    printf("Password deleted successfully.\n");
}

void searchPassword() {
    char service[MAX_LEN];
    printf("Enter the service name to search: ");
    scanf("%s", service);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(passwords[i].service, service) == 0) {
            printf("Found - Service: %s, Username: %s, Password: %s\n", passwords[i].service, passwords[i].username, passwords[i].password);
            return;
        }
    }
    printf("No password found for the service: %s\n", service);
}

void displayMenu() {
    printf("\nPassword Manager\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Search Password\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    loadPasswords();
    
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                searchPassword();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}