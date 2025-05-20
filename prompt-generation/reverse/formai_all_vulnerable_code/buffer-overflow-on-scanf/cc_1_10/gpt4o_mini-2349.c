//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordManager[MAX_PASSWORDS];
int passwordCount = 0;

void encrypt(char *str) {
    int key = 3; // Simple encryption key
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] + key;
    }
}

void decrypt(char *str) {
    int key = 3; // Simple decryption key
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] - key;
    }
}

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password storage is full!\n");
        return;
    }
    PasswordEntry newEntry;
    printf("Enter website: ");
    scanf("%s", newEntry.website);
    printf("Enter username: ");
    scanf("%s", newEntry.username);
    printf("Enter password: ");
    scanf("%s", newEntry.password);
    
    encrypt(newEntry.password); // Encrypt password before storing
    passwordManager[passwordCount++] = newEntry;

    printf("Password added successfully!\n");
}

void viewPasswords() {
    if (passwordCount == 0) {
        printf("No passwords stored!\n");
        return;
    }
    printf("\nStored Passwords:\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("Website: %s, Username: %s, Password: ", passwordManager[i].website, passwordManager[i].username);
        char decryptedPassword[MAX_LENGTH];
        strcpy(decryptedPassword, passwordManager[i].password);
        decrypt(decryptedPassword);
        printf("%s\n", decryptedPassword);
    }
}

void deletePassword() {
    char website[MAX_LENGTH];
    printf("Enter the website of the password you want to delete: ");
    scanf("%s", website);
    int found = 0;

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordManager[i].website, website) == 0) {
            for (int j = i; j < passwordCount - 1; j++) {
                passwordManager[j] = passwordManager[j + 1];
            }
            passwordCount--;
            found = 1;
            printf("Password for website %s deleted successfully!\n", website);
            break;
        }
    }
    if (!found) {
        printf("No password found for website %s!\n", website);
    }
}

void searchPassword() {
    char website[MAX_LENGTH];
    printf("Enter the website of the password you want to search: ");
    scanf("%s", website);
    int found = 0;

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordManager[i].website, website) == 0) {
            printf("Found Password:\n");
            printf("Website: %s, Username: %s, Password: ", passwordManager[i].website, passwordManager[i].username);
            char decryptedPassword[MAX_LENGTH];
            strcpy(decryptedPassword, passwordManager[i].password);
            decrypt(decryptedPassword);
            printf("%s\n", decryptedPassword);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No password found for website %s!\n", website);
    }
}

void displayMenu() {
    printf("\nPassword Manager Menu\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Search Password\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Select an option: ");
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
                printf("Exiting password manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}