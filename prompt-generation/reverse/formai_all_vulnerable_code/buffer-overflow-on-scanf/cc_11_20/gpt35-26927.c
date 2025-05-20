//FormAI DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 20
#define MAX_ENTRIES 10

struct entry {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    struct entry passwordEntries[MAX_ENTRIES];
    int numEntries = 0;
    int i;
    
    while (1) {
        char command;
        printf("Enter a command (a, d, l, e, q): ");
        scanf(" %c", &command);
        switch (command) {
            case 'a': // Add an entry
                if (numEntries < MAX_ENTRIES) {
                    struct entry newEntry;
                    printf("Enter username: ");
                    scanf("%s", newEntry.username);
                    printf("Enter password: ");
                    scanf("%s", newEntry.password);
                    passwordEntries[numEntries++] = newEntry;
                    printf("Entry added successfully.\n");
                } else {
                    printf("Sorry, the password manager is full.\n");
                }
                break;
            case 'd': // Delete an entry
                if (numEntries > 0) {
                    char usernameToDelete[MAX_USERNAME_LENGTH];
                    printf("Enter username to delete: ");
                    scanf("%s", usernameToDelete);
                    for (i = 0; i < numEntries; i++) {
                        if (strcmp(passwordEntries[i].username, usernameToDelete) == 0) {
                            // Delete the entry by shifting all entries after it one spot to the left
                            int j;
                            for (j = i; j < numEntries - 1; j++) {
                                passwordEntries[j] = passwordEntries[j+1];
                            }
                            numEntries--;
                            printf("Entry deleted successfully.\n");
                            break;
                        }
                    }
                    if (i == numEntries) {
                        printf("Sorry, username not found.\n");
                    }
                } else {
                    printf("Sorry, there are no entries to delete.\n");
                }
                break;
            case 'l': // List all entries
                if (numEntries > 0) {
                    printf("Username\tPassword\n");
                    for (i = 0; i < numEntries; i++) {
                        printf("%s\t\t%s\n", passwordEntries[i].username, passwordEntries[i].password);
                    }
                } else {
                    printf("Sorry, there are no entries.\n");
                }
                break;
            case 'e': // Edit an entry
                if (numEntries > 0) {
                    char usernameToEdit[MAX_USERNAME_LENGTH];
                    printf("Enter username to edit: ");
                    scanf("%s", usernameToEdit);
                    for (i = 0; i < numEntries; i++) {
                        if (strcmp(passwordEntries[i].username, usernameToEdit) == 0) {
                            printf("Enter new password: ");
                            scanf("%s", passwordEntries[i].password);
                            printf("Password updated successfully.\n");
                            break;
                        }
                    }
                    if (i == numEntries) {
                        printf("Sorry, username not found.\n");
                    }
                } else {
                    printf("Sorry, there are no entries to edit.\n");
                }
                break;
            case 'q': // Quit the program
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid command. Please try again.\n");
        }
    }
    return 0;
}