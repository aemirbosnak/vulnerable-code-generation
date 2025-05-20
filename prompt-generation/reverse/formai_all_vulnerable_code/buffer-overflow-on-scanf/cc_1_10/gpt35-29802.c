//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    char cmd[100];
    char arg[100];
    char prompt[] = "FUNNY SHELL > ";
    char* cwd;
    int exitCode = 0;

    printf("Welcome to the Funny Shell!\n");

    while(exitCode != 1){
        printf("%s", prompt);
        scanf("%s", cmd);

        if(strcmp(cmd, "exit") == 0){
            printf("Exiting the Funny Shell... Byeeee!\n");
            exitCode = 1;
        }

        else if(strcmp(cmd, "cd") == 0){
            scanf("%s", arg);
            if(chdir(arg) == -1){
                printf("Oops! Directory does not exist. Please Try Again! :(\n");
            }
        }

        else if(strcmp(cmd, "pwd") == 0){
            cwd = getcwd(NULL, 0);
            printf("You are here: %s\n", cwd);
            free(cwd);
        }

        else if(strcmp(cmd, "whoami") == 0){
            printf("You are the Funniest Person in the World! :D\n");
        }

        else if(strcmp(cmd, "date") == 0){
            printf("Today is the most wonderful day ever!\n");
        }

        else if (strcmp(cmd, "ls") == 0) {
            char* argv[] = {"ls", "-la", NULL};
            execvp(argv[0], argv);
        }
        else{
            printf("Hmm. That command does not exist. Please be more funny! :P\n");
        }
    }

    return 0;
}