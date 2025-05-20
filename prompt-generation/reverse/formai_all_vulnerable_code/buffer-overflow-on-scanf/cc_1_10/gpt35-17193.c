//FormAI DATASET v1.0 Category: Password management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Shape-shifting menu options
enum ShapeShiftOptions {
    MENU_MAIN,
    MENU_CREATE,
    MENU_VIEW,
    MENU_EXIT
};

// Password structure
struct Password {
    char name[50];
    char username[50];
    char password[50];
};

// Function prototypes
void clearBuffer();
void printMenu(int menuOption);
void createNewPassword();
void viewPasswords();

// Global variables
const int MAX_PASSWORDS = 50;
int numPasswords = 0;
struct Password passwords[50];

// Main function
int main() {
    int menuOption = MENU_MAIN;

    while (menuOption != MENU_EXIT) {
        printMenu(menuOption);
        int choice;
        scanf("%d", &choice);
        clearBuffer();

        switch(menuOption) {
            case MENU_MAIN:
                if (choice == 1) {
                    menuOption = MENU_CREATE;
                } else if (choice == 2) {
                    menuOption = MENU_VIEW;
                } else if (choice == 3) {
                    menuOption = MENU_EXIT;
                }
                break;
            case MENU_CREATE:
                if (choice == 1) {
                    createNewPassword();
                } else if (choice == 2) {
                    menuOption = MENU_MAIN;
                }
                break;
            case MENU_VIEW:
                if (choice == 1) {
                    viewPasswords();
                } else if (choice == 2) {
                    menuOption = MENU_MAIN;
                }
                break;
        }
    }

    return 0;
}

// Clear input buffer
void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Print menu based on current menu option
void printMenu(int menuOption) {
    system("clear"); // Shape-shift into a clear screen

    switch(menuOption) {
        case MENU_MAIN:
            printf("Password Manager\n");
            printf("----------------\n");
            printf("1. Create new password\n");
            printf("2. View passwords\n");
            printf("3. Exit\n");
            break;
        case MENU_CREATE:
            printf("Create New Password\n");
            printf("-------------------\n");
            printf("Enter name: ");
            break;
        case MENU_VIEW:
            printf("View Passwords\n");
            printf("---------------\n");
            for (int i = 0; i < numPasswords; i++) {
                printf("%d. %s\n", i+1, passwords[i].name);
            }
            printf("\nEnter the number of the password to view or 0 to go back: ");
            break;
    }
}

// Create a new password
void createNewPassword() {
    char name[50];
    char username[50];
    char password[50];

    printf("Enter name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Enter username: ");
    fgets(username, 50, stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter password: ");
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = 0;

    struct Password newPass;
    strcpy(newPass.name, name);
    strcpy(newPass.username, username);
    strcpy(newPass.password, password);

    if (numPasswords < MAX_PASSWORDS) {
        passwords[numPasswords++] = newPass;
    }

    printf("\nShape-shift into a success message!\n\n");
    printf("Password created successfully.\n");
    printf("Press enter to continue...");
    getchar(); // Wait for enter key before returning to main menu
}

// View existing passwords
void viewPasswords() {
    int choice;
    scanf("%d", &choice);
    clearBuffer();

    if (choice == 0) {
        return;
    }

    if (choice > numPasswords || choice < 0) {
        printf("\nShape-shift into an error message!\n\n");
        printf("Invalid password number.\n");
        printf("Press enter to continue...");
        getchar(); // Wait for enter key before returning to view menu
    } else {
        struct Password pass = passwords[choice-1];
        printf("\nShape-shift into the password view!\n\n");
        printf("Name: %s\n", pass.name);
        printf("Username: %s\n", pass.username);
        printf("Password: %s\n", pass.password);
        printf("Press enter to continue...");
        getchar(); // Wait for enter key before returning to view menu
    }
}