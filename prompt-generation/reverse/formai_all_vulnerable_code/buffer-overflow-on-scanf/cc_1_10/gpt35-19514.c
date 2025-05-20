//FormAI DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length for password and username
#define MAX_LENGTH 50

// Define structure for password
struct Password {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char website[MAX_LENGTH];
};

// Function to create a new password entry and store it in a file
void createNewPasswordEntry() {
    struct Password newPassword;

    // Prompt user for website, username, and password
    printf("Enter website: ");
    fgets(newPassword.website, MAX_LENGTH, stdin);

    printf("Enter username: ");
    fgets(newPassword.username, MAX_LENGTH, stdin);

    printf("Enter password: ");
    fgets(newPassword.password, MAX_LENGTH, stdin);

    // Open file in write mode and write the new password entry
    FILE *fptr;
    fptr = fopen("passwords.txt", "a+");
    fprintf(fptr, "%s%s%s\n", newPassword.website, newPassword.username, newPassword.password);
    fclose(fptr);

    printf("New password entry added successfully!\n");
}

// Function to display all password entries stored in the file
void displayAllPasswords() {
    // Open file in read mode and read all password entries
    FILE *fptr;
    fptr = fopen("passwords.txt", "r");

    printf("Website\t\tUsername\tPassword\n");

    char line[MAX_LENGTH * 3];
    while (fgets(line, MAX_LENGTH * 3, fptr) != NULL) {
        printf("%s", line);
    }

    fclose(fptr);
}

// Function to delete a password entry based on website
void deletePasswordByWebsite() {
    // Prompt user for website to delete
    char websiteToDelete[MAX_LENGTH];
    printf("Enter website to delete: ");
    fgets(websiteToDelete, MAX_LENGTH, stdin);

    // Open temporary file to write all non-matching password entries
    FILE *fptr1, *fptr2;
    fptr1 = fopen("passwords.txt", "r");
    fptr2 = fopen("temp.txt", "w");

    char line[MAX_LENGTH * 3];
    while (fgets(line, MAX_LENGTH * 3, fptr1) != NULL) {
        if (strstr(line, websiteToDelete) == NULL) {
            fprintf(fptr2, "%s", line);
        }
    }

    fclose(fptr1);
    fclose(fptr2);

    // Delete original file and rename temp file to original filename
    remove("passwords.txt");
    rename("temp.txt", "passwords.txt");

    printf("Password entry for %s deleted successfully!\n", websiteToDelete);
}

// Main function
int main() {
    int choice;

    printf("Welcome to Password Manager!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create new password entry\n");
        printf("2. Display all password entries\n");
        printf("3. Delete password entry by website\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                createNewPasswordEntry();
                break;
            case 2:
                displayAllPasswords();
                break;
            case 3:
                deletePasswordByWebsite();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}