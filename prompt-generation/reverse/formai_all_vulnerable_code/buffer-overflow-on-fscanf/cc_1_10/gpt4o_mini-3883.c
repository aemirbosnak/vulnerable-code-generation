//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 100
#define FILENAME "passwords.txt"

typedef struct {
    char name[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

// Function prototypes
void addPassword();
void viewPasswords();
void deletePassword();
void searchPassword();
void loadPasswords(PasswordEntry entries[], int *count);
void savePasswords(PasswordEntry entries[], int count);

int main() {
    int choice;
    
    while (1) {
        printf("\nPassword Management System\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Search Password\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
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
                searchPassword();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void addPassword() {
    PasswordEntry entry;
    FILE *file = fopen(FILENAME, "a");
    
    if (!file) {
        perror("Unable to open file");
        return;
    }
    
    printf("Enter website/service name: ");
    scanf("%s", entry.name);
    printf("Enter password: ");
    scanf("%s", entry.password);
    
    fprintf(file, "%s,%s\n", entry.name, entry.password);
    fclose(file);
    printf("Password added successfully!\n");
}

void viewPasswords() {
    PasswordEntry entries[MAX_PASSWORDS];
    int count = 0;
    loadPasswords(entries, &count);
    
    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("%s : %s\n", entries[i].name, entries[i].password);
    }
}

void deletePassword() {
    PasswordEntry entries[MAX_PASSWORDS];
    PasswordEntry entry;
    int count = 0;
    
    loadPasswords(entries, &count);
    
    char nameToDelete[MAX_LENGTH];
    printf("Enter the name of the website/service to delete: ");
    scanf("%s", nameToDelete);
    
    FILE *file = fopen(FILENAME, "w");
    
    if (!file) {
        perror("Unable to open file");
        return;
    }
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].name, nameToDelete) != 0) {
            fprintf(file, "%s,%s\n", entries[i].name, entries[i].password);
        } else {
            found = 1;
        }
    }
    
    fclose(file);
    
    if (found) {
        printf("Password for '%s' deleted successfully!\n", nameToDelete);
    } else {
        printf("No entry found for '%s'.\n", nameToDelete);
    }
}

void searchPassword() {
    PasswordEntry entries[MAX_PASSWORDS];
    int count = 0;
    loadPasswords(entries, &count);
    
    char nameToSearch[MAX_LENGTH];
    printf("Enter the name of the website/service to search for: ");
    scanf("%s", nameToSearch);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].name, nameToSearch) == 0) {
            printf("Password for '%s' is: %s\n", entries[i].name, entries[i].password);
            return;
        }
    }
    printf("No entry found for '%s'.\n", nameToSearch);
}

void loadPasswords(PasswordEntry entries[], int *count) {
    FILE *file = fopen(FILENAME, "r");
    
    if (!file) {
        *count = 0;
        return;
    }
    
    while (fscanf(file, "%[^,],%s\n", entries[*count].name, entries[*count].password) != EOF) {
        (*count)++;
    }
    
    fclose(file);
}

void savePasswords(PasswordEntry entries[], int count) {
    FILE *file = fopen(FILENAME, "w");
    
    if (!file) {
        perror("Unable to open file");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s\n", entries[i].name, entries[i].password);
    }
    
    fclose(file);
}