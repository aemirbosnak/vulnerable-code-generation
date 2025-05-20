//FormAI DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORDS 50
#define MAX_LENGTH 20

/* Structure to hold password and corresponding website */
struct Password {
    char website[MAX_LENGTH];
    char password[MAX_LENGTH];
};

/* Function to add a new password */
void addPassword(struct Password passwords[], int *num_passwords) {
    if (*num_passwords >= MAX_PASSWORDS) {
        printf("\nError: Maximum number of passwords reached.\n");
        return;
    }

    char website[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("\nEnter website name: ");
    scanf("%s", website);
    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[*num_passwords].website, website);
    strcpy(passwords[*num_passwords].password, password);

    printf("\nPassword added successfully!\n");
    (*num_passwords)++;
}

/* Function to list all saved passwords */
void listPasswords(struct Password passwords[], int num_passwords) {
    if (num_passwords == 0) {
        printf("\nNo passwords saved.\n");
        return;
    }

    printf("\nSaved Passwords:\n");
    printf("%-20s %-20s\n", "Website", "Password");
    for (int i = 0; i < num_passwords; i++) {
        printf("%-20s %-20s\n", passwords[i].website, passwords[i].password);
    }
}

/* Function to search for a password */
void searchPasswords(struct Password passwords[], int num_passwords) {
    if (num_passwords == 0) {
        printf("\nNo passwords saved.\n");
        return;
    }

    char website[MAX_LENGTH];
    printf("\nEnter website name to search: ");
    scanf("%s", website);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            printf("\nPassword for %s: %s\n", website, passwords[i].password);
            return;
        }
    }

    printf("\nNo password found for %s.\n", website);
}

/* Function to delete a password */
void deletePassword(struct Password passwords[], int *num_passwords) {
    if (*num_passwords == 0) {
        printf("\nNo passwords saved.\n");
        return;
    }

    char website[MAX_LENGTH];
    printf("\nEnter website name to delete: ");
    scanf("%s", website);

    for (int i = 0; i < *num_passwords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            for (int j = i; j < *num_passwords - 1; j++) {
                strcpy(passwords[j].website, passwords[j+1].website);
                strcpy(passwords[j].password, passwords[j+1].password);
            }
            (*num_passwords)--;
            printf("\nPassword for %s deleted successfully.\n", website);
            return;
        }
    }

    printf("\nNo password found for %s.\n", website);
}

int main() {
    struct Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    int choice = -1;

    while (choice != 0) {
        printf("\nPassword Manager Menu:\n");
        printf("-----------------------\n");
        printf("1. Add Password\n");
        printf("2. List Passwords\n");
        printf("3. Search Password\n");
        printf("4. Delete Password\n");
        printf("0. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword(passwords, &num_passwords);
                break;
            case 2:
                listPasswords(passwords, num_passwords);
                break;
            case 3:
                searchPasswords(passwords, num_passwords);
                break;
            case 4:
                deletePassword(passwords, &num_passwords);
                break;
            case 0:
                printf("\nExiting Password Manager...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}