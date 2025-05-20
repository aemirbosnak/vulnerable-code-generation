//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define USERNAME_LENGTH 30
#define PASSWORD_LENGTH 20
#define FILE_NAME "bank_records.txt"

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    double balance;
} User;

User users[MAX_USERS];
int userCount = 0;

void loadUsers() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return;
    }
    while (fscanf(file, "%s %s %lf", users[userCount].username, users[userCount].password, &users[userCount].balance) != EOF) {
        userCount++;
    }
    fclose(file);
}

void saveUsers() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s %s %.2lf\n", users[i].username, users[i].password, users[i].balance);
    }
    fclose(file);
}

int findUser(const char *username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void registerUser() {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    
    printf("Register New User\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (findUser(username) != -1) {
        printf("Username already exists!\n");
        return;
    }

    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    users[userCount].balance = 0.0;
    userCount++;
    
    printf("User registered successfully!\n");
    saveUsers();
}

void loginUser() {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    
    printf("Login\n");
    printf("Enter username: ");
    scanf("%s", username);
    
    int userIndex = findUser(username);
    if (userIndex == -1) {
        printf("User not found!\n");
        return;
    }

    printf("Enter password: ");
    scanf("%s", password);
    if (strcmp(users[userIndex].password, password) != 0) {
        printf("Invalid password!\n");
        return;
    }

    while (1) {
        printf("\nWelcome %s! Your balance is %.2lf\n", users[userIndex].username, users[userIndex].balance);
        printf("1. Deposit\n2. Withdraw\n3. Logout\nChoose an option: ");
        int choice;
        scanf("%d", &choice);
        
        double amount;
        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                users[userIndex].balance += amount;
                printf("Successfully deposited %.2lf\n", amount);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                if (amount > users[userIndex].balance) {
                    printf("Insufficient funds!\n");
                } else {
                    users[userIndex].balance -= amount;
                    printf("Successfully withdrew %.2lf\n", amount);
                }
                break;
            case 3:
                printf("Logging out...\n");
                saveUsers();
                return;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

int main() {
    loadUsers();
    while (1) {
        printf("\n--- Banking Record System ---\n");
        printf("1. Register\n2. Login\n3. Exit\nChoose an option: ");
        int option;
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}