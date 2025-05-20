//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_USERS 100
#define USERNAME_LEN 32
#define PASSWORD_LEN 32

typedef struct User {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
} User;

User users[MAX_USERS];
int user_count = 0;

void load_users(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open user file");
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%s %s", users[user_count].username, users[user_count].password) == 2) {
        user_count++;
        if (user_count >= MAX_USERS) break;
    }
    
    fclose(file);
}

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }

    User new_user;
    printf("Enter new username: ");
    scanf("%s", new_user.username);
    printf("Enter new password: ");
    scanf("%s", new_user.password);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, new_user.username) == 0) {
            printf("Username already exists.\n");
            return;
        }
    }

    users[user_count++] = new_user;
    printf("User registered successfully!\n");
}

void save_users(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Could not save user file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < user_count; i++) {
        fprintf(file, "%s %s\n", users[i].username, users[i].password);
    }

    fclose(file);
    printf("User data saved successfully!\n");
}

void list_users() {
    printf("Registered users:\n");
    for (int i = 0; i < user_count; i++) {
        printf("- %s\n", users[i].username);
    }
}

void display_menu() {
    printf("1. Register User\n");
    printf("2. List Users\n");
    printf("3. Save Users\n");
    printf("4. Exit\n");
}

int main() {
    const char *filename = "users.txt";
    load_users(filename);

    int choice;
    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                list_users();
                break;
            case 3:
                save_users(filename);
                break;
            case 4:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}