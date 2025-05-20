//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

#define MAX_LENGTH 100

int main()
{
    char input[MAX_LENGTH]; 
    char *args[MAX_LENGTH/2 + 1]; 
    int run = 1; 

    while(run) 
    {
        printf("futuristicShell> ");
        fflush(stdout);

        fgets(input, MAX_LENGTH, stdin);
        input[strlen(input)-1] = '\0'; 

        if(strcmp(input, "exit") == 0) 
        {
            run = 0;
            printf("Farewell, human.\n");
            continue;
        }
        
        pid_t pid = fork();

        if(pid < 0) 
        {
            printf("A fatal error has occurred.\n");
            exit(1);
        }
        else if(pid == 0) 
        {
            int i = 0, j = 0;
            args[0] = strtok(input, " ");
            i++;
            while(args[j] != NULL)
            {
                args[i] = strtok(NULL, " ");
                j++;
                i++;
            }
            args[i] = NULL;

            if(execvp(args[0], args) < 0) 
            {
                printf("Invalid command. Type 'help' for a list of available commands.\n");
                exit(1);
            }
        }
        else 
        {
            wait(NULL); 
        }
    }
    return 0; 
}