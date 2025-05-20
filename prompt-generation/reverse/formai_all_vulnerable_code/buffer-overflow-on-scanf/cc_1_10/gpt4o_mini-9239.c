//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define MAX_ENTRIES 100
#define MAX_PASSWORD_LENGTH 50
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Entry;

void setPassword(char *password);
void clearScreen();
void addEntry(Entry entries[], int *count);
void viewEntries(Entry entries[], int count);
void deleteEntry(Entry entries[], int *count);
void printMenu();
void promptForEnterKey();

int main() {
    Entry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    while (1) {
        clearScreen();
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry(entries, &count);
                break;
            case 2:
                viewEntries(entries, count);
                break;
            case 3:
                deleteEntry(entries, &count);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                promptForEnterKey();
        }
    }
    return 0;
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape sequences to clear screen
}

void printMenu() {
    printf("=== Password Management System ===\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
}

void promptForEnterKey() {
    printf("Press ENTER to continue...");
    while (getchar() != '\n'); // Wait for Enter key
    getchar();
}

void setPassword(char *password) {
    struct termios oldt, newt;
    int ch;
    
    printf("Enter Password: ");
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO); // Disable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF && i < MAX_PASSWORD_LENGTH - 1) {
        password[i++] = (char)ch;
    }
    password[i] = '\0'; // Null terminate the string

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
    printf("\n"); // Move to next line after password entry
}

void addEntry(Entry entries[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Cannot add more entries. Maximum limit reached.\n");
        promptForEnterKey();
        return;
    }

    printf("Enter service name: ");
    scanf("%s", entries[*count].name);
    setPassword(entries[*count].password);
    (*count)++;
    printf("Password added successfully.\n");
    promptForEnterKey();
}

void viewEntries(Entry entries[], int count) {
    if (count == 0) {
        printf("No passwords stored.\n");
    } else {
        printf("=== Stored Passwords ===\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s\n", i + 1, entries[i].name);
        }
    }
    promptForEnterKey();
}

void deleteEntry(Entry entries[], int *count) {
    if (*count == 0) {
        printf("No entries to delete.\n");
        promptForEnterKey();
        return;
    }

    printf("Enter index of entry to delete (1 to %d): ", *count);
    int idx;
    scanf("%d", &idx);
    if (idx < 1 || idx > *count) {
        printf("Invalid index.\n");
    } else {
        for (int i = idx - 1; i < *count - 1; i++) {
            entries[i] = entries[i + 1]; // Shift entries
        }
        (*count)--;
        printf("Entry deleted successfully.\n");
    }
    promptForEnterKey();
}