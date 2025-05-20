//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define BUFFER_SIZE 256
#define SALT_SIZE 16

typedef struct {
    char service[BUFFER_SIZE];
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    char salt[SALT_SIZE];
} PasswordEntry;

PasswordEntry passwordVault[MAX_PASSWORDS];
int passwordCount = 0;

void generateSalt(char *salt) {
    // Generate a random salt
    for (int i = 0; i < SALT_SIZE; i++) {
        salt[i] = 'a' + (rand() % 26);
    }
    salt[SALT_SIZE - 1] = '\0'; // Null terminate
}

void hashPassword(const char *password, const char *salt, char *hashedPassword) {
    // Create a simple hash by combining password and salt
    snprintf(hashedPassword, BUFFER_SIZE, "%s%s", password, salt);
}

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password vault is full!\n");
        return;
    }

    PasswordEntry *entry = &passwordVault[passwordCount];
    printf("Enter service name: ");
    scanf("%s", entry->service);
    printf("Enter username: ");
    scanf("%s", entry->username);
    printf("Enter password: ");
    scanf("%s", entry->password);

    generateSalt(entry->salt);
    char hashedPassword[BUFFER_SIZE];
    hashPassword(entry->password, entry->salt, hashedPassword);
    strcpy(entry->password, hashedPassword);

    passwordCount++;
    printf("Password for %s added successfully!\n", entry->service);
}

void viewPasswords() {
    printf("\n--- Password Vault ---\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("Service: %s, Username: %s, Hashed Password: %s, Salt: %s\n",
               passwordVault[i].service, passwordVault[i].username,
               passwordVault[i].password, passwordVault[i].salt);
    }
    if (passwordCount == 0) {
        printf("No passwords stored.\n");
    }
}

void deletePassword() {
    char service[BUFFER_SIZE];
    printf("Enter the service name to delete: ");
    scanf("%s", service);

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordVault[i].service, service) == 0) {
            printf("Deleting password for %s...\n", service);
            for (int j = i; j < passwordCount - 1; j++) {
                passwordVault[j] = passwordVault[j + 1]; // Shift left
            }
            passwordCount--;
            printf("Password deleted successfully!\n");
            return;
        }
    }
    printf("Service %s not found!\n", service);
}

void savePasswordsToFile() {
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < passwordCount; i++) {
        fprintf(file, "%s,%s,%s,%s\n", passwordVault[i].service,
                passwordVault[i].username,
                passwordVault[i].password,
                passwordVault[i].salt);
    }
    fclose(file);
    printf("Passwords saved to file!\n");
}

void loadPasswordsFromFile() {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("No saved passwords found. Starting fresh!\n");
        return;
    }

    while (!feof(file) && passwordCount < MAX_PASSWORDS) {
        PasswordEntry *entry = &passwordVault[passwordCount];
        fscanf(file, "%[^,],%[^,],%[^,],%[^,]\n",
               entry->service, entry->username,
               entry->password, entry->salt);
        passwordCount++;
    }
    fclose(file);
    printf("Passwords loaded from file!\n");
}

void futuristicUI() {
    int choice;

    do {
        printf("\n--- Futuristic Password Manager ---\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Save Passwords to File\n");
        printf("5. Load Passwords from File\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPassword(); break;
            case 2: viewPasswords(); break;
            case 3: deletePassword(); break;
            case 4: savePasswordsToFile(); break;
            case 5: loadPasswordsFromFile(); break;
            case 6: printf("Exiting... Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);
}

int main() {
    srand(time(NULL)); // Seed random number generator
    loadPasswordsFromFile();
    futuristicUI();
    savePasswordsToFile();
    return 0;
}