//FormAI DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100 // maximum number of passwords that can be stored
#define MAX_LENGTH 50 // maximum length of a password

// struct to store a single password
struct Password {
    char site[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

// functions to manage passwords
void addPassword(struct Password passwords[], int *numPasswords);
void viewPasswords(struct Password passwords[], int numPasswords);
void deletePassword(struct Password passwords[], int *numPasswords);
void changeMasterPassword(char masterPassword[]);

int main() {
    char masterPassword[MAX_LENGTH];
    printf("Enter master password: ");
    scanf("%s", masterPassword);
    
    // check if the master password is correct
    if (strcmp(masterPassword, "password123") != 0) {
        printf("Incorrect password. Exiting program.\n");
        return 0;
    }
    
    // create an array to store passwords
    struct Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;
    
    int choice;
    do {
        printf("\n1. Add a password\n");
        printf("2. View all passwords\n");
        printf("3. Delete a password\n");
        printf("4. Change master password\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPassword(passwords, &numPasswords);
                break;
            case 2:
                viewPasswords(passwords, numPasswords);
                break;
            case 3:
                deletePassword(passwords, &numPasswords);
                break;
            case 4:
                changeMasterPassword(masterPassword);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}

// function to add a password to the array
void addPassword(struct Password passwords[], int *numPasswords) {
    if (*numPasswords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }
    
    printf("Enter site name: ");
    scanf("%s", passwords[*numPasswords].site);
    
    printf("Enter username: ");
    scanf("%s", passwords[*numPasswords].username);
    
    printf("Enter password: ");
    scanf("%s", passwords[*numPasswords].password);
    
    (*numPasswords)++;
    
    printf("Password added successfully.\n");
}

// function to view all passwords in the array
void viewPasswords(struct Password passwords[], int numPasswords) {
    if (numPasswords == 0) {
        printf("No passwords added yet.\n");
        return;
    }
    
    printf("All passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("Site: %s, Username: %s, Password: %s\n", passwords[i].site, passwords[i].username, passwords[i].password);
    }
}

// function to delete a password from the array
void deletePassword(struct Password passwords[], int *numPasswords) {
    if (*numPasswords == 0) {
        printf("No passwords added yet.\n");
        return;
    }
    
    char site[MAX_LENGTH];
    printf("Enter site name: ");
    scanf("%s", site);
    
    int index = -1;
    for (int i = 0; i < *numPasswords; i++) {
        if (strcmp(passwords[i].site, site) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Site not found.\n");
        return;
    }
    
    for (int i = index; i < *numPasswords - 1; i++) {
        passwords[i] = passwords[i+1];
    }
    
    (*numPasswords)--;
    
    printf("Password deleted successfully.\n");
}

// function to change the master password
void changeMasterPassword(char masterPassword[]) {
    char oldPassword[MAX_LENGTH], newPassword[MAX_LENGTH];
    printf("Enter old password: ");
    scanf("%s", oldPassword);
    
    // check if the old password is correct
    if (strcmp(oldPassword, masterPassword) != 0) {
        printf("Incorrect password. Password not changed.\n");
        return;
    }
    
    printf("Enter new password: ");
    scanf("%s", newPassword);
    
    // update the master password
    strcpy(masterPassword, newPassword);
    
    printf("Master password changed successfully.\n");
}