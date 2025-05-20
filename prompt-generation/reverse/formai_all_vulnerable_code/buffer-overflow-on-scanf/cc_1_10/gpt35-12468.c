//FormAI DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100 // Maximum number of passwords that can be stored

struct password { // Struct to hold password information
    char service[50];
    char username[50];
    char password[50];
};

int numPasswords = 0; // Counter for number of stored passwords
struct password passwords[MAX_PASSWORDS]; // Array to hold all password structs

void menu() { // Function to display menu options
    printf("\nEnter 1 to add a password\n");
    printf("Enter 2 to view all passwords\n");
    printf("Enter 3 to search for a password\n");
    printf("Enter 4 to delete a password\n");
    printf("Enter 0 to exit\n\n");
}

void addPassword() { // Function to add a password to the struct array
    if (numPasswords >= MAX_PASSWORDS) {
        printf("\nYou have reached the maximum number of stored passwords.\n");
        return;
    }
    struct password newPassword;
    printf("\nEnter the service name: ");
    scanf("%s", newPassword.service);
    printf("Enter the username: ");
    scanf("%s", newPassword.username);
    printf("Enter the password: ");
    scanf("%s", newPassword.password);
    passwords[numPasswords++] = newPassword; // Add new password to array and increment counter
    printf("\nPassword added successfully!\n");
}

void viewPasswords() { // Function to display all stored passwords
    if (numPasswords == 0) {
        printf("\nThere are no stored passwords.\n");
        return;
    }
    printf("\nService\t\tUsername\tPassword\n");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t%s\t%s\n", passwords[i].service, passwords[i].username, passwords[i].password);
    }
}

void searchPasswords() { // Function to search for a specific password by service name
    if (numPasswords == 0) {
        printf("\nThere are no stored passwords to search.\n");
        return;
    }
    char searchService[50];
    printf("\nEnter the service name to search for: ");
    scanf("%s", searchService);
    int found = 0;
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].service, searchService) == 0) { // Compare service names
            printf("\nService\t\tUsername\tPassword\n");
            printf("-----------------------------------------------\n");
            printf("%s\t%s\t%s\n", passwords[i].service, passwords[i].username, passwords[i].password);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo passwords found for service %s\n", searchService);
    }
}

void deletePassword() { // Function to delete a specific password by service name
    if (numPasswords == 0) {
        printf("\nThere are no stored passwords to delete.\n");
        return;
    }
    char deleteService[50];
    printf("\nEnter the service name to delete: ");
    scanf("%s", deleteService);
    int found = 0;
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].service, deleteService) == 0) { // Compare service names
            for (int j = i; j < numPasswords - 1; j++) {
                passwords[j] = passwords[j+1]; // Shift all subsequent passwords down one index
            }
            numPasswords--; // Decrement counter
            printf("\nPassword deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo passwords found for service %s\n", deleteService);
    }
}

int main() {
    printf("Welcome to your password manager!\n");
    while (1) {
        menu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                printf("\nThank you for using your password manager. Goodbye!\n");
                return 0;
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
                deletePassword();
                break;
            default:
                printf("\nInvalid choice. Please select a valid option from the menu.\n");
                break;
        }
    }
    return 0;
}