//FormAI DATASET v1.0 Category: Password management ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 50

// Define a structure for storing the passwords and their associated websites.
struct Password {
    char website[MAX_LENGTH];
    char password[MAX_LENGTH];
};

// Function to add a new password to the existing list.
void addPassword(struct Password *allPasswords, int *numPasswords) {
    printf("Enter the website name: ");
    fgets(allPasswords[*numPasswords].website, MAX_LENGTH, stdin);
    allPasswords[*numPasswords].website[strcspn(allPasswords[*numPasswords].website, "\n")] = 0;

    printf("Enter the password for %s: ", allPasswords[*numPasswords].website);
    fgets(allPasswords[*numPasswords].password, MAX_LENGTH, stdin);
    allPasswords[*numPasswords].password[strcspn(allPasswords[*numPasswords].password, "\n")] = 0;

    (*numPasswords)++;
    printf("Password added successfully!\n");
}

// Function to display all the saved passwords.
void displayPasswords(struct Password *allPasswords, int numPasswords) {
    printf("Here are all your saved passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("Website: %s\tPassword: %s\n", allPasswords[i].website, allPasswords[i].password);
    }
}

// Function to search for a password by website name.
void findPassword(struct Password *allPasswords, int numPasswords) {
    char website[MAX_LENGTH];
    printf("Enter the website name you want to find: ");
    fgets(website, MAX_LENGTH, stdin);
    website[strcspn(website, "\n")] = 0;

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(allPasswords[i].website, website) == 0) {
            printf("The password for %s is %s\n", allPasswords[i].website, allPasswords[i].password);
            return;
        }
    }

    printf("No password found for %s\n", website);
}

int main() {
    struct Password allPasswords[MAX_LENGTH];
    int numPasswords = 0;
    int choice;

    printf("Welcome to the password manager!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new password\n");
        printf("2. Display all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                addPassword(allPasswords, &numPasswords);
                break;
            case 2:
                displayPasswords(allPasswords, numPasswords);
                break;
            case 3:
                findPassword(allPasswords, numPasswords);
                break;
            case 4:
                printf("Quitting the password manager. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}