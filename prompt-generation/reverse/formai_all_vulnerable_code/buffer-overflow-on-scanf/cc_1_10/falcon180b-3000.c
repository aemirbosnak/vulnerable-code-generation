//Falcon-180B DATASET v1.0 Category: Password management ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_USER 100
#define MAX_PASS 50

struct user {
    char username[MAX_USER];
    char password[MAX_PASS];
    int status;
};

void create(struct user *user) {
    printf("\nEnter username: ");
    scanf("%s", user->username);
    printf("\nEnter password: ");
    scanf("%s", user->password);
    user->status = 1;
    printf("\nUser created successfully!");
}

void delete(struct user *user) {
    printf("\nEnter username: ");
    scanf("%s", user->username);
    printf("\nUser deleted successfully!");
}

void update(struct user *user) {
    printf("\nEnter username: ");
    scanf("%s", user->username);
    printf("\nEnter new password: ");
    scanf("%s", user->password);
    printf("\nUser updated successfully!");
}

void view(struct user *user) {
    printf("\nEnter username: ");
    scanf("%s", user->username);
    if (user->status == 1) {
        printf("\nUser exists.\nUsername: %s\nPassword: %s", user->username, user->password);
    } else {
        printf("\nUser does not exist.");
    }
}

void main() {
    struct user user;
    int choice;

    while (1) {
        printf("\nPassword Manager\n");
        printf("\n1. Create user");
        printf("\n2. Delete user");
        printf("\n3. Update user");
        printf("\n4. View user");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create(&user);
                break;
            case 2:
                delete(&user);
                break;
            case 3:
                update(&user);
                break;
            case 4:
                view(&user);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }
}