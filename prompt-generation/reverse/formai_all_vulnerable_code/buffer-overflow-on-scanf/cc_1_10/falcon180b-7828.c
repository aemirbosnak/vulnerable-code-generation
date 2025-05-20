//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 10
#define MAX_DIARY_ENTRIES 100

// User structure
typedef struct {
    char username[20];
    int userID;
    int numEntries;
    char diaryEntries[MAX_DIARY_ENTRIES][100];
} User;

// Function prototypes
void createUser(User* user);
void loginUser(User* users, int numUsers, char* username);
void addDiaryEntry(User* user);
void viewDiaryEntries(User* user);
void logoutUser(User* user);

int main() {
    User users[MAX_USERS];
    int numUsers = 0;

    // Create first user
    createUser(&users[0]);
    numUsers++;

    // Login loop
    while(1) {
        printf("Enter username: ");
        scanf("%s", users[numUsers - 1].username);
        loginUser(users, numUsers, users[numUsers - 1].username);
        printf("\n");
    }

    return 0;
}

void createUser(User* user) {
    printf("Enter username: ");
    scanf("%s", user->username);

    while(1) {
        printf("User ID (0-9): ");
        scanf("%d", &user->userID);

        if(user->userID >= 0 && user->userID <= 9) {
            break;
        } else {
            printf("Invalid user ID. Try again.\n");
        }
    }
}

void loginUser(User* users, int numUsers, char* username) {
    int i;
    for(i = 0; i < numUsers; i++) {
        if(strcmp(users[i].username, username) == 0) {
            printf("User %s logged in.\n", username);
            break;
        }
    }

    if(i == numUsers) {
        printf("User not found.\n");
    }
}

void addDiaryEntry(User* user) {
    int i;
    for(i = 0; i < user->numEntries; i++) {
        if(user->diaryEntries[i][0] == '\0') {
            printf("Diary entry %d:\n", i + 1);
            fgets(user->diaryEntries[i], 100, stdin);
            user->numEntries++;
            break;
        }
    }
}

void viewDiaryEntries(User* user) {
    int i;
    for(i = 0; i < user->numEntries; i++) {
        if(user->diaryEntries[i][0]!= '\0') {
            printf("Diary entry %d:\n%s", i + 1, user->diaryEntries[i]);
        }
    }
}

void logoutUser(User* user) {
    printf("User %s logged out.\n", user->username);
}