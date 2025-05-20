//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ATTEMPTS 5 //maximum login attempts
#define MAX_USERS 2 //maximum number of users
#define MAX_LOGIN_ATTEMPTS 3 //maximum login attempts per user
#define MAX_LOG_LENGTH 1000 //maximum log length

typedef struct {
    char username[20];
    char password[20];
    int failed_attempts;
    int locked_out;
} User;

void log_event(char* event) {
    time_t t;
    time(&t);
    printf("%s - %s\n", ctime(&t), event);
}

void detect_intrusion(User* users, int num_users) {
    int i, j, k;
    char event[MAX_LOG_LENGTH];

    for(i = 0; i < num_users; i++) {
        if(users[i].locked_out) {
            sprintf(event, "User %s is locked out", users[i].username);
            log_event(event);
            continue;
        }

        if(users[i].failed_attempts >= MAX_LOGIN_ATTEMPTS) {
            users[i].locked_out = 1;
            sprintf(event, "User %s is locked out", users[i].username);
            log_event(event);
            continue;
        }

        for(j = 0; j < MAX_ATTEMPTS; j++) {
            char username[20];
            char password[20];
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);

            for(k = 0; k < num_users; k++) {
                if(strcmp(username, users[k].username) == 0 && strcmp(password, users[k].password) == 0) {
                    sprintf(event, "User %s logged in", users[k].username);
                    log_event(event);
                    users[k].failed_attempts = 0;
                    break;
                }
            }

            if(k == num_users) {
                sprintf(event, "Failed login attempt by %s", username);
                log_event(event);
                users[i].failed_attempts++;
            } else {
                break;
            }
        }

        if(j == MAX_ATTEMPTS) {
            sprintf(event, "Maximum login attempts reached for user %s", users[i].username);
            log_event(event);
            users[i].locked_out = 1;
        }
    }
}

int main() {
    User users[MAX_USERS] = {{"alice", "password", 0, 0}, {"bob", "qwerty", 0, 0}};

    detect_intrusion(users, MAX_USERS);

    return 0;
}