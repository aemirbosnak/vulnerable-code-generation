//FormAI DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
// Max size of password database
#define MAX_SIZE 100
 
// Struct for password entry
typedef struct {
    char website[50];
    char username[50];
    char password[50];
} PasswordEntry;
 
// Global array of password entries
PasswordEntry passwords[MAX_SIZE];
int numEntries = 0; // Keep track of number of entries
 
// Function to add a new password entry
void addEntry() {
    if (numEntries >= MAX_SIZE) {
        printf("Password database is full. Cannot add new entry.\n");
        return;
    }
 
    PasswordEntry newEntry;
    printf("Enter website: ");
    scanf("%s", newEntry.website);
    printf("Enter username: ");
    scanf("%s", newEntry.username);
    printf("Enter password: ");
    scanf("%s", newEntry.password);
    passwords[numEntries] = newEntry;
    numEntries++;
    printf("Entry added successfully!\n");
}
 
// Function to search for a password entry by website
void searchEntry() {
    char website[50];
    printf("Enter website to search for: ");
    scanf("%s", website);
 
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            printf("Found entry:\nWebsite: %s\nUsername: %s\nPassword: %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
            return;
        }
    }
 
    printf("No entry found for website %s\n", website);
}
 
// Function to print all password entries
void printAllEntries() {
    printf("All password entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("Website: %s\nUsername: %s\nPassword: %s\n\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}
 
// Function to generate a random password
void generatePassword() {
    printf("Generating random password...\n");
 
    char password[50];
    for (int i = 0; i < 10; i++) {
        password[i] = 'A' + rand() % 26; // Random capital letter
    }
    for (int i = 10; i < 20; i++) {
        password[i] = 'a' + rand() % 26; // Random lowercase letter
    }
    for (int i = 20; i < 30; i++) {
        password[i] = '0' + rand() % 10; // Random digit
    }
    password[30] = '\0'; // Null terminate the string
 
    printf("Random password generated: %s\n", password);
}
 
// Main function to run password management program
int main() {
    char choice = '0';
 
    // Loop until user chooses to exit
    while (choice != '5') {
        printf("\n\nPassword Management\n");
        printf("====================\n");
        printf("1. Add new entry\n");
        printf("2. Search for entry\n");
        printf("3. Print all entries\n");
        printf("4. Generate random password\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
 
        switch (choice) {
            case '1':
                addEntry();
                break;
            case '2':
                searchEntry();
                break;
            case '3':
                printAllEntries();
                break;
            case '4':
                generatePassword();
                break;
            case '5':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
 
    return 0;
}