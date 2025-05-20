//FormAI DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char email[50];
} User;

int main() {
    int action;
    int num_users = 0;
    User *users = NULL;

    while (1) {
        printf("Welcome to the User Database Simulation.\n");
        printf("Choose an action:\n");
        printf("1. Add a User\n");
        printf("2. Delete a User\n");
        printf("3. View all Users\n");
        printf("4. Exit\n");
        scanf("%d", &action);

        if (action == 1) {
            printf("Enter a user ID: ");
            int id;
            scanf("%d", &id);

            printf("Enter a name: ");
            char name[50];
            scanf("%s", name);

            printf("Enter an email: ");
            char email[50];
            scanf("%s", email);

            User new_user = {id, "", ""};
            strcpy(new_user.name, name);
            strcpy(new_user.email, email);

            users = realloc(users, (num_users + 1) * sizeof(User));
            users[num_users] = new_user;
            num_users++;

            printf("User added successfully!\n\n");
        }
        else if (action == 2) {
            printf("Enter a user ID to delete: ");
            int id;
            scanf("%d", &id);

            int found_index = -1;
            for (int i = 0; i < num_users; i++) {
                if (users[i].id == id) {
                    found_index = i;
                    break;
                }
            }

            if (found_index == -1) {
                printf("User not found!\n\n");
            }
            else {
                for (int i = found_index; i < num_users - 1; i++) {
                    users[i] = users[i + 1];
                }

                users = realloc(users, (num_users - 1) * sizeof(User));
                num_users--;

                printf("User deleted successfully!\n\n");
            }
        }
        else if (action == 3) {
            printf("All Users:\n");

            for (int i = 0; i < num_users; i++) {
                printf("ID: %d\n", users[i].id);
                printf("Name: %s\n", users[i].name);
                printf("Email: %s\n", users[i].email);
                printf("\n");
            }
        }
        else if (action == 4) {
            printf("Exiting User Database Simulation. Goodbye!\n");
            break;
        }
        else {
            printf("Invalid action. Please try again.\n\n");
        }
    }

    free(users);
    return 0;
}