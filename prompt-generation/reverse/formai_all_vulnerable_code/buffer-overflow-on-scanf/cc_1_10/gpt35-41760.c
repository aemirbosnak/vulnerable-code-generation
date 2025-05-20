//FormAI DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 10
#define MAX_USERS 10

typedef struct User {
    char name[50];
    char password[PASSWORD_LENGTH + 1];
} User;

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void display_menu() {
    printf("\n1. Create new user\n");
    printf("2. Change user password\n");
    printf("3. Delete user\n");
    printf("4. Quit\n");
}

User get_user_by_name(User users[], int num_users, char name[]) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0)
            return users[i];
    }
    User no_user = {"", ""};
    return no_user;
}

User create_user() {
    User new_user;
    printf("\nEnter new user name: ");
    scanf("%s", new_user.name);
    
    printf("Enter new password: ");
    scanf("%s", new_user.password);
    clear_input();
    
    printf("User created!\n");
    return new_user;
}

void change_user_password(User users[], int num_users) {
    char name[50];
    printf("\nEnter user name: ");
    scanf("%s", name);
    clear_input();
    
    User user_to_modify = get_user_by_name(users, num_users, name);
    if (strcmp(user_to_modify.name, "") == 0) {
        printf("User not found.\n");
    } else {
        printf("Enter new password: ");
        scanf("%s", user_to_modify.password);
        clear_input();
        printf("Password changed for user %s.\n", user_to_modify.name);
    }
}

void delete_user(User users[], int *num_users) {
    char name[50];
    printf("\nEnter user name: ");
    scanf("%s", name);
    clear_input();
    
    for (int i = 0; i < *num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            for (int j = i; j < (*num_users - 1); j++) {
                users[j] = users[j+1];
            }
            (*num_users)--;
            printf("User %s deleted.\n", name);
            return;
        }
    }
    printf("User %s not found.\n", name);
}

int main() {
    User users[MAX_USERS];
    int num_users = 0;
    int choice;
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input();
        
        switch (choice) {
            case 1:
                if (num_users >= MAX_USERS) {
                    printf("Maximum number of users reached.\n");
                    break;
                }
                users[num_users] = create_user();
                num_users++;
                break;
            case 2:
                change_user_password(users, num_users);
                break;
            case 3:
                delete_user(users, &num_users);
                break;
            case 4:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}