//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256
#define LOGFILE "login_attempts.log"
#define AUTH_USERS_FILE "authorized_users.txt"

bool is_authorized_user(const char* username) {
    FILE* auth_file = fopen(AUTH_USERS_FILE, "r");
    if (auth_file == NULL) {
        perror("Could not open authorized users file");
        return false;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), auth_file) != NULL) {
        line[strcspn(line, "\n")] = 0;  // Remove newline character
        if (strcmp(line, username) == 0) {
            fclose(auth_file);
            return true;   
        }
    }

    fclose(auth_file);
    return false;
}

void log_attempt(const char* username, bool authorized) {
    FILE* log_file = fopen(LOGFILE, "a");
    if (log_file == NULL) {
        perror("Could not open log file for writing");
        return;
    }

    fprintf(log_file, "User: %s - %s\n", username, authorized ? "Authorized" : "Unauthorized");
    fclose(log_file);
}

void alert_unauthorized_access(const char* username) {
    printf("ALERT: Unauthorized access attempt by user: %s\n", username);
}

void monitor_logins() {
    char username[MAX_LINE_LENGTH];
    printf("Enter username to login: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;  // Remove newline character

    bool authorized = is_authorized_user(username);
    
    log_attempt(username, authorized);
    
    if (!authorized) {
        alert_unauthorized_access(username);
    } else {
        printf("Welcome, %s!\n", username);
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("Select an option:\n");
        printf("1. Attempt login\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline character from input buffer

        switch (choice) {
            case 1:
                monitor_logins();
                break;
            case 2:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}