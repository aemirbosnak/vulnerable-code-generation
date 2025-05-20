//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char username[20];
    char password[PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

void clear_screen() {
    printf("\033[H\033[J"); // Clear the screen for a fresh start
}

void display_welcome_message() {
    printf("========================================\n");
    printf("          Password Manager              \n");
    printf("========================================\n");
}

void add_user() {
    if(user_count >= MAX_USERS) {
        printf("Max user limit reached. Cannot add more users.\n");
        return;
    }
    
    printf("Enter username: ");
    scanf("%s", users[user_count].username);
    
    printf("Enter password: ");
    scanf("%s", users[user_count].password);
    
    user_count++;
    printf("User added successfully!\n");
}

void view_users() {
    if(user_count == 0) {
        printf("No users to display.\n");
    } else {
        printf("Users List:\n");
        for(int i = 0; i < user_count; i++) {
            printf("Username: %s\n", users[i].username);
        }
    }
}

void delete_user() {
    char username[20];
    printf("Enter username to delete: ");
    scanf("%s", username);
    
    for(int i = 0; i < user_count; i++) {
        if(strcmp(users[i].username, username) == 0) {
            for(int j = i; j < user_count - 1; j++) {
                users[j] = users[j + 1]; // Shift users left
            }
            user_count--;
            printf("User %s deleted successfully!\n", username);
            return;
        }
    }
    printf("User not found!\n");
}

void update_user() {
    char username[20];
    printf("Enter username to update: ");
    scanf("%s", username);
    
    for(int i = 0; i < user_count; i++) {
        if(strcmp(users[i].username, username) == 0) {
            printf("Enter new password: ");
            scanf("%s", users[i].password);
            printf("Password updated successfully!\n");
            return;
        }
    }
    printf("User not found!\n");
}

void main_menu() {
    int choice;
    
    do {
        clear_screen();
        display_welcome_message();
        printf("1. Add User\n");
        printf("2. View Users\n");
        printf("3. Delete User\n");
        printf("4. Update User Password\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch(choice) {
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
                update_user();
                break;
            case 5:
                printf("Exiting the Password Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        if(choice != 5) {
            printf("Press Enter to continue...");
            while(getchar() != '\n'); // Clear the input buffer
            getchar(); // Wait for user
        }
    } while(choice != 5);
}

int main() {
    main_menu();
    return 0;
}