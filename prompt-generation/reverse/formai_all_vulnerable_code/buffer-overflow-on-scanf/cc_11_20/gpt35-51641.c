//FormAI DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define Macro for maximum password length */
#define MAX_PASSWORD_LENGTH 30

/* Define Macro for maximum number of password entries */
#define MAX_ENTRIES 10

/* Create a struct to represent Password Entry */
struct PasswordEntry {
    char website[50];
    char username[30];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    struct PasswordEntry passwordEntries[MAX_ENTRIES];
    int numEntries = 0;

    while (1) {
        /* Print Menu */
        printf("\nPassword Manager\n");
        printf("-----------------\n");
        printf("1. Add Password Entry\n");
        printf("2. List All Password Entries\n");
        printf("3. Find Password Entry by Website\n");
        printf("4. Exit\n");

        /* Get User Input */
        printf("Enter Choice: ");
        int choice;
        scanf("%d", &choice);

        /* Process User Input */
        switch (choice) {
            case 1:
                /* Add Password Entry */
                if (numEntries >= MAX_ENTRIES) {
                    printf("Error: Maximum Number of Password Entries Reached!\n");
                    break;
                }
                struct PasswordEntry newEntry;
                printf("Enter Website: ");
                scanf("%s", newEntry.website);
                printf("Enter Username: ");
                scanf("%s", newEntry.username);
                printf("Enter Password: ");
                scanf("%s", newEntry.password);
                passwordEntries[numEntries++] = newEntry;
                printf("Password Entry Added Successfully!\n");
                break;
            case 2:
                /* List All Password Entries */
                if (numEntries == 0) {
                    printf("No Password Entries Found!\n");
                    break;
                }
                printf("%-30s %-20s %-20s\n", "Website", "Username", "Password");
                for (int i = 0; i < numEntries; i++) {
                    struct PasswordEntry entry = passwordEntries[i];
                    printf("%-30s %-20s %-20s\n", entry.website, entry.username, entry.password);
                }
                break;
            case 3:
                /* Find Password Entry by Website */
                if (numEntries == 0) {
                    printf("No Password Entries Found!\n");
                    break;
                }
                printf("Enter Website: ");
                char website[50];
                scanf("%s", website);
                int found = 0;
                for (int i = 0; i < numEntries; i++) {
                    struct PasswordEntry entry = passwordEntries[i];
                    if (strcmp(entry.website, website) == 0) {
                        printf("%-30s %-20s %-20s\n", "Website", "Username", "Password");
                        printf("%-30s %-20s %-20s\n", entry.website, entry.username, entry.password);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Password Entry not Found for Website: %s\n", website);
                }
                break;
            case 4:
                /* Exit */
                printf("Exiting Password Manager...\n");
                exit(0);
            default:
                /* Invalid Input */
                printf("Invalid Input, Try Again!\n");
        }
    }
    return 0;
}