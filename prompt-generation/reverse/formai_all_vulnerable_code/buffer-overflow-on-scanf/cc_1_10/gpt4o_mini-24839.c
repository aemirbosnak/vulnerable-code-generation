//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 256

typedef struct {
    char website[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwords[MAX_PASSWORDS];
int count = 0;

void displayMenu();
void addPassword();
void viewPasswords();
void removePassword();
void clearInputBuffer();
void handleInvalidOption();

void displayMenu() {
    printf("\nPassword Manager\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Remove Password\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void handleInvalidOption() {
    printf("Invalid option. Please try again.\n");
    displayMenu();
}

void recursiveMenu() {
    int choice;
    displayMenu();
    
    if (scanf("%d", &choice) != 1) {
        clearInputBuffer();
        handleInvalidOption();
        recursiveMenu(); // Recur for invalid entry
        return;
    }
    
    clearInputBuffer(); // Clear buffer after input

    switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            viewPasswords();
            break;
        case 3:
            removePassword();
            break;
        case 4:
            printf("Exiting Password Manager.\n");
            exit(0);
        default:
            handleInvalidOption();
            break;
    }

    recursiveMenu(); // Go back to menu after action
}

void addPassword() {
    if (count >= MAX_PASSWORDS) {
        printf("Password storage is full.\n");
        return;
    }

    printf("Enter website: ");
    fgets(passwords[count].website, MAX_LENGTH, stdin);
    passwords[count].website[strcspn(passwords[count].website, "\n")] = 0; // Remove newline

    printf("Enter password: ");
    fgets(passwords[count].password, MAX_LENGTH, stdin);
    passwords[count].password[strcspn(passwords[count].password, "\n")] = 0; // Remove newline

    count++;
    printf("Password added successfully.\n");
}

void viewPasswords() {
    if (count == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Website: %s | Password: %s\n", i + 1, passwords[i].website, passwords[i].password);
    }
}

void removePassword() {
    if (count == 0) {
        printf("No passwords to remove.\n");
        return;
    }

    int index;
    printf("Enter the number of the password to remove (1 to %d): ", count);
    if (scanf("%d", &index) != 1 || index < 1 || index > count) {
        clearInputBuffer();
        printf("Invalid index.\n");
        return;
    }

    clearInputBuffer(); // Clear input buffer after reading the number

    index--; // Convert to zero-based index
    printf("Removing password for %s...\n", passwords[index].website);

    for (int i = index; i < count - 1; i++) {
        passwords[i] = passwords[i + 1]; // Shift entries down
    }
    count--;

    printf("Password removed successfully.\n");
}

int main() {
    printf("Welcome to the Password Manager!\n");
    recursiveMenu(); // Start the menu

    return 0;
}