//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_PASS_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char password[MAX_PASS_LEN];
} PasswordEntry;

PasswordEntry passwordList[MAX_ENTRIES];
int entryCount = 0;

// Function to set password without displaying it on the console
void setHiddenInput(char *password, size_t size) {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    fgets(password, size, stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline character from input
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

// Function to add a new password
void addPassword() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Password storage is full!\n");
        return;
    }
    printf("Enter Name for the entry: ");
    scanf("%s", passwordList[entryCount].name);

    printf("Enter Password for %s: ", passwordList[entryCount].name);
    setHiddenInput(passwordList[entryCount].password, MAX_PASS_LEN);
    
    entryCount++;
    printf("Password for '%s' added successfully!\n", passwordList[entryCount - 1].name);
}

// Function to retrieve a password
void retrievePassword() {
    char name[MAX_NAME_LEN];
    printf("Enter the Name to retrieve the password: ");
    scanf("%s", name);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(passwordList[i].name, name) == 0) {
            printf("Password for '%s' is: %s\n", name, passwordList[i].password);
            return;
        }
    }
    printf("No entry found for '%s'.\n", name);
}

// Function to list all passwords
void listPasswords() {
    if (entryCount == 0) {
        printf("No passwords stored.\n");
        return;
    }
    printf("\nList of Stored Passwords:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d: %s\n", i + 1, passwordList[i].name);
    }
    printf("\n");
}

// Function to display the main menu
void displayMenu() {
    printf("\nPassword Management System\n");
    printf("1. Add Password\n");
    printf("2. Retrieve Password\n");
    printf("3. List All Passwords\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
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
                retrievePassword();
                break;
            case 3:
                listPasswords();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}