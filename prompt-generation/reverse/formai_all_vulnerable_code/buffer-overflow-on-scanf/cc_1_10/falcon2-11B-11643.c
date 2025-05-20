//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: medieval
#include <stdio.h>
#include <string.h>

struct User {
    char name[50];
    char email[100];
};

struct User users[100];
int num_users = 0;

void add_user() {
    printf("What is the user's name? ");
    fgets(users[num_users].name, sizeof(users[num_users].name), stdin);
    users[num_users].name[strcspn(users[num_users].name, "\n")] = '\0';
    printf("What is the user's email address? ");
    fgets(users[num_users].email, sizeof(users[num_users].email), stdin);
    users[num_users].email[strcspn(users[num_users].email, "\n")] = '\0';
    num_users++;
}

void remove_user() {
    printf("Which user would you like to remove? ");
    for (int i = 0; i < num_users; i++) {
        printf("(%d) %s <%s>\n", i+1, users[i].name, users[i].email);
    }
    int choice = 0;
    do {
        printf("Enter the number of the user to remove: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > num_users) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice < 1 || choice > num_users);
    memmove(&users[choice-1], &users[choice], (num_users-1) * sizeof(struct User));
    num_users--;
}

void list_users() {
    printf("The mailing list currently contains the following users:\n");
    for (int i = 0; i < num_users; i++) {
        printf("(%d) %s <%s>\n", i+1, users[i].name, users[i].email);
    }
}

int main() {
    while (1) {
        printf("Please select an action:\n");
        printf("1. Add a new user\n");
        printf("2. Remove a user\n");
        printf("3. List all users\n");
        printf("4. Quit\n");
        int choice = 0;
        do {
            printf("Enter your choice: ");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 4);
        switch (choice) {
            case 1: add_user(); break;
            case 2: remove_user(); break;
            case 3: list_users(); break;
            case 4: exit(0);
        }
    }
    return 0;
}