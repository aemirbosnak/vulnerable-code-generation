//FormAI DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 20 // Maximum length of passwords
#define MAX_PASSWORDS 10 // Maximum number of passwords

typedef struct {
    char website[50];
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS]; // Array of Password structures for storing passwords
int numPasswords = 0; // Number of passwords stored

// Function for displaying options menu
void printMenu() {
    printf("1. Add a new password\n");
    printf("2. View all passwords\n");
    printf("3. Search for a password\n");
    printf("4. Delete a password\n");
    printf("5. Exit\n");
}

// Function for adding a new password
void addPassword() {
    if(numPasswords == MAX_PASSWORDS) { // Check if password array is full
        printf("Password database is full\n");
        return;
    }

    Password newPass;

    printf("Enter website name: ");
    scanf("%s", newPass.website);
    printf("Enter username: ");
    scanf("%s", newPass.username);
    printf("Enter password: ");
    scanf("%s", newPass.password);

    passwords[numPasswords++] = newPass; // Add new password to array
    printf("Password added successfully\n");
}

// Function for displaying all saved passwords
void viewPasswords() {
    if(numPasswords == 0) { // Check if there are no saved passwords
        printf("No passwords saved\n");
        return;
    }

    printf("Website\t\tUsername\tPassword\n");
    printf("---------------------------------------------\n");

    for(int i = 0; i < numPasswords; i++) { // Loop through all saved passwords and print them
        printf("%s\t\t%s\t\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

// Function for searching for a saved password based on website name
void searchPasswords() {
    if(numPasswords == 0) { // Check if there are no saved passwords
        printf("No passwords saved\n");
        return;
    }

    char searchWebsite[50];
    printf("Enter the website name: ");
    scanf("%s", searchWebsite);

    bool found = false;

    for(int i = 0; i < numPasswords; i++) { // Loop through all saved passwords and check if website name matches
        if(strcmp(passwords[i].website, searchWebsite) == 0) {
            printf("Website\t\tUsername\tPassword\n");
            printf("---------------------------------------------\n");
            printf("%s\t\t%s\t\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
            found = true;
            break;
        }
    }

    if(!found) {
        printf("Password not found\n");
    }
}

// Function for deleting a saved password based on website name
void deletePassword() {
    if(numPasswords == 0) { // Check if there are no saved passwords
        printf("No passwords saved\n");
        return;
    }

    char delWebsite[50];
    printf("Enter the website name: ");
    scanf("%s", delWebsite);

    bool found = false;

    for(int i = 0; i < numPasswords; i++) { // Loop through all saved passwords and check if website name matches
        if(strcmp(passwords[i].website, delWebsite) == 0) {
            for(int j = i; j < numPasswords-1; j++) { // Shift array elements left to remove the deleted password
                passwords[j] = passwords[j+1];
            }
            numPasswords--;
            printf("Password deleted successfully\n");
            found = true;
            break;
        }
    }

    if(!found) {
        printf("Password not found\n");
    }
}

int main() {
    while(true) { // Loop continuously until user decides to exit
        printMenu();
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) { // Call appropriate function based on user's menu choice
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
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }

        printf("\n");
    }
}