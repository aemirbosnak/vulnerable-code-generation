//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

void addPassword(PasswordEntry *entries, int *count) {
    if (*count >= MAX_PASSWORDS) {
        printf("Password storage full! Cannot add more passwords.\n");
        return;
    }
    
    printf("Enter website: ");
    scanf("%s", entries[*count].website);
    printf("Enter username: ");
    scanf("%s", entries[*count].username);
    printf("Enter password: ");
    scanf("%s", entries[*count].password);
    
    (*count)++;
    printf("Password for %s added successfully!\n\n", entries[*count - 1].website);
}

void viewPasswords(const PasswordEntry *entries, int count) {
    if (count == 0) {
        printf("No passwords stored yet!\n\n");
        return;
    }
    
    printf("Stored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Website: %s, Username: %s, Password: %s\n", 
            entries[i].website, entries[i].username, entries[i].password);
    }
    printf("\n");
}

void deletePassword(PasswordEntry *entries, int *count) {
    if (*count == 0) {
        printf("No passwords to delete!\n\n");
        return;
    }
    
    char website[MAX_LENGTH];
    printf("Enter website of the password to delete: ");
    scanf("%s", website);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            entries[i] = entries[*count - 1]; // Replace with last entry
            (*count)--;
            printf("Password for %s deleted successfully!\n\n", website);
            return;
        }
    }
    
    printf("No password found for website %s.\n\n", website);
}

void displayMenu() {
    printf("******** Password Manager ********\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
    printf("*********************************\n");
}

int main() {
    PasswordEntry entries[MAX_PASSWORDS];
    int count = 0;
    int choice;

    printf("Welcome to the Password Manager! Let's keep your passwords secure!\n\n");

    while (1) {
        displayMenu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPassword(entries, &count);
                break;
            case 2:
                viewPasswords(entries, count);
                break;
            case 3:
                deletePassword(entries, &count);
                break;
            case 4:
                printf("Thank you for using Password Manager! Stay safe!\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n\n");
        }
    }

    return 0;
}