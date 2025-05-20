//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOGS 10000 // Max number of logs to store
#define MAX_ADDR 256 // Max IP address length
#define MAX_USER 256 // Max username length
#define MAX_PASS 256 // Max password length
#define MAX_DATA 1024 // Max data length
#define MAX_ATTEMPTS 5 // Max login attempts per user

// Struct to store login attempt logs
struct log_entry {
    char address[MAX_ADDR];
    char username[MAX_USER];
    char password[MAX_PASS];
    time_t timestamp;
};

// Function to check if a user has exceeded max login attempts
int check_attempts(struct log_entry *logs, int num_logs, char *username) {
    int count = 0;
    time_t now = time(NULL);
    // Iterate through logs to count attempts for specified user
    for (int i = 0; i < num_logs; i++) {
        if (strcmp(logs[i].username, username) == 0) {
            if ((now - logs[i].timestamp) <= 60 && count >= MAX_ATTEMPTS) {
                // User has exceeded max attempts within past minute
                return 1;
            }
            else if ((now - logs[i].timestamp) <= 60) {
                // User has attempted login within past minute
                count++;
            }
        }
    }
    return 0;
}

// Main function
int main() {
    struct log_entry logs[MAX_LOGS]; // Array to store logs
    int num_logs = 0; // Number of logs currently stored
    char input[MAX_DATA]; // Buffer for input data
    // Loop to continuously receive input and check for login attempts
    while (1) {
        printf("Enter login data (in the form of IP address, username, password):\n");
        fgets(input, MAX_DATA, stdin);
        // Parse input data and store in log entry struct
        sscanf(input, "%s %s %s", logs[num_logs].address, logs[num_logs].username, logs[num_logs].password);
        logs[num_logs].timestamp = time(NULL);
        // Check for max login attempts for this user
        if (check_attempts(logs, num_logs, logs[num_logs].username)) {
            printf("Max login attempts exceeded for user %s\n", logs[num_logs].username);
            break;
        }
        // Add log entry to log array
        num_logs++;
        // Check if max logs exceeded and remove oldest log if necessary
        if (num_logs > MAX_LOGS) {
            memmove(logs, logs+1, sizeof(struct log_entry) * (num_logs - 1));
            num_logs--;
        }
    }
    return 0;
}