//FormAI DATASET v1.0 Category: Password management ; Style: cheerful
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_NUM_USERS 10

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} user_t;

void print_welcome_message() {
    printf("Welcome to the happy password management program!\n");
}

void print_menu() {
    printf("Please select an option from the menu below:\n");
    printf("1. Add user\n");
    printf("2. Change password\n");
    printf("3. Remove user\n");
    printf("4. View all users\n");
    printf("5. Quit\n");
}

int get_choice() {
    int choice;
    
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    return choice;
}

void add_user(user_t users[], int *num_users) {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Enter the username: ");
    scanf("%s", username);
    
    printf("Enter the password: ");
    scanf("%s", password);
    
    // Check if user already exists
    for (int i = 0; i < *num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("User already exists\n");
            return;
        }
    }
    
    // Add user to array
    strcpy(users[*num_users].username, username);
    strcpy(users[*num_users].password, password);
    (*num_users)++;
    
    printf("Successfully added user!\n");
}

void change_password(user_t users[], int num_users) {
    char username[MAX_PASSWORD_LENGTH];
    char old_password[MAX_PASSWORD_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];
    
    printf("Enter the username: ");
    scanf("%s", username);
    
    printf("Enter the old password: ");
    scanf("%s", old_password);
    
    printf("Enter the new password: ");
    scanf("%s", new_password);
    
    // Find user in array and change password
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, old_password) == 0) {
            strcpy(users[i].password, new_password);
            printf("Successfully changed password!\n");
            return;
        }
    }
    
    printf("User not found or incorrect password\n");
}

void remove_user(user_t users[], int *num_users) {
    char username[MAX_PASSWORD_LENGTH];
    
    printf("Enter the username: ");
    scanf("%s", username);
    
    // Find user in array and remove
    for (int i = 0; i < *num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            for (int j = i; j < *num_users - 1; j++) {
                strcpy(users[j].username, users[j+1].username);
                strcpy(users[j].password, users[j+1].password);
            }
            
            (*num_users)--;
            printf("Successfully removed user!\n");
            return;
        }
    }
    
    printf("User not found\n");
}

void view_users(user_t users[], int num_users) {
    printf("List of all users:\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s\n", users[i].username);
    }
}

int main() {
    user_t users[MAX_NUM_USERS];
    int num_users = 0;
    int choice;
    
    print_welcome_message();
    
    do {
        print_menu();
        choice = get_choice();
        
        switch (choice) {
            case 1:
                add_user(users, &num_users);
                break;
            case 2:
                change_password(users, num_users);
                break;
            case 3:
                remove_user(users, &num_users);
                break;
            case 4:
                view_users(users, num_users);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}