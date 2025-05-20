//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 12
#define MAX_PASSWORDS 100

// Function prototypes
void generateRandomPassword(char *password, int length);
void customizePassword(char *password, int length);
void displayMenu();
void savePasswordsToFile(char passwords[MAX_PASSWORDS][PASSWORD_LENGTH + 1], int count);
void loadPasswordsFromFile(char passwords[MAX_PASSWORDS][PASSWORD_LENGTH + 1], int *count);

int main() {
    srand(time(0));  // Seed the random number generator

    char passwords[MAX_PASSWORDS][PASSWORD_LENGTH + 1];
    int passwordCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (passwordCount < MAX_PASSWORDS) {
                    generateRandomPassword(passwords[passwordCount], PASSWORD_LENGTH);
                    printf("Generated Password: %s\n", passwords[passwordCount]);
                    passwordCount++;
                } else {
                    printf("Password limit reached!\n");
                }
                break;
            case 2:
                if (passwordCount < MAX_PASSWORDS) {
                    customizePassword(passwords[passwordCount], PASSWORD_LENGTH);
                    printf("Custom Password: %s\n", passwords[passwordCount]);
                    passwordCount++;
                } else {
                    printf("Password limit reached!\n");
                }
                break;
            case 3:
                savePasswordsToFile(passwords, passwordCount);
                printf("Passwords saved to file.\n");
                break;
            case 4:
                loadPasswordsFromFile(passwords, &passwordCount);
                printf("Passwords loaded from file.\n");
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}

void generateRandomPassword(char *password, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % (sizeof(charset) - 1);
        password[i] = charset[randomIndex];
    }
    password[length] = '\0';  // Null-terminate the string
}

void customizePassword(char *password, int length) {
    printf("Enter your custom password (max length %d): ", length);
    scanf("%s", password);  // Read the custom password
    if (strlen(password) > length) {
        password[length] = '\0';  // Ensure null-termination
    }
}

void displayMenu() {
    printf("\n--- Secure Password Generator ---\n");
    printf("1. Generate Random Password\n");
    printf("2. Customize Password\n");
    printf("3. Save Passwords to File\n");
    printf("4. Load Passwords from File\n");
    printf("5. Exit\n");
}

void savePasswordsToFile(char passwords[MAX_PASSWORDS][PASSWORD_LENGTH + 1], int count) {
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        perror("Failed to save passwords");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", passwords[i]);
    }
    fclose(file);
}

void loadPasswordsFromFile(char passwords[MAX_PASSWORDS][PASSWORD_LENGTH + 1], int *count) {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        perror("Failed to load passwords");
        return;
    }

    *count = 0;  // Reset password count
    while (fgets(passwords[*count], PASSWORD_LENGTH + 1, file) != NULL && *count < MAX_PASSWORDS) {
        passwords[*count][strcspn(passwords[*count], "\n")] = 0;  // Remove newline character
        (*count)++;
    }
    fclose(file);
}