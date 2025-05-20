//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_USERS 10

typedef struct {
    char name[MAX_STRING_LENGTH];
    int age;
} User;

void clear_buffer() {
    while (getchar() != '\n') { }
}

void add_user(User *users, int *count) {
    if (*count >= MAX_USERS) {
        printf("Error: Maximum user limit reached (%d users).\n", MAX_USERS);
        return;
    }

    User newUser;
    printf("Enter name: ");
    if (fgets(newUser.name, sizeof(newUser.name), stdin) == NULL) {
        printf("Error: Unable to read name.\n");
        return;
    }
    newUser.name[strcspn(newUser.name, "\n")] = 0; // Remove newline

    printf("Enter age: ");
    if (scanf("%d", &newUser.age) != 1) {
        printf("Error: Invalid input for age.\n");
        clear_buffer();
        return;
    }
    clear_buffer();

    users[*count] = newUser;
    (*count)++;

    printf("User added successfully: %s (%d years old)\n", newUser.name, newUser.age);
}

void display_users(User *users, int count) {
    if (count == 0) {
        printf("Error: No users to display.\n");
        return;
    }

    printf("List of users:\n");
    for (int i = 0; i < count; i++) {
        printf("User %d: %s, Age: %d\n", i + 1, users[i].name, users[i].age);
    }
}

void find_user(User *users, int count) {
    if (count == 0) {
        printf("Error: No users to search.\n");
        return;
    }

    char name[MAX_STRING_LENGTH];
    printf("Enter name to find: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("Error: Unable to read name.\n");
        return;
    }
    name[strcspn(name, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("User found: %s, Age: %d\n", users[i].name, users[i].age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: User not found.\n");
    }
}

void delete_user(User *users, int *count) {
    if (*count == 0) {
        printf("Error: No users to delete.\n");
        return;
    }

    char name[MAX_STRING_LENGTH];
    printf("Enter name to delete: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("Error: Unable to read name.\n");
        return;
    }
    name[strcspn(name, "\n")] = 0; // Remove newline

    int found = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(users[i].name, name) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Error: User not found. Cannot delete.\n");
        return;
    }

    for (int i = found; i < *count - 1; i++) {
        users[i] = users[i + 1];
    }

    (*count)--;

    printf("User deleted successfully: %s\n", name);
}

void show_menu() {
    printf("\n--- User Management System ---\n");
    printf("1. Add User\n");
    printf("2. Display Users\n");
    printf("3. Find User\n");
    printf("4. Delete User\n");
    printf("5. Exit\n");
    printf("------------------------------\n");
    printf("Choose an option: ");
}

int main() {
    User users[MAX_USERS];
    int user_count = 0;
    int choice;

    while (1) {
        show_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Error: Invalid input. Please enter a number.\n");
            clear_buffer();
            continue;
        }
        clear_buffer();

        switch (choice) {
            case 1:
                add_user(users, &user_count);
                break;
            case 2:
                display_users(users, user_count);
                break;
            case 3:
                find_user(users, user_count);
                break;
            case 4:
                delete_user(users, &user_count);
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                return 0;
            default:
                printf("Error: Invalid option. Please choose between 1-5.\n");
        }
    }
    return 0;
}