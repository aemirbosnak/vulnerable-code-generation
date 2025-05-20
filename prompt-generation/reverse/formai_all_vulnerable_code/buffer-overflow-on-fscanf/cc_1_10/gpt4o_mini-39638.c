//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>

#define MAX_USERS 100
#define USERNAME_LENGTH 32
#define BUFFER_SIZE 256

typedef struct UserInfo {
    char username[USERNAME_LENGTH];
    time_t last_login;
    int login_count;
} UserInfo;

UserInfo users[MAX_USERS];
int user_count = 0;

void load_user_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open user data file");
        return;
    }
    while (fscanf(file, "%s %ld %d", users[user_count].username,
                  &users[user_count].last_login, &users[user_count].login_count) != EOF) {
        user_count++;
    }
    fclose(file);
}

void save_user_data(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open user data file for saving");
        return;
    }
    for (int i = 0; i < user_count; i++) {
        fprintf(file, "%s %ld %d\n", users[i].username, users[i].last_login, users[i].login_count);
    }
    fclose(file);
}

void add_user(const char *username) {
    if (user_count >= MAX_USERS) {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }
    strcpy(users[user_count].username, username);
    users[user_count].last_login = time(NULL);
    users[user_count].login_count = 1;
    user_count++;
}

void update_user(const char *username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            users[i].last_login = time(NULL);
            users[i].login_count++;
            return;
        }
    }
    printf("User %s not found. Adding user.\n", username);
    add_user(username);
}

void display_users() {
    printf("User Report:\n");
    printf("Username\tLast Login\t\t\tLogin Count\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < user_count; i++) {
        char last_login_string[BUFFER_SIZE];
        struct tm *tm_info = localtime(&users[i].last_login);
        strftime(last_login_string, sizeof(last_login_string), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("%s\t%s\t%d\n", users[i].username, last_login_string, users[i].login_count);
    }
}

int main() {
    const char *data_filename = "user_data.txt";
    
    load_user_data(data_filename);
    
    char command[BUFFER_SIZE];
    char username[USERNAME_LENGTH];

    while (1) {
        printf("Enter username to log in (or type 'exit' to quit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;  // Remove newline

        if (strcmp(command, "exit") == 0) {
            break;
        }

        update_user(command);
        save_user_data(data_filename);
        display_users();
    }

    return 0;
}