//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_PASS_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASS_LENGTH];
} PasswordEntry;

typedef struct {
    PasswordEntry *entries;
    size_t count;
    size_t capacity;
} PasswordManager;

void initPasswordManager(PasswordManager *pm) {
    pm->count = 0;
    pm->capacity = 2;
    pm->entries = malloc(pm->capacity * sizeof(PasswordEntry));
}

void addPassword(PasswordManager *pm, const char *name, const char *password) {
    if (pm->count >= pm->capacity) {
        pm->capacity *= 2;
        pm->entries = realloc(pm->entries, pm->capacity * sizeof(PasswordEntry));
    }
    strncpy(pm->entries[pm->count].name, name, MAX_NAME_LENGTH);
    strncpy(pm->entries[pm->count].password, password, MAX_PASS_LENGTH);
    pm->count++;
}

void deletePassword(PasswordManager *pm, const char *name) {
    for (size_t i = 0; i < pm->count; i++) {
        if (strcmp(pm->entries[i].name, name) == 0) {
            for (size_t j = i; j < pm->count - 1; j++) {
                pm->entries[j] = pm->entries[j + 1];
            }
            pm->count--;
            printf("Password for '%s' deleted.\n", name);
            return;
        }
    }
    printf("Password for '%s' not found.\n", name);
}

void retrievePassword(const PasswordManager *pm, const char *name) {
    for (size_t i = 0; i < pm->count; i++) {
        if (strcmp(pm->entries[i].name, name) == 0) {
            printf("Password for '%s': %s\n", name, pm->entries[i].password);
            return;
        }
    }
    printf("Password for '%s' not found.\n", name);
}

void freePasswordManager(PasswordManager *pm) {
    free(pm->entries);
}

void displayMenu() {
    printf("Password Manager\n");
    printf("1. Add Password\n");
    printf("2. Retrieve Password\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    PasswordManager pm;
    initPasswordManager(&pm);
    
    int option;
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASS_LENGTH];

    while (1) {
        displayMenu();
        scanf("%d", &option);
        getchar(); // Clear newline character

        switch (option) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter password: ");
                fgets(password, MAX_PASS_LENGTH, stdin);
                password[strcspn(password, "\n")] = 0; // Remove newline
                addPassword(&pm, name, password);
                printf("Password added successfully!\n");
                break;

            case 2:
                printf("Enter name to retrieve password: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                retrievePassword(&pm, name);
                break;

            case 3:
                printf("Enter name to delete password: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                deletePassword(&pm, name);
                break;

            case 4:
                freePasswordManager(&pm);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}