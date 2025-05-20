//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */
#define BUFFER_SIZE 50

int main(void)
{
    char *args[MAX_LINE/2 + 1]; /* command line arguments */
    char *history[MAX_LINE/2 + 1]; /* array to store command history */
    char buffer[BUFFER_SIZE]; /* buffer for storing  input */
    int should_run = 1; /* flag to determine when to exit program */
    int args_size = 0, history_size = 0; /* counters for args and history arrays */
    
    while (should_run)
    {
        printf("osh> ");
        fflush(stdout);
        
        /* read input from user */
        fgets(buffer, BUFFER_SIZE, stdin);
        
        /* remove newline character from input */
        if ((strlen(buffer) > 0) && (buffer[strlen(buffer) - 1] == '\n'))
            buffer[strlen(buffer) - 1] = '\0';
        
        /* check for "!!" to execute previous command */
        if (strcmp(buffer, "!!") == 0)
        {
            if (history_size == 0)
                printf("No commands in history.\n");
            else
            {
                printf("%s\n", history[history_size - 1]);
                strcpy(buffer, history[history_size - 1]);
            }
        }
        /* check for "!n" to execute nth command in history */
        else if (buffer[0] == '!')
        {
            int index = atoi(&buffer[1]);
            if (index <= 0 || index > history_size)
                printf("Invalid command index.\n");
            else
            {
                printf("%s\n", history[index - 1]);
                strcpy(buffer, history[index - 1]);
            }
        }
        
        /* tokenise input into arguments */
        args_size = 0;
        char *token = strtok(buffer, " ");
        while (token != NULL)
        {
            args[args_size] = token;
            args_size++;
            token = strtok(NULL, " ");
        }
        args[args_size] = NULL;
        
        /* add command to history */
        if (args_size != 0)
        {
            history[history_size] = (char*) malloc(BUFFER_SIZE*sizeof(char));
            strcpy(history[history_size], buffer);
            history_size++;
        }
        
        /* check for exit command */
        if (strcmp(args[0], "exit") == 0)
            should_run = 0;
        else
        {
            pid_t pid;
            int status;
            
            /* fork a child process */
            pid = fork();
            
            if (pid < 0)
            {
                printf("Fork failed.\n");
                exit(1);
            }
            else if (pid == 0) /* child process */
            {
                if (execvp(args[0], args) == -1)
                    printf("Invalid command.\n");
                exit(0);
            }
            else /* parent process */
            {
                wait(NULL);
            }
        }
    }
    
    /* free memory allocated for history */
    for (int i = 0; i < history_size; i++)
        free(history[i]);

    return 0;
}