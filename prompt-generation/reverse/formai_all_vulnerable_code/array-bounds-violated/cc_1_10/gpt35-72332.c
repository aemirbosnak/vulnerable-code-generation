//FormAI DATASET v1.0 Category: Password management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
  char username[MAX_PASSWORD_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
} user_t;

void clear_input(void) {
    int ch = 0;
    /* Read until end of input or newline */
    while(ch != EOF && ch != '\n') {
        ch = getchar();
    }
}

char *hash_password(const char *password) {
    /* Simple hashing function that returns original password reversed */
    char *hash = malloc(MAX_PASSWORD_LENGTH + 1);
    int len = strlen(password);
    for(int i = 0; i < len; i++) {
        hash[i] = password[len - 1 - i];
    }
    hash[len] = '\0';
    return hash;
}

int main(void) {
    int num_users = 0;
    user_t users[MAX_USERS];

    while(1) {
        printf("\nEnter a command ('add', 'lookup', 'exit'): ");
        char command[MAX_PASSWORD_LENGTH + 1];
        if(fgets(command, MAX_PASSWORD_LENGTH + 1, stdin) == NULL) {
            printf("Error reading input\n");
            continue;
        }
        /* Remove trailing newline from input */
        int len = strlen(command);
        if(command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }
        /* Convert command to uppercase */
        for(char *ptr = command; *ptr != '\0'; ptr++) {
            *ptr = toupper(*ptr);
        }

        if(strcmp(command, "ADD") == 0) {
            if(num_users == MAX_USERS) {
                printf("Maximum number of users reached!\n");
                continue;
            }
            user_t user;
            printf("\nEnter username: ");
            if(fgets(user.username, MAX_PASSWORD_LENGTH + 1, stdin) == NULL) {
                printf("Error reading input\n");
                clear_input();
                continue;
            }
            /* Remove trailing newline from username */
            len = strlen(user.username);
            if(user.username[len - 1] == '\n') {
                user.username[len - 1] = '\0';
            }
            printf("Enter password: ");
            if(fgets(user.password, MAX_PASSWORD_LENGTH + 1, stdin) == NULL) {
                printf("Error reading input\n");
                clear_input();
                continue;
            }
            /* Remove trailing newline from password */
            len = strlen(user.password);
            if(user.password[len - 1] == '\n') {
                user.password[len - 1] = '\0';
            }
            char *hash = hash_password(user.password);
            strcpy(user.password, hash);
            free(hash);
            users[num_users++] = user;
            printf("User added\n");
        }
        else if(strcmp(command, "LOOKUP") == 0) {
            printf("\nEnter username: ");
            char username[MAX_PASSWORD_LENGTH + 1];
            if(fgets(username, MAX_PASSWORD_LENGTH + 1, stdin) == NULL) {
                printf("Error reading input\n");
                clear_input();
                continue;
            }
            /* Remove trailing newline from username */
            len = strlen(username);
            if(username[len - 1] == '\n') {
                username[len - 1] = '\0';
            }
            for(int i = 0; i < num_users; i++) {
                if(strcmp(users[i].username, username) == 0) {
                    printf("Found user '%s'\n", username);
                    printf("Password hash: '%s'\n", users[i].password);
                    break;
                }
            }
        }
        else if(strcmp(command, "EXIT") == 0) {
            printf("Exiting program\n");
            return 0;
        }
        else {
            printf("Invalid command: '%s'\n", command);
        }
    }
}