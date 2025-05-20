//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a new user to the mailing list
void addUser(char* username, char* email) {
    char* newUser = (char*)malloc(sizeof(char) * (strlen(username) + strlen(email) + 1));
    strcpy(newUser, username);
    strcat(newUser, " <");
    strcat(newUser, email);
    strcat(newUser, ">");
    printf("Added %s to the mailing list\n", newUser);
    free(newUser);
}

// Function to remove a user from the mailing list
void removeUser(char* username) {
    char* userToRemove = (char*)malloc(sizeof(char) * (strlen(username) + 1));
    strcpy(userToRemove, username);
    printf("Removed %s from the mailing list\n", userToRemove);
    free(userToRemove);
}

// Function to display the current mailing list
void displayList() {
    char* currentList = (char*)malloc(sizeof(char) * 256);
    printf("Current mailing list:\n");
    char* user;
    char* email;
    int count = 0;
    while (scanf("%s %s", &user, &email) == 2) {
        strcat(currentList, user);
        strcat(currentList, " <");
        strcat(currentList, email);
        strcat(currentList, ">\n");
        count++;
    }
    printf("%s\n", currentList);
    free(currentList);
}

int main() {
    char* username;
    char* email;
    char* password;

    while (scanf("%s %s %s", &username, &email, &password) == 3) {
        if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
            char* command;
            while (scanf("%s", &command) == 1) {
                if (strcmp(command, "add") == 0) {
                    char* newUser;
                    scanf("%s %s", &username, &email);
                    addUser(username, email);
                } else if (strcmp(command, "remove") == 0) {
                    char* userToRemove;
                    scanf("%s", &userToRemove);
                    removeUser(userToRemove);
                } else if (strcmp(command, "display") == 0) {
                    displayList();
                } else {
                    printf("Invalid command\n");
                }
            }
        } else {
            printf("Invalid username or password\n");
        }
    }
    return 0;
}