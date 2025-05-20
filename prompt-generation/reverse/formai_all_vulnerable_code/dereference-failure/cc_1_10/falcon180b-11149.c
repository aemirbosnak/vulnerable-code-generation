//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 80
#define TRUE 1
#define FALSE 0

int command_count = 0;
char commands[MAX_COMMANDS][MAX_COMMAND_LENGTH];

void add_command(char* command) {
    strcpy(commands[command_count], command);
    command_count++;
}

int get_command_count() {
    return command_count;
}

char* get_command(int index) {
    return commands[index];
}

void execute_command(char* command) {
    pid_t pid = fork();

    if(pid == 0) {
        system(command);
        exit(0);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

void handle_sigint(int signum) {
    printf("\nExiting...\n");
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);

    char input[MAX_COMMAND_LENGTH];

    printf("Welcome to the Smart Home Automation System!\n");

    while(TRUE) {
        printf("Enter a command (or type 'exit' to quit): ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if(strcmp(input, "exit") == 0) {
            break;
        } else {
            add_command(input);
        }
    }

    for(int i = 0; i < command_count; i++) {
        execute_command(get_command(i));
    }

    return 0;
}