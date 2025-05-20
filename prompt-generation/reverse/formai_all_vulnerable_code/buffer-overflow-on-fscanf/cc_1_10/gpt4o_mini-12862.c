//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_PASSWORDS];
int currentCount = 0;

void encrypt(char *password);
void decrypt(char *password);
void addPassword();
void retrievePassword();
void displayPasswords();
void savePasswords();
void loadPasswords();

int main() {
    loadPasswords();
    int choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. Retrieve Password\n");
        printf("3. Display All Passwords\n");
        printf("4. Save & Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // consume newline

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                retrievePassword();
                break;
            case 3:
                displayPasswords();
                break;
            case 4:
                savePasswords();
                printf("Passwords saved. Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addPassword() {
    if (currentCount >= MAX_PASSWORDS) {
        printf("Password storage full. Cannot add more passwords.\n");
        return;
    }

    printf("Enter name for the password: ");
    fgets(passwordList[currentCount].name, MAX_LENGTH, stdin);
    strtok(passwordList[currentCount].name, "\n"); // Remove newline

    printf("Enter password: ");
    fgets(passwordList[currentCount].password, MAX_LENGTH, stdin);
    strtok(passwordList[currentCount].password, "\n"); // Remove newline
    
    encrypt(passwordList[currentCount].password);

    currentCount++;
    printf("Password added successfully!\n");
}

void retrievePassword() {
    char name[MAX_LENGTH];
    printf("Enter the name of the password you want to retrieve: ");
    fgets(name, MAX_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline

    for (int i = 0; i < currentCount; i++) {
        if (strcmp(passwordList[i].name, name) == 0) {
            char decryptedPassword[MAX_LENGTH];
            strcpy(decryptedPassword, passwordList[i].password);
            decrypt(decryptedPassword);
            printf("Password for %s is: %s\n", name, decryptedPassword);
            return;
        }
    }
    printf("Password for %s not found.\n", name);
}

void displayPasswords() {
    printf("\nStored Passwords:\n");
    for (int i = 0; i < currentCount; i++) {
        char decryptedPassword[MAX_LENGTH];
        strcpy(decryptedPassword, passwordList[i].password);
        decrypt(decryptedPassword);
        printf("Name: %s, Password: %s\n", passwordList[i].name, decryptedPassword);
    }
}

void encrypt(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] += 1; // Simple encryption by shifting characters
    }
}

void decrypt(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] -= 1; // Reversing the encryption by shifting back
    }
}

void savePasswords() {
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Error saving passwords!\n");
        return;
    }

    for (int i = 0; i < currentCount; i++) {
        // Writing the encrypted password to the file
        fprintf(file, "%s,%s\n", passwordList[i].name, passwordList[i].password);
    }

    fclose(file);
    printf("Passwords have been saved to passwords.txt\n");
}

void loadPasswords() {
    FILE *file = fopen("passwords.txt", "r");
    if (file) {
        while (fscanf(file, "%[^,],%s\n", passwordList[currentCount].name, passwordList[currentCount].password) != EOF) {
            currentCount++;
        }
        fclose(file);
    }
}