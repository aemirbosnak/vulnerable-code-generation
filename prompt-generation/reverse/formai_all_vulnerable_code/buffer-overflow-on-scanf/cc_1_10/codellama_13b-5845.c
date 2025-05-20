//Code Llama-13B DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
    #include <string.h>

    // Structure to store user data
    struct user {
        char username[20];
        char password[20];
    };

    // Function to print the menu
    void print_menu() {
        printf("--------------------------------\n");
        printf("1. Add a new user\n");
        printf("2. View all users\n");
        printf("3. Delete a user\n");
        printf("4. Exit\n");
        printf("--------------------------------\n");
    }

    // Function to add a new user
    void add_user() {
        struct user new_user;
        printf("Enter the new user's username: ");
        scanf("%s", new_user.username);
        printf("Enter the new user's password: ");
        scanf("%s", new_user.password);
        printf("User added successfully!\n");
    }

    // Function to view all users
    void view_users() {
        struct user all_users[10];
        int num_users = 0;
        printf("--------------------------------\n");
        printf("All users:\n");
        for (int i = 0; i < num_users; i++) {
            printf("%d. %s\n", i + 1, all_users[i].username);
        }
        printf("--------------------------------\n");
    }

    // Function to delete a user
    void delete_user() {
        struct user users[10];
        int num_users = 0;
        printf("Enter the username of the user to delete: ");
        scanf("%s", users[num_users].username);
        for (int i = 0; i < num_users; i++) {
            if (strcmp(users[i].username, users[num_users].username) == 0) {
                users[i] = users[num_users];
                break;
            }
        }
        num_users--;
        printf("User deleted successfully!\n");
    }

    // Main function
    int main() {
        int choice;
        do {
            print_menu();
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    add_user();
                    break;
                case 2:
                    view_users();
                    break;
                case 3:
                    delete_user();
                    break;
                case 4:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice. Try again.\n");
                    break;
            }
        } while (choice != 4);
        return 0;
    }