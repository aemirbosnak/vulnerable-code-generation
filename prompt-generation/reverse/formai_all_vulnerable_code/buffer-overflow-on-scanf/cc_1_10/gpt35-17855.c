//FormAI DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000  // Maximum number of passwords to be stored
#define MAX_LENGTH 50       // Maximum length of each password

void add_password(char *password, char passwords[MAX_PASSWORDS][MAX_LENGTH], int *num_passwords) 
{
    if (*num_passwords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords exceeded.\n");
        return;
    }
    strncpy(passwords[*num_passwords], password, MAX_LENGTH);
    (*num_passwords)++;
    printf("Password added successfully.\n");
}

void display_passwords(char passwords[MAX_PASSWORDS][MAX_LENGTH], int num_passwords) 
{
    if (num_passwords == 0) {
        printf("No passwords found.\n");
        return;
    }
    printf("List of passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%d: %s\n", i+1, passwords[i]);
    }
}

int main() 
{
    char passwords[MAX_PASSWORDS][MAX_LENGTH];  // Two-dimensional array to store passwords
    int num_passwords = 0;                      // Counter for number of passwords stored
    int choice;                                 // User's choice from menu
    char password[MAX_LENGTH];                  // Variable to hold user input password
    
    printf("--- Password Manager ---\n");

    // Loop for displaying menu until user exits program
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add password\n");
        printf("2. Display passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a password to add (maximum length %d): ", MAX_LENGTH);
                scanf("%s", password);
                add_password(password, passwords, &num_passwords);
                break;
            case 2:
                display_passwords(passwords, num_passwords);
                break;
            case 3:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice, choose again.\n");
        }
    }
    return 0;
}