//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_USERS 100
#define USERNAME_LENGTH 50
#define PASSWORD_LENGTH 50

typedef struct User {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    time_t last_login;
} User;

User users[MAX_USERS];
int user_count = 0;

void add_user(const char* username, const char* password) {
    if (user_count >= MAX_USERS) {
        fprintf(stderr, "User limit reached. Cannot add more users.\n");
        return;
    }
    strcpy(users[user_count].username, username);
    strcpy(users[user_count].password, password);
    users[user_count].last_login = 0; // Not logged in yet
    user_count++;
    printf("User %s added successfully.\n", username);
}

int authenticate_user(const char* username, const char* password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            return i; // Return the index of the authenticated user
        }
    }
    return -1; // Authentication failed
}

void update_last_login(int user_index) {
    users[user_index].last_login = time(NULL);
}

void show_user_info(int user_index) {
    struct tm *tm_info;
    char buffer[26];

    tm_info = localtime(&users[user_index].last_login);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    
    printf("User: %s\n", users[user_index].username);
    printf("Last Login: %s\n", buffer);
}

void list_users() {
    printf("Registered Users:\n");
    for (int i = 0; i < user_count; i++) {
        printf("Username: %s\n", users[i].username);
    }
}

void clear_console() {
    if (system("clear") == -1) {
        fprintf(stderr, "Failed to clear console.\n");
    }
}

void menu() {
    printf("1. Add User\n");
    printf("2. Authenticate User\n");
    printf("3. List Users\n");
    printf("4. Show User Info\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    
    while(1) {
        clear_console();
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                add_user(username, password);
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                int user_index = authenticate_user(username, password);
                if (user_index != -1) {
                    update_last_login(user_index);
                    printf("Authentication successful!\n");
                } else {
                    printf("Authentication failed!\n");
                }
                break;

            case 3:
                list_users();
                break;

            case 4:
                printf("Enter username to show info: ");
                scanf("%s", username);
                int info_index = authenticate_user(username, "");
                if (info_index != -1) {
                    show_user_info(info_index);
                } else {
                    printf("User not found!\n");
                }
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        printf("Press Enter to continue...");
        while (getchar() != '\n'); // Clear the buffer
        getchar(); // Wait for Enter
    }
    
    return 0;
}