//FormAI DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USER_INPUT 50

void printSurprisedMessage(char *message) {
    printf("\n😲😲😲 %s 😲😲😲\n", message);
}

void addUserToSystem(char *username) {
    char command[MAX_USER_INPUT];
    sprintf(command, "sudo useradd -m %s", username);
    system(command);
    printf("\nUser %s has been added to the system!\n", username);
}

void deleteUserFromSystem(char *username) {
    char command[MAX_USER_INPUT];
    sprintf(command, "sudo userdel -fr %s", username);
    system(command);
    printf("\nUser %s has been deleted from the system!\n", username);
}

int main() {
    char userInput[MAX_USER_INPUT];
    while (1) {
        printf("Enter 'add' to add a user to the system or 'delete' to delete a user: ");
        scanf("%s", userInput);
        if (strcmp(userInput, "add") == 0) {
            printf("\nEnter the username you would like to add: ");
            scanf("%s", userInput);
            printSurprisedMessage("Adding a user to the system!");
            addUserToSystem(userInput);
        }
        else if (strcmp(userInput, "delete") == 0) {
            printf("\nEnter the username you would like to delete: ");
            scanf("%s", userInput);
            printSurprisedMessage("Deleting a user from the system!");
            deleteUserFromSystem(userInput);
        }
        else {
            printSurprisedMessage("Invalid input! Please try again.");
        }
        sleep(1);
        system("clear");
    }
    return 0;
}