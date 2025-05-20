//FormAI DATASET v1.0 Category: System administration ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
    char username[20];
    char password[20];
    int isAdmin;
};

void createUser(struct user *users, int *numUsers) {
    printf("Enter username: ");
    scanf("%s", users[*numUsers].username);

    printf("Enter password: ");
    scanf("%s", users[*numUsers].password);

    printf("Is this user an administrator (0=no, 1=yes)? ");
    scanf("%d", &users[*numUsers].isAdmin);

    (*numUsers)++;
    printf("User created successfully!\n");
}

void deleteUser(struct user *users, int *numUsers) {
    char username[20];
    int foundIndex = -1;

    printf("Enter the username of the user to delete: ");
    scanf("%s", username);

    for (int i = 0; i < *numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Error: User not found.\n");
        return;
    }

    for (int i = foundIndex; i < *numUsers-1; i++) {
        users[i] = users[i+1];
    }

    (*numUsers)--;
    printf("User deleted successfully!\n");
}

void listUsers(struct user *users, int numUsers) {
    printf("Users:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("%s (%s)\n", users[i].username, users[i].isAdmin ? "admin" : "normal");
    }
}

int main() {
    struct user users[10];
    int numUsers = 0;
    int choice;

    while (1) {
        printf("\n");
        printf("1. Create user\n");
        printf("2. Delete user\n");
        printf("3. List users\n");
        printf("4. Quit\n");
        printf("\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser(users, &numUsers);
                break;
            case 2:
                deleteUser(users, &numUsers);
                break;
            case 3:
                listUsers(users, numUsers);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}