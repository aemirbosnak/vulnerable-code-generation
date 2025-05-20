//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 16
#define USERNAME_LENGTH 32
#define FILENAME "cybervault.dat"

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} Credential;

Credential vault[MAX_PASSWORDS];
int count = 0;

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape sequences to clear terminal
}

void generatePassword(char *password) {
    const char *charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";
    for (int i = 0; i < PASSWORD_LENGTH - 1; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[PASSWORD_LENGTH - 1] = '\0'; // Null terminate
}

void saveVault() {
    FILE *file = fopen(FILENAME, "wb");
    if (!file) {
        perror("Failed to open vault");
        return;
    }
    fwrite(vault, sizeof(Credential), count, file);
    fclose(file);
}

void loadVault() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        printf("Vault not found, starting fresh...\n");
        return;
    }
    while (fread(&vault[count], sizeof(Credential), 1, file) == 1) {
        count++;
    }
    fclose(file);
}

void addCredential() {
    if (count >= MAX_PASSWORDS) {
        printf("Vault full! Cannot add more credentials.\n");
        return;
    }
    
    char username[USERNAME_LENGTH];
    printf("Choose a username: ");
    scanf("%31s", username);
    
    generatePassword(vault[count].password);
    strncpy(vault[count].username, username, USERNAME_LENGTH);
    printf("Generated password for %s: %s\n", vault[count].username, vault[count].password);
    
    count++;
    saveVault();
}

void listCredentials() {
    if (count == 0) {
        printf("No credentials found in the vault.\n");
        return;
    }
    
    printf("\n--- Credential List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Username: %s | Password: %s\n", vault[i].username, vault[i].password);
    }
}

void deleteCredential() {
    char username[USERNAME_LENGTH];
    printf("Enter the username you want to remove: ");
    scanf("%31s", username);
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(vault[i].username, username) == 0) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                vault[j] = vault[j + 1]; // Shift left
            }
            count--;
            break;
        }
    }
    
    if (found) {
        printf("Removed credentials for username: %s\n", username);
        saveVault();
    } else {
        printf("Username not found in the vault.\n");
    }
}

void clearVault() {
    count = 0;
    remove(FILENAME);
    printf("All credentials have been erased from the vault. Proceed with caution...\n");
}

void displayMenu() {
    printf("====== CyberVault ======\n");
    printf("1. Add Credential\n");
    printf("2. List Credentials\n");
    printf("3. Delete Credential\n");
    printf("4. Clear Vault\n");
    printf("5. Exit\n");
    printf("=========================\n");
}

void launchCyberVault() {
    loadVault();
    
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addCredential();
                break;
            case 2:
                listCredentials();
                break;
            case 3:
                deleteCredential();
                break;
            case 4:
                clearVault();
                break;
            case 5:
                printf("Logging out from CyberVault...\n");
                exit(0);
            default:
                printf("Invalid option! Try again.\n");
        }
        
        sleep(1);
        clearScreen();
    }
}

int main() {
    srand(time(NULL));
    clearScreen();
    launchCyberVault();
    return 0;
}