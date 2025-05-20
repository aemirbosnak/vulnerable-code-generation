//FormAI DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_SIZE 20
#define FILENAME "passwords.txt"

// Function prototypes
void encrypt(char* password);
void decrypt(char* password);
int menu();
void storePassword(char* username, char* password);
void getStoredPassword(char* username);

int main() {
    printf(" === Retro Password Manager === \n\n");
    char password[MAX_SIZE];

    printf("Enter master password: ");
    fgets(password, MAX_SIZE, stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline character

    // Encrypt master password
    encrypt(password);

    int option = menu();
    while (option != 3) {
        // User selects option
        switch (option) {
            case 1:
                printf("Enter website username: ");
                char username[MAX_SIZE];
                fgets(username, MAX_SIZE, stdin);
                username[strcspn(username, "\n")] = 0; // Remove newline character
                printf("Enter website password: ");
                fgets(password, MAX_SIZE, stdin);
                password[strcspn(password, "\n")] = 0; // Remove newline character
                encrypt(password);
                storePassword(username, password);
                printf("Password for %s stored successfully.\n", username);
                break;
            case 2:
                printf("Enter website username: ");
                char findUsername[MAX_SIZE];
                fgets(findUsername, MAX_SIZE, stdin);
                findUsername[strcspn(findUsername, "\n")] = 0; // Remove newline character
                getStoredPassword(findUsername);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

        // Prompt user for next action
        option = menu();
    }

    printf("\nThank you for using Retro Password Manager.\n");

    // Exit program
    return 0;
}

void encrypt(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        password[i] += 1;
    }
}

void decrypt(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        password[i] -= 1;
    }
}

int menu() {
    printf("\nWhat would you like to do?\n");
    printf("1. Store a password\n");
    printf("2. Retrieve a password\n");
    printf("3. Exit\n");

    int option;
    printf("Enter option (1-3): ");
    scanf("%d", &option);
    getchar(); // Remove newline character
    return option;
}

void storePassword(char* username, char* password) {
    FILE* fp;
    fp = fopen(FILENAME, "a+"); // Open file for appending or create if it doesn't exist

    // Write username and password to file
    fprintf(fp, "%s %s\n", username, password);

    fclose(fp);
}

void getStoredPassword(char* username) {
    FILE* fp;
    fp = fopen(FILENAME, "r");

    char storedUsername[MAX_SIZE];
    char storedPassword[MAX_SIZE];

    int found = 0;
    while (fscanf(fp, "%s %s", storedUsername, storedPassword) != EOF) {
        // Decrypt password
        decrypt(storedPassword);

        // Compare stored username with input username
        if (strcmp(storedUsername, username) == 0) {
            printf("Password for %s found: %s\n", username, storedPassword);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Password for %s not found.\n", username);
    }
}