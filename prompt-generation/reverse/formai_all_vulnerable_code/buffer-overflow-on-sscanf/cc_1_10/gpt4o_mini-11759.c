//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char user_id[50];
    int login_count;
    long total_duration; // in seconds
    long last_login_time; // timestamp of last login
} UserActivity;

UserActivity users[MAX_USERS];
int num_users = 0;

void parse_log_line(char *line) {
    char date_time[50], user_id[50], action[10];
    long duration;
    
    sscanf(line, "%s %s %s", date_time, user_id, action);
    
    if (strcmp(action, "login") == 0) {
        // Handle login
        for (int i = 0; i < num_users; i++) {
            if (strcmp(users[i].user_id, user_id) == 0) {
                users[i].login_count++;
                users[i].last_login_time = atol(date_time); // Storing time as a long for simplicity
                return;
            }
        }
        
        // New user
        strcpy(users[num_users].user_id, user_id);
        users[num_users].login_count = 1;
        users[num_users].total_duration = 0;
        users[num_users].last_login_time = atol(date_time);
        num_users++;
        
    } else if (strcmp(action, "logout") == 0) {
        // Handle logout
        sscanf(line, "%s %s %s %ld", date_time, user_id, action, &duration);
        for (int i = 0; i < num_users; i++) {
            if (strcmp(users[i].user_id, user_id) == 0) {
                users[i].total_duration += duration; // Add duration to the total for this user
                return;
            }
        }
    }
}

void print_user_summary() {
    printf("User Activity Summary:\n");
    printf("%-20s %-15s %-15s %-15s\n", "User ID", "Login Count", "Total Duration", "Average Duration");
    
    for (int i = 0; i < num_users; i++) {
        long average_duration = (users[i].login_count > 0) ? users[i].total_duration / users[i].login_count : 0;
        printf("%-20s %-15d %-15ld %-15ld\n", users[i].user_id, users[i].login_count, users[i].total_duration, average_duration);
    }
}

int main() {
    FILE *log_file = fopen("activity.log", "r");
    if (!log_file) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    
    while (fgets(line, sizeof(line), log_file)) {
        parse_log_line(line);
    }
    
    fclose(log_file);
    
    print_user_summary();
    
    return 0;
}