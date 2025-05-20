//FormAI DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define PASSWORD_LEN 20   // Max length of the user passwords
#define MAX_USERS 10       // Maximum number of users that can be stored

// Struct to hold user information, including username and password
struct user {
    char username[20];
    char password[PASSWORD_LEN + 1];   // +1 for null terminator
};

// Helper function to print out a menu of options for the user
void print_menu() {
    printf("\nPassword Manager\n");
    printf("---------------------\n");
    printf("1. Add User\n");
    printf("2. List Users\n");
    printf("3. Change Password\n");
    printf("4. Exit\n");
}

// Helper function to get input from the user as a string
void get_input(char *input, int max_len) {
    fgets(input, max_len, stdin);
    // Remove newline character if present
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
}

// Helper function to compare two strings case-insensitively
int strcasecmp(const char *s1, const char *s2) {
    for (; *s1 && *s2; ++s1, ++s2) {
        if (*s1 == *s2 || (*s1 ^ 32) == *s2) {
            continue;
        }
        break;
    }
    return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

// Helper function to add a new user to the system
void add_user(struct user *users, int *num_users) {
    char username[20];
    char password[PASSWORD_LEN + 1];
    printf("\nEnter Username: ");
    get_input(username, sizeof(username));
    for (int i = 0; i < *num_users; ++i) {
        if (strcasecmp(username, users[i].username) == 0) {
            printf("--> Error: Username already exists!");
            return;
        }
    }
    printf("Enter Password: ");
    get_input(password, sizeof(password));
    if (strlen(password) > PASSWORD_LEN) {
        printf("--> Error: Password is too long");
        return;
    }
    struct user new_user = {0};
    strncpy(new_user.username, username, sizeof(new_user.username));
    strncpy(new_user.password, password, sizeof(new_user.password));
    users[*num_users] = new_user;
    ++*num_users;
    printf("--> User Added Successfully!");
}

// Helper function to list all users in the system
void list_users(const struct user *users, int num_users) {
    printf("\nList of Users\n");
    printf("---------------------\n");
    for (int i = 0; i < num_users; ++i) {
        printf("Username: %s\n", users[i].username);
    }
}

// Helper function to change the password of an existing user
void change_password(struct user *users, int num_users) {
    char username[20];
    char old_password[PASSWORD_LEN + 1];
    char new_password[PASSWORD_LEN + 1];
    printf("\nEnter Username: ");
    get_input(username, sizeof(username));
    for (int i = 0; i < num_users; ++i) {
        if (strcasecmp(username, users[i].username) == 0) {
            printf("Enter Old Password: ");
            get_input(old_password, sizeof(old_password));
            if (strcasecmp(users[i].password, old_password) == 0) {
                printf("Enter New Password: ");
                get_input(new_password, sizeof(new_password));
                if (strlen(new_password) > PASSWORD_LEN) {
                    printf("--> Error: Password is too long");
                    return;
                }
                strncpy(users[i].password, new_password, sizeof(users[i].password));
                printf("--> Password Changed Successfully!");
                return;
            }
            else {
                printf("--> Error: Incorrect Password!");
                return;
            }
        }
    }
    printf("--> Error: User Not Found!");
}

int main() {
    struct user users[MAX_USERS] = {0};
    int num_users = 0;
    int choice = 0;

    while (choice != 4) {
        print_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character left by scanf
        
        switch (choice) {
            case 1:
                add_user(users, &num_users);
                break;
            case 2:
                list_users(users, num_users);
                break;
            case 3:
                change_password(users, num_users);
                break;
            case 4:
                printf("--> Goodbye!");
                break;
            default:
                printf("--> Invalid choice!");
                break;
        }
    }

    return 0;
}