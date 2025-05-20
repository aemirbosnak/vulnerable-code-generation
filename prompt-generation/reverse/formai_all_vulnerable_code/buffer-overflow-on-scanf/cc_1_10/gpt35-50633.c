//FormAI DATASET v1.0 Category: System administration ; Style: realistic
#include <stdio.h>

void listUsers(void);
void deleteUser(char name[]);

int main() {
    int choice;
    char name[20];

    printf("Welcome to the User Administration Portal\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. List Users\n");
        printf("2. Delete User\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listUsers();
                break;
            case 2:
                printf("Enter the name of the user to delete: ");
                scanf("%s", name);
                deleteUser(name);
                break;
            case 3:
                printf("Thank you for using the User Administration Portal.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void listUsers() {
    printf("\nList of Users:\n");
    // code to retrieve and display list of users goes here
}

void deleteUser(char name[]) {
    printf("Deleting user %s...\n", name);
    // code to delete user goes here
    printf("User %s has been deleted.\n", name);
}