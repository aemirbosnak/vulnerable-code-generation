//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 10
#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    int age;
    char email[MAX_LENGTH];
} User;

void clear_input_buffer() {
    while (getchar() != '\n');
}

void add_user(User users[], int *user_count) {
    if (*user_count >= MAX_USERS) {
        printf("User list is full!\n");
        return;
    }

    printf("Enter user name: ");
    fgets(users[*user_count].name, MAX_LENGTH, stdin);
    users[*user_count].name[strcspn(users[*user_count].name, "\n")] = 0; // Remove newline

    printf("Enter user age: ");
    scanf("%d", &users[*user_count].age);
    clear_input_buffer(); // Clear newline from the buffer

    printf("Enter user email: ");
    fgets(users[*user_count].email, MAX_LENGTH, stdin);
    users[*user_count].email[strcspn(users[*user_count].email, "\n")] = 0; // Remove newline

    (*user_count)++;
}

void display_users(User users[], int user_count) {
    if (user_count == 0) {
        printf("No users to display.\n");
        return;
    }

    printf("\n--- List of Users ---\n");
    for (int i = 0; i < user_count; i++) {
        printf("User %d:\n", i + 1);
        printf("Name: %s\n", users[i].name);
        printf("Age: %d\n", users[i].age);
        printf("Email: %s\n\n", users[i].email);
    }
}

void search_user(User users[], int user_count) {
    char search_name[MAX_LENGTH];
    printf("Enter user name to search for: ");
    fgets(search_name, MAX_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < user_count; i++) {
        if (strcasecmp(users[i].name, search_name) == 0) { // Case-insensitive comparison
            printf("User found!\n");
            printf("Name: %s\n", users[i].name);
            printf("Age: %d\n", users[i].age);
            printf("Email: %s\n", users[i].email);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("User not found.\n");
    }
}

void remove_user(User users[], int *user_count) {
    char delete_name[MAX_LENGTH];
    printf("Enter user name to remove: ");
    fgets(delete_name, MAX_LENGTH, stdin);
    delete_name[strcspn(delete_name, "\n")] = 0; // Remove newline

    int found = -1;
    for (int i = 0; i < *user_count; i++) {
        if (strcasecmp(users[i].name, delete_name) == 0) {
            found = i;
            break;
        }
    }
    
    if (found != -1) {
        for (int i = found; i < *user_count - 1; i++) {
            users[i] = users[i + 1]; // Shift users left
        }
        (*user_count)--;
        printf("User '%s' removed successfully.\n", delete_name);
    } else {
        printf("User not found.\n");
    }
}

void print_menu() {
    printf("\n--- User Management System ---\n");
    printf("1. Add User\n");
    printf("2. Display Users\n");
    printf("3. Search User\n");
    printf("4. Remove User\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    User users[MAX_USERS];
    int user_count = 0;
    int option;

    while (1) {
        print_menu();
        scanf("%d", &option);
        clear_input_buffer(); // Clear newline after scanf

        switch (option) {
            case 1:
                add_user(users, &user_count);
                break;
            case 2:
                display_users(users, user_count);
                break;
            case 3:
                search_user(users, user_count);
                break;
            case 4:
                remove_user(users, &user_count);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}