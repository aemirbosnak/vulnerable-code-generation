//FormAI DATASET v1.0 Category: Password management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 5
#define MAX_SIZE 50

struct PasswordManager{
    char password[MAX_SIZE];
    char website[MAX_SIZE];
};

struct PasswordManager passwordDatabase[MAX_PASSWORDS];
int numPasswords = 0;

// Function to add a new password to the database
void addPassword() {
    struct PasswordManager newPassword;
    printf("Enter the website name: ");
    scanf("%s", newPassword.website);
    printf("Enter the password: ");
    scanf("%s", newPassword.password);
    passwordDatabase[numPasswords++] = newPassword;
}

// Function to display all the passwords in the database
void displayPasswords() {
    printf("----------------------------------------------------------\n");
    printf("%-20s %s\n", "Website", "Password");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%-20s %s\n", passwordDatabase[i].website, passwordDatabase[i].password);
    }
    if (numPasswords == 0) {
        printf("Password Database is empty.\n");
    }
    printf("----------------------------------------------------------\n");
}

// Function to search for a password based on the website
void searchPassword() {
    char website[MAX_SIZE];
    printf("Enter the website name to search: ");
    scanf("%s", website);
    printf("----------------------------------------------------------\n");
    printf("%-20s %s\n", "Website", "Password");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwordDatabase[i].website, website) == 0) {
            printf("%-20s %s\n", passwordDatabase[i].website, passwordDatabase[i].password);
            return;
        }
    }
    printf("No password found for %s.\n", website);
    printf("----------------------------------------------------------\n");
}

// Function to delete a password based on the website
void deletePassword() {
    char website[MAX_SIZE];
    printf("Enter the website name to delete: ");
    scanf("%s", website);
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwordDatabase[i].website, website) == 0) {
            // Shift the passwords left to fill the empty slot
            for (int j = i; j < numPasswords - 1; j++) {
                passwordDatabase[j] = passwordDatabase[j+1];
            }
            numPasswords--;
            printf("Password for website %s deleted successfully.\n", website);
            return;
        }
    }
    printf("No password found for %s.\n", website);
}

int main(){
    int ch;
    while (1){
        printf("\nChoose an operation to perform:\n");
        printf("1. Add a new Password\n");
        printf("2. Display all Passwords\n");
        printf("3. Search for Password\n");
        printf("4. Delete a Password\n");
        printf("5. Exit\n\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
                addPassword();
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                searchPassword();
                break;
            case 4:
                deletePassword();
                break;
            case 5:
                printf("Thank you for using Password Manager!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}