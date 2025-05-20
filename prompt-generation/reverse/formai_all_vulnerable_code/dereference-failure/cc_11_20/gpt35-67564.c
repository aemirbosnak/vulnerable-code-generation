//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 512
#define MAX_ARG 16

int main() {
    char input[MAX_INPUT];

    while(1) {
        printf("$ ");
        fflush(stdout);

        fgets(input, MAX_INPUT, stdin);

        if (feof(stdin)) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if(strlen(input) == 0) {
            continue;
        }

        // Parse input into array of arguments
        char* argv[MAX_ARG] = {0};
        char* token;
        int arg_num = 0;

        token = strtok(input, " ");

        while(token != NULL && arg_num < MAX_ARG) {
            argv[arg_num] = token;
            token = strtok(NULL, " ");
            arg_num++;
        }

        // Execute command based on arguments
        if(strcmp(argv[0], "exit") == 0) {
            exit(0);
        } else {
            pid_t pid = fork();

            if(pid < 0) {
                perror("fork");
                exit(1);
            } else if(pid == 0) {
                // Child process
                execvp(argv[0], argv);
                // execvp only returns if there is an error
                perror("execvp");
                exit(1);
            } else {
                // Parent process
                int status;
                waitpid(pid, &status, 0);

                if(WIFEXITED(status)) {
                    int code = WEXITSTATUS(status);
                    printf("Command exited with status %d\n", code);
                } else if(WIFSIGNALED(status)) {
                    int signal_num = WTERMSIG(status);
                    printf("Command terminated with signal %d\n", signal_num);
                }
            }
        }

        memset(input, 0, MAX_INPUT);
    }

    printf("\n");
    return 0;
}