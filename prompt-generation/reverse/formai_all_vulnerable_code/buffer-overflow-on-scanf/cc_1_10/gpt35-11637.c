//FormAI DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50

struct User {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    int isAdmin;
};

struct User* createUser(char* username, char* password, int isAdmin) {
    struct User* user = (struct User*)malloc(sizeof(struct User));

    // Copy username and password into user
    strncpy(user->username, username, MAX_USERNAME_LEN);
    strncpy(user->password, password, MAX_PASSWORD_LEN);

    user->isAdmin = isAdmin;

    return user;
}

void freeUser(struct User* user) {
    free(user);
}

struct User** createUsers(int numUsers) {
    struct User** users = (struct User**)malloc(numUsers * sizeof(struct User*));

    int i;
    for (i = 0; i < numUsers; i++) {
        char username[MAX_USERNAME_LEN];
        char password[MAX_PASSWORD_LEN];
        int isAdmin;

        printf("Enter username for user %d: ", i+1);
        scanf("%s", username);

        printf("Enter password for user %d: ", i+1);
        scanf("%s", password);

        printf("Is user %d an admin? (0 for no, 1 for yes): ", i+1);
        scanf("%d", &isAdmin);

        users[i] = createUser(username, password, isAdmin);
    }

    return users;
}

void freeUsers(struct User** users, int numUsers) {
    int i;
    for (i = 0; i < numUsers; i++) {
        freeUser(users[i]);
    }

    free(users);
}

int main() {
    struct User** users = NULL;
    int numUsers = 0;

    while (1) {
        int option;

        printf("\n========== User Management System ==========\n");
        printf("1. Add user\n");
        printf("2. Remove user\n");
        printf("3. List users\n");
        printf("4. Quit\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                {
                    int isAdmin;
                    char username[MAX_USERNAME_LEN];
                    char password[MAX_PASSWORD_LEN];

                    printf("\nEnter username: ");
                    scanf("%s", username);

                    printf("Enter password: ");
                    scanf("%s", password);

                    printf("Is user an admin? (0 for no, 1 for yes): ");
                    scanf("%d", &isAdmin);

                    struct User* user = createUser(username, password, isAdmin);

                    if (users == NULL) {
                        users = (struct User**)malloc(sizeof(struct User*));
                    } else {
                        users = (struct User**)realloc(users, (numUsers+1) * sizeof(struct User*));
                    }

                    users[numUsers] = user;
                    numUsers++;

                    printf("\nUser added successfully!\n");
                    break;
                }

            case 2:
                {
                    if (users == NULL || numUsers == 0) {
                        printf("\nNo users to remove!\n");
                        break;
                    }

                    char username[MAX_USERNAME_LEN];
                    printf("\nEnter username of user to remove: ");
                    scanf("%s", username);

                    int i;
                    for (i = 0; i < numUsers; i++) {
                        if (strcmp(users[i]->username, username) == 0) {
                            freeUser(users[i]);

                            // Shift all users after the removed user to the left
                            int j;
                            for (j = i; j < numUsers-1; j++) {
                                users[j] = users[j+1];
                            }

                            numUsers--;

                            // If there are no more users, free the pointer
                            if (numUsers == 0) {
                                free(users);
                                users = NULL;
                            } else {
                                // Resize the pointer since a user was removed
                                users = (struct User**)realloc(users, numUsers * sizeof(struct User*));
                            }

                            printf("\nUser removed successfully!\n");
                            break;
                        }
                    }

                    if (i == numUsers) {
                        printf("\nUser '%s' not found!\n", username);
                    }

                    break;
                }

            case 3:
                {
                    printf("\n========== List of Users ==========\n");

                    if (users == NULL || numUsers == 0) {
                        printf("\nNo users to list!\n");
                        break;
                    }

                    int i;
                    for (i = 0; i < numUsers; i++) {
                        printf("%s (Password: %s) - %s\n", users[i]->username, users[i]->password, users[i]->isAdmin ? "Admin" : "Regular");
                    }

                    break;
                }

            case 4:
                {
                    // Free all memory before quitting
                    freeUsers(users, numUsers);

                    printf("\nGoodbye!\n");
                    return 0;
                }

            default:
                printf("\nInvalid option!\n");
        }
    }

    return 0;
}