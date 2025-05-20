//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_LOGS 50
#define MAX_ATTEMPTS 5

struct Log {
    char username[20];
    char password[20];
    int numAttempts;
};

struct User {
    char username[20];
    char password[20];
};

struct Log userLogs[MAX_LOGS];

int numOfLogs = 0;

int main() {
    struct User validUsers[] = {
        {"admin", "admin123"},
        {"user1", "password1"},
        {"user2", "password2"},
        {"user3", "password3"}
    };

    char inputUsername[20];
    char inputPassword[20];
    int attempts = 0;
    int isAuthenticated = 0;

    printf("Welcome to My Application!\n\n");

    while (attempts < MAX_ATTEMPTS && !isAuthenticated) {
        printf("Username: ");
        scanf("%s", inputUsername);

        printf("Password: ");
        scanf("%s", inputPassword);

        for (int i = 0; i < sizeof(validUsers) / sizeof(validUsers[0]); i++) {
            if (strcmp(inputUsername, validUsers[i].username) == 0 && strcmp(inputPassword, validUsers[i].password) == 0) {
                isAuthenticated = 1;
                break;
            }
        }

        if (!isAuthenticated) {
            printf("Invalid username or password. Please try again.\n");
            attempts++;

            struct Log log = {inputUsername, inputPassword, 1};
            userLogs[numOfLogs++] = log;

            if (attempts == MAX_ATTEMPTS) {
                printf("Maximum number of attempts reached. You are locked out.\n");
            }
        }
    }

    if (isAuthenticated) {
        printf("Welcome %s!\n", inputUsername);
    }

    return 0;
}