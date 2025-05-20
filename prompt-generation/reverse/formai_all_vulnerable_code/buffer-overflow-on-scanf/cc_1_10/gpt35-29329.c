//FormAI DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PASSWORDS 100

struct Password { // Define Password struct
    char account[20];
    char username[20];
    char password[20];
};

int numPasswords = 0; // Global variable for number of stored passwords
struct Password passwords[MAX_PASSWORDS]; // Global variable for array of Passwords

void printMenu() { // Function to print menu options
    printf("Password Manager\n");
    printf("1. Add New Password\n");
    printf("2. View All Passwords\n");
    printf("3. Find Password\n");
    printf("4. Exit\n");
    printf("Please enter an option: ");
}

void addPassword() { // Function to add a new password to the array
    if(numPasswords == MAX_PASSWORDS) { // Check if array is already full
        printf("Error: maximum number of passwords reached\n");
        return;
    }
    struct Password newPassword; // Create new Password struct
    printf("Account: ");
    scanf("%s", newPassword.account);
    printf("Username: ");
    scanf("%s", newPassword.username);
    printf("Password: ");
    scanf("%s", newPassword.password);
    passwords[numPasswords] = newPassword; // Add new password to array
    numPasswords++;
    printf("Password added successfully\n");
}

void viewPasswords() { // Function to view all stored passwords
    if(numPasswords == 0) { // Check if array is empty
        printf("No passwords stored\n");
        return;
    }
    printf("Account\tUsername\tPassword\n");
    for(int i = 0; i < numPasswords; i++) { // Loop through array and print each password
        printf("%s\t%s\t%s\n", passwords[i].account, passwords[i].username, passwords[i].password);
    }
}

void findPassword() { // Function to find a password by account name
    if(numPasswords == 0) { // Check if array is empty
        printf("No passwords stored\n");
        return;
    }
    char accountName[20];
    printf("Enter account name to find: ");
    scanf("%s", accountName);
    for(int i = 0; i < numPasswords; i++) { // Loop through array to find matching account name
        if(strcmp(passwords[i].account, accountName) == 0) { // Use strcmp() to compare strings
            printf("Account: %s\nUsername: %s\nPassword: %s\n", passwords[i].account, passwords[i].username, passwords[i].password);
            return;
        }
    }
    printf("Could not find password for account %s\n", accountName);
}

int main() {
    int choice = 0;
    while(choice != 4) { // Loop until user chooses to exit
        printMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                findPassword();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}