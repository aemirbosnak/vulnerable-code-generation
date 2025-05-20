//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

char* tokens[MAX_NUM_TOKENS];

void* execute_command(void* str_command)
{
    char* command = (char*)str_command;
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        printf("fork failed\n");
        return NULL;
    }
    else if (pid == 0) {
        // child process
        execvp(tokens[0], tokens);
        printf("execvp failed\n");
        return NULL;
    }
    else {
        // parent process
        waitpid(pid, &status, 0);
    }
    return NULL;
}

int parse_command(char* str_command)
{
    char input[MAX_INPUT_SIZE];
    strcpy(input, str_command);

    char* token = strtok(input, " \n");
    int i = 0;
    while (token != NULL && i < MAX_NUM_TOKENS) {
        tokens[i] = token;
        token = strtok(NULL, " \n");
        i++;
    }
    tokens[i] = NULL;

    if (tokens[0] == NULL) {
        return 0;
    }
    return 1;
}

int main()
{
    char input[MAX_INPUT_SIZE];
    int num_threads = 0;
    pthread_t threads[MAX_NUM_TOKENS];

    while (1) {
        // get user input
        printf("Shell> ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // remove newline character
        if (input[strlen(input)-1] == '\n') {
            input[strlen(input)-1] = '\0';
        }

        if (strcmp(input, "exit") == 0) {
            break;
        }

        // parse command and create thread
        if (parse_command(input)) {
            num_threads++;
            pthread_create(&threads[num_threads], NULL, &execute_command, (void*)input);
        }

        // join all threads
        for (int i = 1; i <= num_threads; i++) {
            pthread_join(threads[i], NULL);
        }
    }

    return 0;
}