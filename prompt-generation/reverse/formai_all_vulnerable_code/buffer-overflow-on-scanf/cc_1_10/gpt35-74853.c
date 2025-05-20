//FormAI DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 20

// Function prototypes
void printMenu();
void addPassword(char *username, char *password, char *notes);
void viewPasswords();
void filterPasswords(char *key);
void deletePassword(int id);

// Struct for passwords
struct Password {
    int id;
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char notes[MAX_LENGTH];
};

// Global variables
struct Password passwords[100];
int passwordCount = 0;

int main() {
    
    int choice;
    char key[MAX_LENGTH];
    
    // Loop until user chooses to exit
    while (1) {
        
        // Print menu and get user choice
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Add password
                {
                    char username[MAX_LENGTH];
                    char password[MAX_LENGTH];
                    char notes[MAX_LENGTH];
                    
                    printf("Enter username: ");
                    scanf("%s", username);
                    printf("Enter password: ");
                    scanf("%s", password);
                    printf("Enter notes: ");
                    scanf("%s", notes);
                    
                    addPassword(username, password, notes);
                    break;
                }
            case 2:
                // View all passwords
                viewPasswords();
                break;
            case 3:
                // Filter passwords by key
                printf("Enter key: ");
                scanf("%s", key);
                filterPasswords(key);
                break;
            case 4:
                // Delete password
                {
                    int id;
                    printf("Enter ID of password to delete: ");
                    scanf("%d", &id);
                    deletePassword(id);
                    break;
                }
            case 5:
                // Exit program
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    return 0;
}

void printMenu() {
    printf("\n===================================\n");
    printf("Password Manager\n");
    printf("===================================\n");
    printf("1. Add password\n");
    printf("2. View all passwords\n");
    printf("3. Filter passwords by key\n");
    printf("4. Delete password\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void addPassword(char *username, char *password, char *notes) {
    // Create new password
    struct Password newPassword;
    newPassword.id = passwordCount + 1;
    strncpy(newPassword.username, username, MAX_LENGTH);
    strncpy(newPassword.password, password, MAX_LENGTH);
    strncpy(newPassword.notes, notes, MAX_LENGTH);
    
    // Add new password to array
    passwords[passwordCount++] = newPassword;
    
    printf("Password added!\n");
}

void viewPasswords() {
    if (passwordCount == 0) {
        printf("No passwords found!\n");
        return;
    }
    
    printf("\n===================================\n");
    printf("ID\tUsername\tPassword\tNotes\n");
    printf("===================================\n");
    
    // Print all passwords
    for (int i = 0; i < passwordCount; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n", passwords[i].id, passwords[i].username, passwords[i].password, passwords[i].notes);
    }
}

void filterPasswords(char *key) {
    if (strlen(key) == 0) {
        printf("No key entered!\n");
        return;
    }
    
    int foundCount = 0;
    
    printf("\n===================================\n");
    printf("ID\tUsername\tPassword\tNotes\n");
    printf("===================================\n");
    
    // Print only passwords that contain key
    for (int i = 0; i < passwordCount; i++) {
        if (strstr(passwords[i].username, key) != NULL || strstr(passwords[i].password, key) != NULL || strstr(passwords[i].notes, key) != NULL) {
            printf("%d\t%s\t\t%s\t\t%s\n", passwords[i].id, passwords[i].username, passwords[i].password, passwords[i].notes);
            foundCount++;
        }
    }
    
    if (foundCount == 0) {
        printf("No passwords found!\n");
    }
}

void deletePassword(int id) {
    int deleteIndex = -1;
    
    // Find index of password with given ID
    for (int i = 0; i < passwordCount; i++) {
        if (passwords[i].id == id) {
            deleteIndex = i;
            break;
        }
    }
    
    if (deleteIndex == -1) {
        printf("Password not found!\n");
        return;
    }
    
    // Shift remaining passwords in array
    for (int i = deleteIndex; i < passwordCount - 1; i++) {
        passwords[i] = passwords[i+1];
    }
    
    passwordCount--;
    
    printf("Password deleted!\n");
}