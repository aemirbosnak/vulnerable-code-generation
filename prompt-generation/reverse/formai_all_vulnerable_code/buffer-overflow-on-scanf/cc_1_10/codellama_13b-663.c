//Code Llama-13B DATASET v1.0 Category: Password management ; Style: realistic
/*
 * Program: Password Management
 * Description: This program allows the user to manage their passwords securely.
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for the maximum number of passwords and the length of each password
#define MAX_PASSWORDS 100
#define PASSWORD_LEN 16

// Define the struct for a password
typedef struct {
    char name[16];
    char password[PASSWORD_LEN + 1];
} Password;

// Function to generate a random password
void generatePassword(char *password) {
    int i;
    for (i = 0; i < PASSWORD_LEN; i++) {
        password[i] = 'a' + (rand() % 26);
    }
    password[i] = '\0';
}

// Function to store the passwords
void storePasswords(Password passwords[], int numPasswords) {
    FILE *fp;
    fp = fopen("passwords.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    for (int i = 0; i < numPasswords; i++) {
        fprintf(fp, "%s %s\n", passwords[i].name, passwords[i].password);
    }
    fclose(fp);
}

// Function to load the passwords
void loadPasswords(Password passwords[], int *numPasswords) {
    FILE *fp;
    fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    char name[16];
    char password[PASSWORD_LEN + 1];
    while (fscanf(fp, "%s %s", name, password) == 2) {
        strcpy(passwords[*numPasswords].name, name);
        strcpy(passwords[*numPasswords].password, password);
        *numPasswords = *numPasswords + 1;
    }
    fclose(fp);
}

// Function to retrieve a password
void retrievePassword(Password passwords[], int numPasswords) {
    int i;
    char name[16];
    printf("Enter the name of the password you want to retrieve: ");
    scanf("%s", name);
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("The password for %s is %s\n", name, passwords[i].password);
            return;
        }
    }
    printf("The password for %s could not be found\n", name);
}

// Function to delete a password
void deletePassword(Password passwords[], int *numPasswords) {
    int i;
    char name[16];
    printf("Enter the name of the password you want to delete: ");
    scanf("%s", name);
    for (i = 0; i < *numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            for (int j = i; j < *numPasswords - 1; j++) {
                passwords[j] = passwords[j + 1];
            }
            *numPasswords = *numPasswords - 1;
            break;
        }
    }
}

// Function to update a password
void updatePassword(Password passwords[], int *numPasswords) {
    int i;
    char name[16];
    char newPassword[PASSWORD_LEN + 1];
    printf("Enter the name of the password you want to update: ");
    scanf("%s", name);
    for (i = 0; i < *numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("Enter the new password: ");
            scanf("%s", newPassword);
            strcpy(passwords[i].password, newPassword);
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    // Load the passwords from the file
    loadPasswords(passwords, &numPasswords);

    // Print the menu
    printf("1. Add a new password\n");
    printf("2. Retrieve a password\n");
    printf("3. Delete a password\n");
    printf("4. Update a password\n");
    printf("5. Quit\n");

    // Get the user's choice
    int choice;
    scanf("%d", &choice);

    // Perform the chosen action
    switch (choice) {
        case 1:
            // Add a new password
            if (numPasswords < MAX_PASSWORDS) {
                char name[16];
                char password[PASSWORD_LEN + 1];
                printf("Enter the name of the password: ");
                scanf("%s", name);
                generatePassword(password);
                strcpy(passwords[numPasswords].name, name);
                strcpy(passwords[numPasswords].password, password);
                numPasswords++;
            } else {
                printf("Maximum number of passwords reached\n");
            }
            break;
        case 2:
            // Retrieve a password
            retrievePassword(passwords, numPasswords);
            break;
        case 3:
            // Delete a password
            deletePassword(passwords, &numPasswords);
            break;
        case 4:
            // Update a password
            updatePassword(passwords, &numPasswords);
            break;
        case 5:
            // Quit
            return 0;
            break;
        default:
            printf("Invalid choice\n");
    }

    // Store the passwords back to the file
    storePasswords(passwords, numPasswords);

    return 0;
}