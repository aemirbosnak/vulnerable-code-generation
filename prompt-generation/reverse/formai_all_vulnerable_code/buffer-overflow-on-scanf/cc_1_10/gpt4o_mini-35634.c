//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold password information
typedef struct PasswordEntry {
    char website[50];
    char username[50];
    char password[50];
} PasswordEntry;

// Function prototypes
void addPassword();
void displayPasswords();
void deletePassword();
void savePasswordsToFile();
void loadPasswordsFromFile();
int passwordEntryExists(const char *website);

// Global variables
PasswordEntry *entries = NULL;
int entryCount = 0;
const char *filename = "passwords.txt";

int main() {
    int choice;
    loadPasswordsFromFile();

    do {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. Display Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Save Passwords to File\n");
        printf("5. Load Passwords from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                savePasswordsToFile();
                break;
            case 5:
                loadPasswordsFromFile();
                break;
            case 6:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    // Cleanup
    free(entries);
    return 0;
}

void addPassword() {
    entries = realloc(entries, sizeof(PasswordEntry) * (entryCount + 1));
    if (entries == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    PasswordEntry *newEntry = &entries[entryCount];

    printf("Enter website: ");
    fgets(newEntry->website, 50, stdin);
    newEntry->website[strcspn(newEntry->website, "\n")] = 0; // Remove newline

    printf("Enter username: ");
    fgets(newEntry->username, 50, stdin);
    newEntry->username[strcspn(newEntry->username, "\n")] = 0; // Remove newline

    printf("Enter password: ");
    fgets(newEntry->password, 50, stdin);
    newEntry->password[strcspn(newEntry->password, "\n")] = 0; // Remove newline

    entryCount++;
    printf("Password added successfully!\n");
}

void displayPasswords() {
    if (entryCount == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Website: %s, Username: %s, Password: %s\n",
               entries[i].website, entries[i].username, entries[i].password);
    }
}

void deletePassword() {
    if (entryCount == 0) {
        printf("No passwords to delete.\n");
        return;
    }

    char website[50];
    printf("Enter website to delete: ");
    fgets(website, 50, stdin);
    website[strcspn(website, "\n")] = 0; // Remove newline

    int found = -1;
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        for (int i = found; i < entryCount - 1; i++) {
            entries[i] = entries[i + 1]; // Shift entries left
        }
        entryCount--;
        entries = realloc(entries, sizeof(PasswordEntry) * entryCount); // Resize array
        printf("Password deleted successfully!\n");
    } else {
        printf("Website not found!\n");
    }
}

void savePasswordsToFile() {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open file for writing!\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s\n%s\n%s\n",
                entries[i].website, entries[i].username, entries[i].password);
    }

    fclose(file);
    printf("Passwords saved to file successfully!\n");
}

void loadPasswordsFromFile() {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file for reading! Starting with no entries.\n");
        return;
    }

    while (!feof(file)) {
        entries = realloc(entries, sizeof(PasswordEntry) * (entryCount + 1));
        if (entries == NULL) {
            printf("Memory allocation failed while loading!\n");
            fclose(file);
            return;
        }

        PasswordEntry *newEntry = &entries[entryCount];
        fgets(newEntry->website, 50, file);
        fgets(newEntry->username, 50, file);
        fgets(newEntry->password, 50, file);

        newEntry->website[strcspn(newEntry->website, "\n")] = 0; // Remove newline
        newEntry->username[strcspn(newEntry->username, "\n")] = 0; // Remove newline
        newEntry->password[strcspn(newEntry->password, "\n")] = 0; // Remove newline

        entryCount++;
    }

    fclose(file);
    printf("Passwords loaded from file successfully!\n");
}