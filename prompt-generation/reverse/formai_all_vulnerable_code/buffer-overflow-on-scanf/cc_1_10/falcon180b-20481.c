//Falcon-180B DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

struct User {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void generatePassword(char *password) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i;
    for (i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[MAX_PASSWORD_LENGTH - 1] = '\0';
}

int main() {
    FILE *usersFile;
    struct User users[MAX_USERS];
    int numUsers = 0;
    char filename[20];
    int choice;

    do {
        printf("Enter 1 to create a new user, 2 to login, 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the name of the new user: ");
            scanf("%s", users[numUsers].name);
            generatePassword(users[numUsers].password);
            printf("Your password is: %s\n", users[numUsers].password);
            numUsers++;
            break;
        case 2:
            printf("Enter your name: ");
            scanf("%s", filename);
            usersFile = fopen(filename, "r");
            if (usersFile == NULL) {
                printf("User not found\n");
            } else {
                fclose(usersFile);
                printf("Enter your password: ");
                scanf("%s", users[numUsers - 1].password);
                if (strcmp(users[numUsers - 1].password, filename) == 0) {
                    printf("Login successful\n");
                } else {
                    printf("Incorrect password\n");
                }
            }
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 3);

    return 0;
}