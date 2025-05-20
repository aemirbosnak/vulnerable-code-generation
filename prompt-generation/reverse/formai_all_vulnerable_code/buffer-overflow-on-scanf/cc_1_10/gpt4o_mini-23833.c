//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_LOG_SIZE 256

typedef struct {
    char username[50];
    time_t last_login;
} User;

User users[MAX_USERS];
int user_count = 0;

void add_user(const char *username) {
    if (user_count >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }

    // Initialize a new user
    strcpy(users[user_count].username, username);
    users[user_count].last_login = time(NULL);
    user_count++;

    printf("User %s added successfully.\n", username);
}

void log_activity(const char *activity) {
    FILE *log_file = fopen("activity_log.txt", "a");
    if (!log_file) {
        perror("Failed to open log file");
        return;
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now);

    // Remove newline from the time string
    time_str[strcspn(time_str, "\n")] = 0;

    fprintf(log_file, "[%s] %s\n", time_str, activity);
    fclose(log_file);
}

void display_users() {
    printf("Currently Registered Users:\n");
    for (int i = 0; i < user_count; i++) {
        printf("Username: %s, Last Login: %s", users[i].username, ctime(&users[i].last_login));
    }
}

void simulate_user_login(const char *username) {
    int user_found = 0;

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            users[i].last_login = time(NULL);
            user_found = 1;
            log_activity(username);
            printf("User %s logged in successfully.\n", username);
            return;
        }
    }

    if (!user_found) {
        printf("User %s not found for login.\n", username);
    }
}

void display_log() {
    char buffer[MAX_LOG_SIZE];
    FILE *log_file = fopen("activity_log.txt", "r");
    if (!log_file) {
        perror("Failed to open log file");
        return;
    }

    printf("Activity Log:\n");
    while (fgets(buffer, sizeof(buffer), log_file)) {
        printf("%s", buffer);
    }

    fclose(log_file);
}

int main() {
    int choice;
    char username[50];

    while (1) {
        printf("\n--- System Administration Menu ---\n");
        printf("1. Add User\n");
        printf("2. Simulate User Login\n");
        printf("3. Display Users\n");
        printf("4. Display Activity Log\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter username to add: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove newline character
                add_user(username);
                break;

            case 2:
                printf("Enter username to login: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove newline character
                simulate_user_login(username);
                break;

            case 3:
                display_users();
                break;

            case 4:
                display_log();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}