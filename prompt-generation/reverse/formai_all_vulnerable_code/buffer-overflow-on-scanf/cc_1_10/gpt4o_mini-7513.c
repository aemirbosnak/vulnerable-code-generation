//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 100
#define DATA_FILE "passwords.txt"

typedef struct {
    char name[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwords[MAX_PASSWORDS];
int passwordCount = 0;

void displayMenu();
void addPassword();
void viewPasswords();
void deletePassword();
void savePasswords();
void loadPasswords();
void clearInputBuffer();

int main() {
    loadPasswords();
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                savePasswords();
                printf("Passwords saved! Goodbye!\n");
                break;
            case 0:
                printf("Exiting Program. Bye! Stay safe and secure!\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n--- Password Manager ---\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Save Passwords\n");
    printf("0. Exit\n");
}

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Cannot add more passwords! Maximum limit reached!\n");
        return;
    }
    
    printf("Enter the name/website for the password: ");
    fgets(passwords[passwordCount].name, MAX_LENGTH, stdin);
    strtok(passwords[passwordCount].name, "\n"); // Remove newline character

    printf("Enter the password: ");
    fgets(passwords[passwordCount].password, MAX_LENGTH, stdin);
    strtok(passwords[passwordCount].password, "\n"); // Remove newline character
    
    passwordCount++;
    printf("Password added successfully! You rock!\n");
}

void viewPasswords() {
    if (passwordCount == 0) {
        printf("No passwords saved yet!\n");
        return;
    }
    printf("\n--- Saved Passwords ---\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("%d. %s: %s\n", i + 1, passwords[i].name, passwords[i].password);
    }
}

void deletePassword() {
    if (passwordCount == 0) {
        printf("No passwords to delete! Put on those creativity glasses and add some first!\n");
        return;
    }
    
    int index;
    printf("Enter the number of the password to delete: ");
    scanf("%d", &index);
    clearInputBuffer();

    if (index < 1 || index > passwordCount) {
        printf("Invalid index! Choose wisely next time!\n");
        return;
    }

    for (int i = index - 1; i < passwordCount - 1; i++) {
        passwords[i] = passwords[i + 1];
    }
    passwordCount--;
    printf("Password deleted successfully! Out with the old, in with the new!\n");
}

void savePasswords() {
    FILE *file = fopen(DATA_FILE, "w");
    if (file == NULL) {
        printf("Error opening file for saving! Keep those passwords secure!\n");
        return;
    }
    
    for (int i = 0; i < passwordCount; i++) {
        fprintf(file, "%s\n%s\n", passwords[i].name, passwords[i].password);
    }
    
    fclose(file);
    printf("Passwords saved to %s successfully! Your secret is safe with us!\n", DATA_FILE);
}

void loadPasswords() {
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL) {
        printf("No previous password data found. Let's make this exciting and start fresh!\n");
        return;
    }

    while (fgets(passwords[passwordCount].name, MAX_LENGTH, file) != NULL) {
        strtok(passwords[passwordCount].name, "\n"); // Remove newline
        fgets(passwords[passwordCount].password, MAX_LENGTH, file);
        strtok(passwords[passwordCount].password, "\n"); // Remove newline
        passwordCount++;
    }
    
    fclose(file);
    printf("Loaded %d passwords. You're all set!\n", passwordCount);
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Flush input buffer
}