//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SITES 100
#define MAX_LENGTH 100
#define FILE_NAME "passwords.txt"

// Function to add a new password
void addPassword() {
    char site[MAX_LENGTH];
    char password[MAX_LENGTH];
    
    printf("Enter the site name: ");
    scanf("%s", site);
    printf("Enter the password: ");
    scanf("%s", password);
    
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    fprintf(file, "%s %s\n", site, password);
    fclose(file);
    printf("Password added successfully!\n");
}

// Function to display all stored passwords
void displayPasswords() {
    char line[256];
    
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No passwords stored yet!\n");
        return;
    }
    
    printf("Stored passwords:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// Function to delete a password
void deletePassword() {
    char site[MAX_LENGTH];
    char line[256];
    int found = 0;

    printf("Enter the site name to delete: ");
    scanf("%s", site);
    
    FILE *file = fopen(FILE_NAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    
    if (file == NULL) {
        printf("No passwords stored yet!\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, site) == NULL) {
            fputs(line, tempFile);
        } else {
            found = 1;
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
    
    if (found) {
        printf("Password for '%s' deleted successfully!\n", site);
    } else {
        printf("No password found for '%s'.\n", site);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\nPassword Management System\n");
    printf("1. Add Password\n");
    printf("2. Display Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}