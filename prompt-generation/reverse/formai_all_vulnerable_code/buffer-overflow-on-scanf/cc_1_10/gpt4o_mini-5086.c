//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 32

typedef struct {
    char site[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Credentials;

Credentials passwordManager[MAX_PASSWORDS];
int passwordCount = 0;

void addPassword();
void viewPasswords();
void encryptPassword(char *password);
void decryptPassword(char *password);
int isEmpty(const char *str);
void clearScreen();

int main() {
    int choice;
    do {
        clearScreen();
        printf("Welcome to the Curious Password Manager!\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume the newline character

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                printf("Exiting the Curious Password Manager. Stay Secure!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        getchar();  // to pause before clearing the screen
    } while (choice != 3);

    return 0;
}

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password storage is full! Please delete some passwords to add new ones.\n");
        return;
    }

    printf("Enter site name: ");
    fgets(passwordManager[passwordCount].site, MAX_LENGTH, stdin);
    passwordManager[passwordCount].site[strcspn(passwordManager[passwordCount].site, "\n")] = 0; // Remove newline

    printf("Enter username: ");
    fgets(passwordManager[passwordCount].username, MAX_LENGTH, stdin);
    passwordManager[passwordCount].username[strcspn(passwordManager[passwordCount].username, "\n")] = 0; // Remove newline

    printf("Enter password: ");
    fgets(passwordManager[passwordCount].password, MAX_LENGTH, stdin);
    passwordManager[passwordCount].password[strcspn(passwordManager[passwordCount].password, "\n")] = 0; // Remove newline
    encryptPassword(passwordManager[passwordCount].password);
    
    passwordCount++;
    printf("Password stored successfully!\n");
}

void viewPasswords() {
    if (passwordCount == 0) {
        printf("No passwords stored yet!\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("Site: %s\n", passwordManager[i].site);
        printf("Username: %s\n", passwordManager[i].username);
        decryptPassword(passwordManager[i].password);
        printf("Password: %s\n", passwordManager[i].password);
        printf("---------------------------\n");
    }
}

void encryptPassword(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] += 5; // Simple encryption by shifting ASCII values
    }
}

void decryptPassword(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] -= 5; // Simple decryption by shifting back
    }
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}