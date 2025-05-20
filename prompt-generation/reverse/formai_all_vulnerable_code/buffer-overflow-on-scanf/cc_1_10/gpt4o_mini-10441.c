//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char website[50];
    char username[50];
    char password[PASSWORD_LENGTH];
} Entry;

Entry passwordList[MAX_PASSWORDS];
int count = 0;

// Function prototypes
void addEntry();
void viewEntries();
void generatePassword(char *password, int length);
void saveToFile();
void loadFromFile();
void menu();
void clearBuffer();

int main() {
    loadFromFile();
    menu();
    saveToFile();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n=== Password Manager ===\n");
        printf("1. Add new entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 3);
}

void addEntry() {
    if (count >= MAX_PASSWORDS) {
        printf("Password list is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter website: ");
    fgets(passwordList[count].website, sizeof(passwordList[count].website), stdin);
    passwordList[count].website[strcspn(passwordList[count].website, "\n")] = 0; // Remove newline

    printf("Enter username: ");
    fgets(passwordList[count].username, sizeof(passwordList[count].username), stdin);
    passwordList[count].username[strcspn(passwordList[count].username, "\n")] = 0; // Remove newline

    printf("Do you want to generate a password? (y/n): ");
    char option;
    scanf(" %c", &option);
    clearBuffer();

    if (option == 'y' || option == 'Y') {
        generatePassword(passwordList[count].password, PASSWORD_LENGTH);
        printf("Generated Password: %s\n", passwordList[count].password);
    } else {
        printf("Enter password: ");
        fgets(passwordList[count].password, sizeof(passwordList[count].password), stdin);
        passwordList[count].password[strcspn(passwordList[count].password, "\n")] = 0; // Remove newline
    }

    count++;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (count == 0) {
        printf("No entries found!\n");
        return;
    }

    printf("\n--- Saved Passwords ---\n");
    for (int i = 0; i < count; i++) {
        printf("Website: %s\n", passwordList[i].website);
        printf("Username: %s\n", passwordList[i].username);
        printf("Password: %s\n", passwordList[i].password);
        printf("-----------------------\n");
    }
}

void generatePassword(char *password, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    srand(time(NULL));

    for (int i = 0; i < length - 1; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    password[length - 1] = '\0'; // Null terminate the string
}

void saveToFile() {
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%s\n", passwordList[i].website, passwordList[i].username, passwordList[i].password);
    }
    fclose(file);
    printf("Passwords saved to file!\n");
}

void loadFromFile() {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("No previous passwords found, starting fresh...\n");
        return;
    }

    while (fscanf(file, "%49[^,],%49[^,],%19s\n", passwordList[count].website, passwordList[count].username, passwordList[count].password) != EOF) {
        count++;
    }
    fclose(file);
    printf("Passwords loaded successfully!\n");
}

void clearBuffer() {
    while (getchar() != '\n');
}