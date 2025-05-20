//FormAI DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void printHeader();
void displayMenu();
void addPassword();
void showPasswords();
void editPassword();
void deletePassword();

// Global variables
struct Password {
    char website[50];
    char username[50];
    char password[50];
};
struct Password passwords[100];
int numPasswords = 0;

int main() {
    // Load previously saved passwords
    FILE *fptr;
    fptr = fopen("passwords.txt", "r");
    if (fptr != NULL) {
        fread(&numPasswords, sizeof(int), 1, fptr);
        fread(passwords, sizeof(struct Password), numPasswords, fptr);
        fclose(fptr);
    }

    // Print header and display menu
    printHeader();
    displayMenu();

    // Save passwords to file before exiting
    fptr = fopen("passwords.txt", "w");
    fwrite(&numPasswords, sizeof(int), 1, fptr);
    fwrite(passwords, sizeof(struct Password), numPasswords, fptr);
    fclose(fptr);

    return 0;
}

void printHeader() {
    printf("\n**********************************************");
    printf("\n               PASSWORD MANAGER               ");
    printf("\n**********************************************\n");
}

void displayMenu() {
    printf("\nChoose an option:");
    printf("\n 1. Add password");
    printf("\n 2. Show passwords");
    printf("\n 3. Edit password");
    printf("\n 4. Delete password");
    printf("\n 5. Exit\n");

    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            showPasswords();
            break;
        case 3:
            editPassword();
            break;
        case 4:
            deletePassword();
            break;
        case 5:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            displayMenu();
    }
}

void addPassword() {
    struct Password newPassword;

    printf("\nEnter website: ");
    scanf("%s", newPassword.website);

    printf("Enter username: ");
    scanf("%s", newPassword.username);

    printf("Enter password: ");
    scanf("%s", newPassword.password);

    passwords[numPasswords] = newPassword;
    numPasswords++;

    printf("\nPassword added!\n");

    displayMenu();
}

void showPasswords() {
    if (numPasswords == 0) {
        printf("\nNo passwords saved.\n");
    } else {
        printf("\nWEBSITE\t\tUSERNAME\tPASSWORD");
        for (int i = 0; i < numPasswords; i++) {
            printf("\n%s\t\t%s\t\t%s", passwords[i].website, passwords[i].username, passwords[i].password);
        }
    }

    displayMenu();
}

void editPassword() {
    if (numPasswords == 0) {
        printf("\nNo passwords saved.\n");
    } else {
        printf("\nEnter website to edit: ");
        char website[50];
        scanf("%s", website);

        int index = -1;
        for (int i = 0; i < numPasswords; i++) {
            if (strcmp(passwords[i].website, website) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("\nWebsite not found.\n");
        } else {
            printf("\nEnter new username: ");
            scanf("%s", passwords[index].username);

            printf("Enter new password: ");
            scanf("%s", passwords[index].password);

            printf("\nPassword updated!\n");
        }
    }

    displayMenu();
}

void deletePassword() {
    if (numPasswords == 0) {
        printf("\nNo passwords saved.\n");
    } else {
        printf("\nEnter website to delete: ");
        char website[50];
        scanf("%s", website);

        int index = -1;
        for (int i = 0; i < numPasswords; i++) {
            if (strcmp(passwords[i].website, website) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("\nWebsite not found.\n");
        } else {
            for (int i = index; i < numPasswords-1; i++) {
                passwords[i] = passwords[i+1];
            }
            numPasswords--;

            printf("\nPassword deleted!\n");
        }
    }

    displayMenu();
}