//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: beginner-friendly
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

PasswordEntry passwordList[MAX_PASSWORDS];
int passwordCount = 0;

void loadPasswords() {
    FILE *file = fopen("passwords.txt", "r");
    if (file) {
        while (fscanf(file, "%s %s %s", passwordList[passwordCount].website, 
                passwordList[passwordCount].username, 
                passwordList[passwordCount].password) != EOF) {
            passwordCount++;
        }
        fclose(file);
    }
}

void savePasswords() {
    FILE *file = fopen("passwords.txt", "w");
    for (int i = 0; i < passwordCount; i++) {
        fprintf(file, "%s %s %s\n", passwordList[i].website, 
                passwordList[i].username, 
                passwordList[i].password);
    }
    fclose(file);
}

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password storage is full.\n");
        return;
    }
    
    printf("Enter website: ");
    scanf("%s", passwordList[passwordCount].website);
    printf("Enter username: ");
    scanf("%s", passwordList[passwordCount].username);
    printf("Enter password: ");
    scanf("%s", passwordList[passwordCount].password);
    
    passwordCount++;
    savePasswords();
    printf("Password added successfully!\n");
}

void viewPasswords() {
    if (passwordCount == 0) {
        printf("No stored passwords.\n");
        return;
    }
    
    printf("\nStored Passwords:\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("Website: %s, Username: %s, Password: %s\n", 
               passwordList[i].website, 
               passwordList[i].username, 
               passwordList[i].password);
    }
}

void deletePassword() {
    char website[MAX_LENGTH];
    printf("Enter website to delete: ");
    scanf("%s", website);
    
    int found = 0;
    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordList[i].website, website) == 0) {
            for (int j = i; j < passwordCount - 1; j++) {
                passwordList[j] = passwordList[j + 1];
            }
            passwordCount--;
            found = 1;
            printf("Password for %s deleted successfully!\n", website);
            break;
        }
    }
    
    if (!found) {
        printf("No password found for %s.\n", website);
    }
    savePasswords();
}

void displayMenu() {
    printf("\nPassword Manager\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    loadPasswords();
    
    while (1) {
        displayMenu();
        int choice;
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
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}