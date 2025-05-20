//FormAI DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 50
#define MAX_ENTRIES 100

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Entry;

int num_entries = 0;
Entry entries[MAX_ENTRIES];

void printMenu() {
    printf("1. Add entry\n");
    printf("2. Show all entries\n");
    printf("3. Delete entry\n");
    printf("4. Quit\n");
}

int isValidPassword(char* password) {
    int len = strlen(password);
    if (len < 8 || len > 20) {
        return 0;
    }
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    for (int i = 0; i < len; i++) {
        char c = password[i];
        if (c >= 'A' && c <= 'Z') {
            has_upper = 1;
        } else if (c >= 'a' && c <= 'z') {
            has_lower = 1;
        } else if (c >= '0' && c <= '9') {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }
    if (has_upper && has_lower && has_digit && has_special) {
        return 1;
    }
    return 0;
}

int addEntry() {
    printf("Enter username (max %d characters): ", MAX_USERNAME_LENGTH);
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(username, entries[i].username) == 0) {
            printf("Error: username already exists.\n");
            return -1;
        }
    }
    printf("Enter password (between 8 and 20 characters): ");
    char password[MAX_PASSWORD_LENGTH];
    scanf("%s", password);
    if (!isValidPassword(password)) {
        printf("Error: invalid password.\n");
        return -1;
    }
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached (%d).\n", MAX_ENTRIES);
        return -1;
    }
    Entry new_entry;
    strcpy(new_entry.username, username);
    strcpy(new_entry.password, password);
    entries[num_entries] = new_entry;
    num_entries++;
    printf("Entry added successfully.\n");
    return 0;
}

void showAllEntries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }
    printf("All entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("Username: %s\nPassword: %s\n", entries[i].username, entries[i].password);
    }
}

int deleteEntry() {
    if (num_entries == 0) {
        printf("Error: no entries to delete.\n");
        return -1;
    }
    printf("Enter username to delete: ");
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(username, entries[i].username) == 0) {
            for (int j = i + 1; j < num_entries; j++) {
                entries[j - 1] = entries[j];
            }
            num_entries--;
            printf("Entry deleted successfully.\n");
            return 0;
        }
    }
    printf("Error: username not found.\n");
    return -1;
}

int main() {
    while (1) {
        printMenu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                showAllEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}