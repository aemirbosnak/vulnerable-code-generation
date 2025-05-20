//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 5
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
} User;

// Function prototypes
void greetUser();
void logError(const char *message);
int addUser(User *users, int *userCount);
void displayUsers(const User *users, int userCount);

int main() {
    User users[MAX_USERS];
    int userCount = 0;

    greetUser();

    while (userCount < MAX_USERS) {
        printf("Would you like to add a user? (1 for Yes, 0 for No): ");
        int choice;
        if (scanf("%d", &choice) != 1) {
            logError("Invalid input. Please enter a number (0 or 1).");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (choice == 1) {
            if (addUser(users, &userCount) == -1) {
                logError("Failed to add another user. User limit reached!");
                break; // Maximum users reached
            }
        } else {
            break;
        }
    }

    displayUsers(users, userCount);
    return 0;
}

void greetUser() {
    printf("🎉 Welcome to the User Registration System! 🎉\n");
    printf("Let's create some friendly users together!\n\n");
}

void logError(const char *message) {
    fprintf(stderr, "🚨 Error: %s\n", message);
}

int addUser(User *users, int *userCount) {
    if (*userCount >= MAX_USERS) {
        return -1; // User limit reached
    }

    User newUser;
    printf("Please enter the name of the new user: ");
    getchar(); // Clear newline character
    if (fgets(newUser.name, sizeof(newUser.name), stdin) == NULL) {
        logError("Failed to read name.");
        return -1;
    }

    // Remove newline character from the name
    newUser.name[strcspn(newUser.name, "\n")] = 0;

    printf("Please enter the age of %s: ", newUser.name);
    if (scanf("%d", &newUser.age) != 1) {
        logError("Invalid age input. Please enter a valid number.");
        while(getchar() != '\n'); // Clear input buffer
        return -1; // Don't add user
    }

    // Store new user
    users[*userCount] = newUser;
    (*userCount)++;
    printf("🎉 User %s added successfully! 🎉\n\n", newUser.name);
    return 0;
}

void displayUsers(const User *users, int userCount) {
    if (userCount == 0) {
        printf("No users registered yet. Let's add some!\n");
        return;
    }

    printf("📋 Here are the registered users: 📋\n");
    for (int i = 0; i < userCount; i++) {
        printf("User %d: %s, Age: %d\n", i + 1, users[i].name, users[i].age);
    }
}