//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASS_LEN 128
#define MAX_ENTRIES 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    char password[MAX_PASS_LEN];
} Entry;

Entry passwordVault[MAX_ENTRIES];
int entryCount = 0;

void clearScreen() {
    printf("\033[H\033[J");
}

void printHeader() {
    clearScreen();
    printf("=====================================\n");
    printf("     Cyberpunk Password Vault        \n");
    printf("=====================================\n");
}

void generateRandomPassword(char *password, int length) {
    const char *charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % (strlen(charset) - 1)];
    }
    password[length] = '\0';
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Vault is full! Can't add more entries.\n");
        return;
    }

    Entry newEntry;
    printf("Enter a name for the entry: ");
    scanf("%s", newEntry.name);

    // Generate a random password
    generateRandomPassword(newEntry.password, 12);
    
    passwordVault[entryCount++] = newEntry;

    printf("Entry \"%s\" added! Password: %s\n", newEntry.name, newEntry.password);
}

void displayEntries() {
    printHeader();
    if (entryCount == 0) {
        printf("No entries in the vault.\n");
        return;
    }
    
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d: %s | Password: %s\n", i + 1, passwordVault[i].name, passwordVault[i].password);
    }
    printf("\nPress Enter to continue...");
    getchar();
    getchar(); // wait for user to press Enter
}

void deleteEntry() {
    printHeader();
    if (entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int index;
    printf("Select entry number to delete (1-%d): ", entryCount);
    scanf("%d", &index);
    
    if (index < 1 || index > entryCount) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = index - 1; i < entryCount - 1; i++) {
        passwordVault[i] = passwordVault[i + 1];
    }
    entryCount--;
    printf("Entry deleted successfully.\n");
}

void mainMenu() {
    int choice;

    while (1) {
        printHeader();
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEntry(); break;
            case 2: displayEntries(); break;
            case 3: deleteEntry(); break;
            case 4: 
                printf("Shutting down...\n");
                exit(0);
            default: 
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for random password generation
    mainMenu();
    return 0;
}