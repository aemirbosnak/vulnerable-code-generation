//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

char *tokens[MAX_NUM_TOKENS];
char input[MAX_INPUT_SIZE];
char *token;
int status;
int num_tokens;

void parse_input(char *line) {
    num_tokens = 0;
    token = strtok(line, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }
}

int main() {
    pid_t child_pid;
    int i;

    printf("\n---------------------------------------------------\n");
    printf("|              Welcome to the Happiest Shell!       |\n");
    printf("|                                                 |\n");
    printf("---------------------------------------------------\n");

    while (1) {
        printf("\n%s> ", "Happy Shell:");
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strlen(input) - 1] = '\0'; // remove newline character

        if (strcmp(input, "exit") == 0) {
            break;
        }

        parse_input(input);

        switch (num_tokens) {
            case 0:
                printf("Please enter a command.\n");
                break;

            case 1:
                if (strcmp(tokens[0], "echo") == 0) {
                    printf("%s\n", tokens[0] + 5);
                    for (i = 1; i < num_tokens; i++) {
                        printf(" %s", tokens[i]);
                    }
                    printf("\n");
                } else {
                    printf("Invalid command: %s\n", tokens[0]);
                }
                break;

            case 2:
                if (strcmp(tokens[0], "cd") == 0) {
                    if (chdir(tokens[1]) != 0) {
                        perror("Error changing directory.");
                    }
                } else {
                    printf("Invalid command: %s\n", tokens[0]);
                }
                break;

            case 3:
                if (strcmp(tokens[0], "cat") == 0) {
                    int fd = open(tokens[1], O_RDONLY);
                    if (fd < 0) {
                        perror("Error opening file.");
                    } else {
                        ssize_t bytes_read;
                        char buffer[128];
                        while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
                            write(STDOUT_FILENO, buffer, bytes_read);
                        }
                        close(fd);
                    }
                } else {
                    printf("Invalid command: %s\n", tokens[0]);
                }
                break;

            default:
                child_pid = fork();
                if (child_pid < 0) {
                    perror("Error forking process.");
                } else if (child_pid > 0) {
                    int stat_loc;
                    waitpid(child_pid, &stat_loc, 0);
                    WIFEXITED(stat_loc) ? (status = WEXITSTATUS(stat_loc)) : (status = 127);
                } else {
                    execvp(tokens[0], tokens);
                    perror("Error executing command.");
                    exit(1);
                }
                break;
        }
    }

    return 0;
}