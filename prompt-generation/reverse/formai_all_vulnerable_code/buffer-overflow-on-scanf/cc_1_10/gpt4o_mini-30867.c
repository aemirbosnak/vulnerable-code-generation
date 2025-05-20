//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 50

typedef struct {
    char site[50];
    char username[50];
    char password[PASSWORD_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_PASSWORDS];
int passwordCount = 0;

void addPassword() {
    if (passwordCount < MAX_PASSWORDS) {
        PasswordEntry newEntry;
        printf("Enter the site name: ");
        scanf("%s", newEntry.site);
        printf("Enter your username: ");
        scanf("%s", newEntry.username);
        printf("Enter your password: ");
        scanf("%s", newEntry.password);

        passwordList[passwordCount++] = newEntry;
        printf("Password for %s added successfully! 🎉\n", newEntry.site);
    } else {
        printf("Sorry, you can't store more passwords. Maximum limit reached! 😢\n");
    }
}

void viewPasswords() {
    if (passwordCount == 0) {
        printf("No passwords stored yet! 📂\n");
        return;
    }
    printf("\nYour stored passwords: \n");
    for (int i = 0; i < passwordCount; i++) {
        printf("Site: %s, Username: %s, Password: %s\n", 
                passwordList[i].site, 
                passwordList[i].username, 
                passwordList[i].password);
    }
}

void modifyPassword() {
    char site[50];
    printf("Enter the site name of the password you want to modify: ");
    scanf("%s", site);
    
    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordList[i].site, site) == 0) {
            printf("Enter the new username: ");
            scanf("%s", passwordList[i].username);
            printf("Enter the new password: ");
            scanf("%s", passwordList[i].password);
            printf("Password for %s updated successfully! ✨\n", site);
            return;
        }
    }
    printf("Site not found! Please check the name and try again. ❌\n");
}

void deletePassword() {
    char site[50];
    printf("Enter the site name of the password you want to delete: ");
    scanf("%s", site);
    
    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordList[i].site, site) == 0) {
            for (int j = i; j < passwordCount - 1; j++) {
                passwordList[j] = passwordList[j + 1];
            }
            passwordCount--;
            printf("Password for %s deleted successfully! 🗑️\n", site);
            return;
        }
    }
    printf("Site not found! Please double-check and try again. ❌\n");
}

void displayMenu() {
    printf("\n==== Welcome to the Password Manager! ====\n");
    printf("1. Add a new password\n");
    printf("2. View all passwords\n");
    printf("3. Modify an existing password\n");
    printf("4. Delete a password\n");
    printf("5. Exit\n");
    printf("==========================================\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                modifyPassword();
                break;
            case 4:
                deletePassword();
                break;
            case 5:
                printf("Thank you for using the Password Manager! Bye! 👋\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 5. ⚠️\n");
        }
    }
    return 0;
}