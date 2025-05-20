//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 1000  // maximum number of logs to be stored in the system
#define MAX_ATTEMPTS 5  // maximum number of login attempts allowed before alarm is triggered
#define MAX_USERNAME 20  // maximum length of username
#define MAX_PASSWORD 20  // maximum length of password

// define a Log structure to store information about each login attempt
typedef struct Log {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char ip_address[16];
} Log;

// function to check if a given username and password combination is valid
int is_valid_login(char* username, char* password) {
    // check against a pre-defined list of usernames and passwords
    char* valid_usernames[] = {"admin", "user1", "user2"};
    char* valid_passwords[] = {"password1", "password2", "password3"};
    int i, len = sizeof(valid_usernames)/sizeof(valid_usernames[0]);
    for (i=0; i<len; i++) {
        if (strcmp(username, valid_usernames[i]) == 0 && strcmp(password, valid_passwords[i]) == 0) {
            return 1;  // valid login
        }
    }
    return 0;  // invalid login
}

int main() {
    Log logs[MAX_LOGS];  // array of Log objects to store login attempts
    int num_logs = 0;  // number of logs stored in the system
    int num_attempts = 0;  // number of attempts made by a user during a session
    char input_username[MAX_USERNAME], input_password[MAX_PASSWORD];  // variables to store user input
    char input_ip[16];  // variable to store user's IP address
    int alarm_triggered = 0;  // flag to indicate if alarm has been triggered

    printf("Welcome to the Intrusion Detection System!\n");

    while (1) {
        // get user input
        printf("Please enter your username: ");
        scanf("%s", input_username);
        printf("Please enter your password: ");
        scanf("%s", input_password);
        printf("Please enter your IP address: ");
        scanf("%s", input_ip);

        // check if login is valid
        if (is_valid_login(input_username, input_password)) {
            printf("Login successful.\n");

            // store login attempt in logs
            Log new_log;
            strcpy(new_log.username, input_username);
            strcpy(new_log.password, input_password);
            strcpy(new_log.ip_address, input_ip);
            logs[num_logs] = new_log;
            num_logs += 1;

            num_attempts = 0;  // reset number of attempts made by user
        } else {
            printf("Invalid login.\n");
            num_attempts += 1;
        }

        // check if user has made too many unsuccessful attempts
        if (num_attempts >= MAX_ATTEMPTS) {
            printf("Too many unsuccessful attempts. Alarm triggered.\n");
            alarm_triggered = 1;
        }

        // check if maximum number of logs has been reached
        if (num_logs >= MAX_LOGS) {
            printf("Maximum number of logs reached. System is full.\n");
            break;
        }

        // check if alarm has been triggered
        if (alarm_triggered) {
            printf("Please contact your system administrator.\n");
            break;
        }
    }

    return 0;
}