//FormAI DATASET v1.0 Category: Password management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to hold password information
struct Password {
    char website[50];
    char username[30];
    char password[30];
};

// Function to add password to file
void add_password() {
    // Declare variable to hold user input
    struct Password password;

    // Ask user for website, username, and password
    printf("Enter website: ");
    scanf("%s", password.website);
    printf("Enter username: ");
    scanf("%s", password.username);
    printf("Enter password: ");
    scanf("%s", password.password);

    // Open file to add password
    FILE *file = fopen("passwords.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Write password information to file
    fprintf(file, "%s,%s,%s\n", password.website, password.username, password.password);

    // Close file
    fclose(file);

    printf("Password added successfully!\n");
}

// Function to display all saved passwords
void display_passwords() {
    // Open file to read passwords
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Loop through file to print out passwords
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        printf("%s", line);
    }

    // Close file
    fclose(file);
}

int main() {
    // Declare variable to hold user input
    int choice;

    printf("Welcome to Password Manager!\n");

    // Loop to display menu until user chooses to exit
    while (1) {
        printf("1. Add password\n");
        printf("2. Display passwords\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                display_passwords();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}