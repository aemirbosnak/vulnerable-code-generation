//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define MAX_USERS 10

typedef struct User {
    char name[NAME_LENGTH];
    int age;
} User;

void print_user(const User *user) {
    if (user == NULL) {
        printf("User is NULL.\n");
        return;
    }
    printf("Name: %s, Age: %d\n", user->name, user->age);
}

void allocate_users(User **users, int count) {
    *users = (User *)malloc(count * sizeof(User));
    if (*users == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

void input_user(User *user) {
    printf("Enter the name: ");
    fgets(user->name, NAME_LENGTH, stdin);
    user->name[strcspn(user->name, "\n")] = 0; // Remove newline character

    printf("Enter the age: ");
    scanf("%d", &user->age);
    getchar(); // Clear newline from input buffer
}

void free_users(User *users) {
    free(users);
}

void show_all_users(const User *users, int count) {
    printf("\nList of Users:\n");
    for (int i = 0; i < count; i++) {
        print_user(&users[i]);
    }
}

void find_user_by_name(const User *users, int count, const char *name) {
    printf("\nSearching for user: %s\n", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].name, name) == 0) {
            print_user(&users[i]);
            return;
        }
    }
    printf("User not found.\n");
}

int main() {
    User *users = NULL;
    int user_count;

    printf("How many users do you want to allocate? (Max: %d): ", MAX_USERS);
    scanf("%d", &user_count);
    getchar(); // Clear newline from input buffer

    if (user_count <= 0 || user_count > MAX_USERS) {
        fprintf(stderr, "Invalid number of users.\n");
        return EXIT_FAILURE;
    }

    allocate_users(&users, user_count);

    for (int i = 0; i < user_count; i++) {
        printf("\nEnter details for User %d:\n", i + 1);
        input_user(&users[i]);
    }

    show_all_users(users, user_count);

    char search_name[NAME_LENGTH];
    printf("\nEnter a name to search:");
    fgets(search_name, NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = 0; // Remove newline character

    find_user_by_name(users, user_count, search_name);

    free_users(users);
    return EXIT_SUCCESS;
}