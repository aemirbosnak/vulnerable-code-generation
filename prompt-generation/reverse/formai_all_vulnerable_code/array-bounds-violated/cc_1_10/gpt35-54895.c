//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LEN 100
#define MAX_HISTORY_SIZE 10

void welcome_message();
void print_prompt();
int process_command(char command[]);
void execute_command(char* args[]);
void add_to_history(char history[][MAX_COMMAND_LEN], char command[]);
void show_history(char history[][MAX_COMMAND_LEN], int history_count);
void handle_signal(int sig);

int main()
{
    char command[MAX_COMMAND_LEN];
    char history[MAX_HISTORY_SIZE][MAX_COMMAND_LEN];
    int history_count = 0;

    welcome_message();

    while(1)
    {
        print_prompt();

        // Read user input
        fgets(command, MAX_COMMAND_LEN, stdin);
        command[strlen(command)-1] = '\0';

        // Process the command
        add_to_history(history, command);
        history_count++;
        int result = process_command(command);

        if(result == 1)
        {
            // User request to exit the shell
            break;
        }
        else if(result == 2)
        {
            // Show history
            show_history(history, history_count);
            continue;
        }

        // Execute the command
        char* args[MAX_COMMAND_LEN];
        char* token = strtok(command, " ");
        int arg_count = 0;

        while(token != NULL)
        {
            args[arg_count] = token;
            token = strtok(NULL, " ");
            arg_count++;
        }

        args[arg_count] = NULL;

        execute_command(args);
    }

    return 0;
}

void welcome_message()
{
    printf("Welcome to MyShell!\n");
}

void print_prompt()
{
    printf("MyShell> ");
}

int process_command(char command[])
{
    if(strcmp(command, "exit") == 0)
    {
        return 1;
    }
    else if(strcmp(command, "history") == 0)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void execute_command(char* args[])
{
    pid_t pid = fork();

    if(pid == -1)
    {
        // Fork error
        printf("Error executing command!\n");
    }
    else if(pid == 0)
    {
        // Child process
        int result = execvp(args[0], args);

        if(result == -1)
        {
            // If the function returns -1, it means that it did not execute successfully, so print an error message
            printf("Invalid command or arguments!\n");
        }

        exit(0);
    }
    else
    {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

void add_to_history(char history[][MAX_COMMAND_LEN], char command[])
{
    // Shift the history array to the right to make space for the new command
    for(int i = MAX_HISTORY_SIZE-1; i > 0; i--)
    {
        strcpy(history[i], history[i-1]);
    }

    // Add the new command to the beginning of the history array
    strcpy(history[0], command);
}

void show_history(char history[][MAX_COMMAND_LEN], int history_count)
{
    printf("Command history:\n");

    for(int i = 0; i < history_count && i < MAX_HISTORY_SIZE; i++)
    {
        printf("%d: %s\n", i+1, history[i]);
    }
}

void handle_signal(int sig)
{
    printf("\n");
    print_prompt();
    fflush(stdout); // flush output buffer
}

void init_signal_handler()
{
    signal(SIGINT, handle_signal);
}