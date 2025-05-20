//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 256

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_PASSWORDS];
int passwordCount = 0;

void addPassword();
void viewPasswords();
void deletePassword();
void displayStatistics();
void writeToFile();
void readFromFile();

int main() {
    int choice;
    readFromFile();

    do {
        printf("\n--- Password Management System ---\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. View Password Statistics\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

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
                displayStatistics();
                break;
            case 5:
                writeToFile();
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password list is full. Cannot add more passwords.\n");
        return;
    }
    
    PasswordEntry entry;
    printf("Enter website: ");
    fgets(entry.website, MAX_LENGTH, stdin);
    entry.website[strcspn(entry.website, "\n")] = 0; // Remove trailing newline
    
    printf("Enter username: ");
    fgets(entry.username, MAX_LENGTH, stdin);
    entry.username[strcspn(entry.username, "\n")] = 0; // Remove trailing newline

    printf("Enter password: ");
    fgets(entry.password, MAX_LENGTH, stdin);
    entry.password[strcspn(entry.password, "\n")] = 0; // Remove trailing newline

    passwordList[passwordCount++] = entry;
    printf("Password added successfully!\n");
}

void viewPasswords() {
    if (passwordCount == 0) {
        printf("No passwords saved.\n");
        return;
    }

    printf("\n--- Stored Passwords ---\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("Website: %s, Username: %s, Password: %s\n", 
                passwordList[i].website, 
                passwordList[i].username, 
                passwordList[i].password);
    }
}

void deletePassword() {
    char website[MAX_LENGTH];
    printf("Enter the website of the password to delete: ");
    fgets(website, MAX_LENGTH, stdin);
    website[strcspn(website, "\n")] = 0; // Remove trailing newline

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordList[i].website, website) == 0) {
            for (int j = i; j < passwordCount - 1; j++) {
                passwordList[j] = passwordList[j + 1];
            }
            passwordCount--;
            printf("Password for %s has been deleted.\n", website);
            return;
        }
    }
    printf("Password for %s not found.\n", website);
}

void displayStatistics() {
    if (passwordCount == 0) {
        printf("No passwords saved. Statistics cannot be generated.\n");
        return;
    }

    int minLength = MAX_LENGTH, maxLength = 0;
    float totalLength = 0;

    for (int i = 0; i < passwordCount; i++) {
        int length = strlen(passwordList[i].password);
        if (length < minLength) minLength = length;
        if (length > maxLength) maxLength = length;
        totalLength += length;
    }

    float averageLength = totalLength / passwordCount;

    printf("\n--- Password Statistics ---\n");
    printf("Total Passwords: %d\n", passwordCount);
    printf("Shortest Password Length: %d\n", minLength);
    printf("Longest Password Length: %d\n", maxLength);
    printf("Average Password Length: %.2f\n", averageLength);
}

void writeToFile() {
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Error saving passwords to file.\n");
        return;
    }

    for (int i = 0; i < passwordCount; i++) {
        fprintf(file, "%s\n%s\n%s\n", 
                passwordList[i].website, 
                passwordList[i].username, 
                passwordList[i].password);
    }
    fclose(file);
}

void readFromFile() {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        return;  // If the file doesn't exist, we start fresh.
    }

    while (fscanf(file, "%255s %255s %255s", 
                  passwordList[passwordCount].website, 
                  passwordList[passwordCount].username, 
                  passwordList[passwordCount].password) != EOF) {
        passwordCount++;
        if (passwordCount >= MAX_PASSWORDS) {
            break;
        }
    }
    fclose(file);
}