//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_LENGTH 100

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Alas! The list of lovers is full.\n");
        return;
    }

    char username[MAX_LENGTH], password[MAX_LENGTH];

    printf("Enter your name, oh sweet Juliet: ");
    scanf("%s", username);
    printf("Create a secret password, dear Romeo: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Oh! The name you choose is already in the hearts of another.\n");
            return;
        }
    }

    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;
    
    printf("Sweet love, thy registration is a success!\n");
}

void loginUser() {
    char username[MAX_LENGTH], password[MAX_LENGTH];
    printf("Enter your name, fair maiden: ");
    scanf("%s", username);
    printf("Speak thy secret password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (strcmp(users[i].password, password) == 0) {
                printf("Oh joyous day, %s! Thou hast entered the realm!\n", username);
                return;
            } else {
                printf("Oh cruel fate! Thy password doth not match.\n");
                return;
            }
        }
    }
    printf("Alas! The name is lost in the shadows.\n");
}

void displayUsers() {
    printf("List of lovers, oh let it be known:\n");
    for (int i = 0; i < userCount; i++) {
        printf("%s\n", users[i].username);
    }
}

void deleteUser() {
    char username[MAX_LENGTH];
    printf("Speak the name of the lover to be forgotten: ");
    scanf("%s", username);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            for (int j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1];
            }
            userCount--;
            printf("Alas! %s has been forgotten from this realm.\n", username);
            return;
        }
    }
    printf("Sweet sorrow, but no such name exists in the hearts of this world.\n");
}

void exitProgram() {
    printf("The farewell, gentle user! May love guide your way.\n");
    exit(0);
}

int main() {
    while (1) {
        printf("\n-- A Password Management Tale of Romeo and Juliet --\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Display Users\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Choose thy action: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                displayUsers();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                exitProgram();
                break;
            default:
                printf("Oh no! A choice unseen, thus must be left behind.\n");
                break;
        }
    }
    return 0;
}