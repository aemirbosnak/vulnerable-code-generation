//FormAI DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000

struct Password {
    char website[50];
    char username[50];
    char password[50];
};

struct Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: password database full\n");
        return;
    }
    
    struct Password newPassword;
    printf("Enter website: ");
    scanf("%s", newPassword.website);
    printf("Enter username: ");
    scanf("%s", newPassword.username);
    printf("Enter password: ");
    scanf("%s", newPassword.password);
    
    passwords[numPasswords++] = newPassword;
}

void viewPasswords() {
    if (numPasswords == 0) {
        printf("No passwords saved\n");
        return;
    }
    
    printf("%-20s %-20s %-20s\n", "Website", "Username", "Password");
    printf("------------------------------------------------\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%-20s %-20s %-20s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

void searchPasswords() {
    char website[50];
    printf("Enter website to search for: ");
    scanf("%s", website);
    
    int found = 0;
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            printf("%-20s %-20s %-20s\n", "Website", "Username", "Password");
            printf("------------------------------------------------\n");
            printf("%-20s %-20s %-20s\n", passwords[i].website, passwords[i].username, passwords[i].password);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Password not found for website: %s\n", website);
    }
}

int main() {
    int choice;
    
    do {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Search passwords\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                searchPasswords();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);
    
    return 0;
}