//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multiplayer
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#define MAX_USERS 50 // maximum number of users
#define MAX_CHARS 1024 // maximum characters per input line

typedef struct User {
    int id; // unique user ID
    char username[30]; // username string
    int pid; // process ID of the user's shell process
    int active; // boolean flag indicating if user is currently active
    int prompt; // boolean flag indicating if the user should display the custom prompt
    char prompt_text[30]; // custom prompt string for the user
} User;

User users[MAX_USERS]; // array of users
int user_count = 0; // current user count
char username[30]; // username of current user
int prompt = 0; // boolean flag indicating if custom prompt should be used
char prompt_text[30]; // custom prompt string

void setup() {
    printf("Welcome to the multiplayer Unix-like shell!\n");
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Creating shell for user '%s'...\n", username);
    users[user_count].id = user_count;
    strcpy(users[user_count].username, username);
    users[user_count].pid = getpid();
    users[user_count].active = 1;
    users[user_count].prompt = 0;
    user_count++;
}

void execute(char* args[]) {
    int pid = fork();

    if (pid < 0) {
        printf("Error: fork failed.\n");
        return;
    } else if (pid == 0) {
        if (execvp(args[0], args) < 0) {
            printf("Error: could not execute command.\n");
        }
        exit(0);
    } else {
        wait(NULL);
    }
}

void sigint_handler(int signum) {
    printf("\n");
    return;
}

void print_prompt() {
    if (prompt) {
        printf("%s", prompt_text);
    } else {
        printf("%s$ ", username);
    }
}

int main(int argc, char* argv[]) {
    setup();

    while (1) {
        signal(SIGINT, sigint_handler);
        print_prompt();
        char line[MAX_CHARS];
        fgets(line, MAX_CHARS, stdin);
        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "") == 0) {
            continue;
        }

        char* args[MAX_CHARS];
        int arg_count = 0;
        char* token = strtok(line, " ");

        while (token != NULL) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        if (strcmp(args[0], "exit") == 0) {
            printf("Goodbye, %s!\n", username);
            return 0;
        } else if (strcmp(args[0], "prompt") == 0) {
            if (arg_count < 2) {
                printf("Error: prompt command requires an argument.\n");
            } else {
                prompt = 1;
                strcpy(prompt_text, args[1]);
            }
        } else if (strcmp(args[0], "users") == 0) {
            printf("Active users:\n");
            for (int i = 0; i < user_count; i++) {
                if (users[i].active) {
                    printf("- %s\n", users[i].username);
                }
            }
        } else if (strcmp(args[0], "connect") == 0) {
            if (arg_count < 2) {
                printf("Error: connect command requires a username argument.\n");
            } else {
                int found = 0;
                for (int i = 0; i < user_count; i++) {
                    if (strcmp(users[i].username, args[1]) == 0) {
                        found = 1;
                        if (users[i].active) {
                            printf("User '%s' is already connected.\n", args[1]);
                        } else {
                            users[i].active = 1;
                            printf("Connected to user '%s'.\n", args[1]);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("Error: user '%s' not found.\n", args[1]);
                }
            }
        } else if (strcmp(args[0], "disconnect") == 0) {
            if (arg_count < 2) {
                printf("Error: disconnect command requires a username argument.\n");
            } else {
                int found = 0;
                for (int i = 0; i < user_count; i++) {
                    if (strcmp(users[i].username, args[1]) == 0) {
                        found = 1;
                        if (!users[i].active) {
                            printf("User '%s' is already disconnected.\n", args[1]);
                        } else {
                            users[i].active = 0;
                            printf("Disconnected from user '%s'.\n", args[1]);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("Error: user '%s' not found.\n", args[1]);
                }
            }
        } else {
            execute(args);
        }
    }

    return 0;
}